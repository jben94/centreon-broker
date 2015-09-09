/*
** Copyright 2009-2013 Centreon
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

#include "com/centreon/broker/io/events.hh"
#include "com/centreon/broker/neb/log_entry.hh"
#include "com/centreon/broker/neb/internal.hh"

using namespace com::centreon::broker::neb;

/**************************************
*                                     *
*          Public Methods             *
*                                     *
**************************************/

/**
 *  @brief Default constructor.
 *
 *  Initialize members to 0, NULL or equivalent.
 */
log_entry::log_entry()
  : c_time(0),
    host_id(0),
        issue_start_time(0),
    log_type(0),
    msg_type(0),
    retry(0),
    service_id(0),
    status(5) {}

/**
 *  @brief Copy constructor.
 *
 *  Copy all internal data of the given object to the current instance.
 *
 *  @param[in] le Object to copy.
 */
log_entry::log_entry(log_entry const& le) : io::data(le) {
  _internal_copy(le);
}

/**
 *  Destructor.
 */
log_entry::~log_entry() {}

/**
 *  @brief Assignment operator.
 *
 *  Copy all internal data of the given object to the current instance.
 *
 *  @param[in] le Object to copy.
 *
 *  @return This object.
 */
log_entry& log_entry::operator=(log_entry const& le) {
  io::data::operator=(le);
  _internal_copy(le);
  return (*this);
}

/**
 *  Returns the type of the event.
 *
 *  @return The event_type.
 */
unsigned int log_entry::type() const {
  return (io::events::data_type<io::events::neb, neb::de_log_entry>::value);
}

/**************************************
*                                     *
*          Private Methods            *
*                                     *
**************************************/

/**
 *  @brief Copy all internal data of the given object to the current
 *         instance.
 *
 *  Make a copy of all data defined within the log_entry class. This
 *  method is used by the copy constructor and the assignment operator.
 *
 *  @param[in] le Object to copy.
 */
void log_entry::_internal_copy(log_entry const& le) {
  c_time = le.c_time;
  host_id = le.host_id;
  host_name = le.host_name;
    instance_name = le.instance_name;
  issue_start_time = le.issue_start_time;
  log_type = le.log_type;
  msg_type = le.msg_type;
  notification_cmd = le.notification_cmd;
  notification_contact = le.notification_contact;
  output = le.output;
  retry = le.retry;
  service_description = le.service_description;
  service_id = le.service_id;
  status = le.status;
  return ;
}
