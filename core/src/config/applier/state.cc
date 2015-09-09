/*
** Copyright 2011-2012 Centreon
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

#include <cstdlib>
#include <memory>
#include <QCoreApplication>
#include <QMutex>
#include <QMutexLocker>
#include "com/centreon/broker/config/applier/endpoint.hh"
#include "com/centreon/broker/config/applier/logger.hh"
#include "com/centreon/broker/config/applier/modules.hh"
#include "com/centreon/broker/config/applier/state.hh"
#include "com/centreon/broker/config/applier/temporary.hh"
#include "com/centreon/broker/logging/file.hh"
#include "com/centreon/broker/logging/logging.hh"
#include "com/centreon/broker/multiplexing/engine.hh"
#include "com/centreon/broker/multiplexing/subscriber.hh"

using namespace com::centreon::broker::config::applier;

// Class instance.
static state* gl_state = NULL;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Destructor.
 */
state::~state() {}

/**
 *  Apply a configuration state.
 *
 *  @param[in] s       State to apply.
 *  @param[in] run_mux Set to true if multiplexing must be run.
 */
void state::apply(
              com::centreon::broker::config::state const& s,
              bool run_mux) {
  // Save poller id.
  _instance_id = s.instance_id();

  // Apply logging configuration.
  logger::instance().apply(s.loggers());

  // Flush logs or not.
  com::centreon::broker::logging::file::with_flush(
    s.flush_logs());

  // Enable or not thread ID logging.
  com::centreon::broker::logging::file::with_thread_id(
    s.log_thread_id());

  // Enable or not timestamp logging.
  com::centreon::broker::logging::file::with_timestamp(
    s.log_timestamp());

  // Apply modules configuration.
  modules::instance().apply(
                        s.module_list(),
                        s.module_directory(),
                        &s);
  static bool first_application(true);
  if (first_application)
    first_application = false;
  else {
    unsigned int module_count(0);
    for (modules::iterator
           it(modules::instance().begin()),
           end(modules::instance().end());
         it != end;
         ++it)
      ++module_count;
    if (module_count)
      logging::config(logging::high) << "applier: " << module_count
        << " modules loaded";
    else
      logging::config(logging::high) << "applier: no module loaded, "
        "you might want to check the 'module_directory' directive";
  }

  com::centreon::broker::multiplexing::subscriber::event_queue_max_size(s.event_queue_max_size());

  com::centreon::broker::config::state st = s;

  // Create command file.
  if (!s.command_file().isEmpty()) {
    config::endpoint ept;
    ept.name = "(external commands)";
    ept.type = "extcmd";
    ept.params.insert("extcmd", s.command_file());
    st.inputs().push_back(ept);
  }

  // Apply temporary configuration.
  temporary::instance().apply(st.temporary());

  // Apply input and output configuration.
  endpoint::instance().apply(st.inputs(), st.outputs());

  // Enable multiplexing loop.
  if (run_mux)
    com::centreon::broker::multiplexing::engine::instance().start();

  return ;
}

/**
 *  Get the instance ID.
 *
 *  @return Instance ID of this Broker instance.
 */
unsigned int state::get_instance_id() const throw () {
  return (_instance_id);
}

/**
 *  Get the instance of this object.
 *
 *  @return Class instance.
 */
state& state::instance() {
  return (*gl_state);
}

/**
 *  Load singleton.
 */
void state::load() {
  if (!gl_state)
    gl_state = new state;
  return ;
}

/**
 *  Unload singleton.
 */
void state::unload() {
  delete gl_state;
  gl_state = NULL;
  return ;
}

/**************************************
*                                     *
*           Private Methods           *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
state::state() {}
