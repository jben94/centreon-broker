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

#ifndef CCB_NEB_STATISTICS_SERVICES_PASSIVELY_CHECKED_HH
#  define CCB_NEB_STATISTICS_SERVICES_PASSIVELY_CHECKED_HH

#  include <string>
#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/neb/statistics/plugin.hh"

CCB_BEGIN()

namespace                neb {
  namespace              statistics {
    /**
     *  @class services_passively_checked services_passively_checked.hh "com/centreon/broker/neb/statistics/services_passively_checked.hh"
     *  @brief services_passively_checked statistics plugin.
     */
    class                services_passively_checked : public plugin {
    public:
                         services_passively_checked();
                         services_passively_checked(
                           services_passively_checked const& right);
                         ~services_passively_checked();
      services_passively_checked&
                         operator=(services_passively_checked const& right);
      void               run(std::string& output, std::string& perfdata);
    };
  }
}

CCB_END()

#endif // !CCB_NEB_STATISTICS_SERVICES_PASSIVELY_CHECKED_HH
