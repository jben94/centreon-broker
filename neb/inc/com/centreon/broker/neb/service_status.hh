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

#ifndef CCB_NEB_SERVICE_STATUS_HH
#  define CCB_NEB_SERVICE_STATUS_HH

#  include <QString>
#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/neb/host_service_status.hh"
#  include "com/centreon/broker/timestamp.hh"

CCB_BEGIN()

namespace           neb {
  /**
   *  @class service_status service_status.hh "com/centreon/broker/neb/service_status.hh"
   *  @brief When the status of a service change, such an event is generated.
   *
   *  This class represents a change in a service status.
   */
  class             service_status : public host_service_status {
  public:
                    service_status();
                    service_status(service_status const& ss);
    virtual         ~service_status();
    service_status& operator=(service_status const& ss);
    unsigned int    type() const;

    QString         host_name;
    timestamp       last_time_critical;
    timestamp       last_time_ok;
    timestamp       last_time_unknown;
    timestamp       last_time_warning;
    QString         service_description;
    unsigned int    service_id;

  private:
    void            _internal_copy(service_status const& ss);
  };
}

CCB_END()

#endif // !CCB_NEB_SERVICE_STATUS_HH
