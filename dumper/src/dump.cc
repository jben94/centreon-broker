/*
** Copyright 2013 Centreon
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
#include "com/centreon/broker/dumper/dump.hh"
#include "com/centreon/broker/dumper/internal.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::dumper;

/**
 *  Default constructor.
 */
dump::dump() : instance_id(0) {}

/**
 *  Copy constructor.
 *
 *  @param[in] right Object to copy.
 */
dump::dump(dump const& right) : io::data(right) {
  _internal_copy(right);
}

/**
 *  Destructor.
 */
dump::~dump() {}

/**
 *  Assignment operator.
 *
 *  @param[in] right Object to copy.
 *
 *  @return This object.
 */
dump& dump::operator=(dump const& right) {
  if (this != &right) {
    io::data::operator=(right);
    _internal_copy(right);
  }
  return (*this);
}

/**
 *  Get event type.
 *
 *  @return Event type.
 */
unsigned int dump::type() const {
  return (io::events::data_type<io::events::dumper, dumper::de_dump>::value);
}

/**
 *  Copy internal data members.
 *
 *  @param[in] right Object to copy.
 */
void dump::_internal_copy(dump const& right) {
  content = right.content;
  instance_id = right.instance_id;
  tag = right.tag;
  return ;
}
