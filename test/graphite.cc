/*
** Copyright 2014 Centreon
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** For more information : contact@centreon.com
*/

#include <ctime>
#include <iostream>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QTcpSocket>
#include <QTcpServer>
#include <sstream>
#include "com/centreon/broker/exceptions/msg.hh"
#include "config.hh"
#include "cbd.hh"
#include "vars.hh"
#include "generate.hh"
#include "misc.hh"
#include "vars.hh"
#include "engine.hh"
#include "external_command.hh"

using namespace com::centreon::broker;

#define STORAGE_DB_NAME "broker_graphite_centreon_storage"
#define COMMAND_FILE "broker_graphite_command_file"

#define GRAPHITE_DB_PORT "6422"
#define GRAPHITE_DB_PORT_S 6422
#define GRAPHITE_DB_PASSWORD "graphite_password"
#define GRAPHITE_DB_HOST "localhost"
#define GRAPHITE_DB_USER "graphite_user"

static const char* expected_result =
    "Authorization: Basic $auth$\n"
    "centreon.statuses.1 0 $timestamp$\n"
    "centreon.metrics.1 0.8 $timestamp$\n";

/**
 *  Check that the graphite works.
 *
 *  @return EXIT_SUCCESS on success.
 */
int main() {
  // Error flag.
  bool error(true);

  // Variables that need cleaning.
  std::list<host> hosts;
  std::list<service> services;
  test_db db;
  external_command commander;
  engine monitoring;
  std::string engine_config_path(tmpnam(NULL));

  try {
    // Open the socket
    QTcpServer server;
    if (!server.listen(QHostAddress::Any, GRAPHITE_DB_PORT_S))
      throw exceptions::msg() << "couldn't listen to " << GRAPHITE_DB_PORT_S;

    // Prepare database.
    db.open(STORAGE_DB_NAME);

    // Create the config graphite xml file.
    test_file file;
    file.set_template(
      PROJECT_SOURCE_DIR "/test/cfg/graphite.xml.in");
    file.set("MYSQL_DB_NAME", STORAGE_DB_NAME);
    file.set("GRAPHITE_DB_PORT", GRAPHITE_DB_PORT);
    file.set("GRAPHITE_DB_PASSWORD", GRAPHITE_DB_PASSWORD);
    file.set("GRAPHITE_DB_HOST", GRAPHITE_DB_HOST);
    file.set("GRAPHITE_DB_USER", GRAPHITE_DB_USER);
    std::string config_file = file.generate();

    // Prepare monitoring engine configuration parameters.
    generate_hosts(hosts, 1);
    generate_services(services, hosts, 1);
    services.back().checks_enabled = 0;
    services.back().accept_passive_service_checks = 1;
    services.back().max_attempts = 1;
    commander.set_file(tmpnam(NULL));
    std::string additional_config;
    {
      std::ostringstream oss;
      oss << commander.get_engine_config()
          << "broker_module=" << CBMOD_PATH << " "
          << config_file << "\n";
      additional_config = oss.str();
    }
    config_write(
      engine_config_path.c_str(),
      additional_config.c_str(),
      &hosts,
      &services);

    std::string engine_config_file(engine_config_path);
    engine_config_file.append("/nagios.cfg");
    monitoring.set_config_file(engine_config_file);
    monitoring.start();

    sleep_for(3 * MONITORING_ENGINE_INTERVAL_LENGTH);
    time_t first_timestamp_possible = std::time(NULL);
    commander.execute(
      "PROCESS_SERVICE_CHECK_RESULT;1;1;0;Submitted by unit test | graphite_test=0.80");

    if (!server.waitForNewConnection(8000 * MONITORING_ENGINE_INTERVAL_LENGTH))
      throw exceptions::msg()
            << "no incoming connection to " << GRAPHITE_DB_PORT_S;
    QTcpSocket* s = server.nextPendingConnection();
    if (!s)
      throw exceptions::msg()
            << "no incoming connection to " << GRAPHITE_DB_PORT_S;
    QByteArray array;
    while (s->isOpen() && s->waitForReadyRead())
      array.append(s->readAll());
    QString data(array);

    time_t last_timestamp_possible = std::time(NULL);
    bool got = false;
    QString auth_base64 = QByteArray(GRAPHITE_DB_USER ":" GRAPHITE_DB_PASSWORD).toBase64();
    // Check the data got for everything is okay.
    for (;
         first_timestamp_possible <= last_timestamp_possible;
         ++first_timestamp_possible) {
      QString expected = expected_result;
      expected.replace("$timestamp$", QString::number(first_timestamp_possible));
      expected.replace("$auth$", auth_base64);
      if (expected == data) {
        got = true;
        break;
      }
    }
    if (!got)
      throw exceptions::msg()
            << "incorrect graphite data: got: "
            << data
            << "\nexpected: "
            << expected_result;

    // Success.
    error = false;
  }
  catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
  }
  catch (...) {
    std::cerr << "unknown exception" << std::endl;
  }

  // Cleanup.
  monitoring.stop();
  free_hosts(hosts);
  free_services(services);
  config_remove(engine_config_path.c_str());

  return (error ? EXIT_FAILURE : EXIT_SUCCESS);
}
