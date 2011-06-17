/*
** Copyright 2009-2011 Merethis
** This file is part of Centreon Broker.
**
** Centreon Broker is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Broker is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Broker. If not, see
** <http://www.gnu.org/licenses/>.
*/

#ifndef CCB_NEB_HOST_SERVICE_STATUS_HH_
# define CCB_NEB_HOST_SERVICE_STATUS_HH_

# include <QString>
# include <time.h>
# include "com/centreon/broker/neb/status.hh"

namespace                      com {
  namespace                    centreon {
    namespace                  broker {
      namespace                neb {
        /**
         *  @class host_service_status host_service_status.hh "com/centreon/broker/neb/host_service_status.hh"
         *  @brief host_status and service_status shared data.
         *
         *  This class represents what is shared between a host status
         *  event and a service status event.
         *
         *  @see host_status
         *  @see service_status
         */
        class                  host_service_status : public status {
         private:
          void                 _internal_copy(host_service_status const& hss);

         public:
          short                acknowledgement_type;
          bool                 active_checks_enabled;
          QString              check_command;
          double               check_interval;
          QString              check_period;
          short                check_type;
          short                current_check_attempt;
          short                current_notification_number;
          short                current_state;
          bool                 enabled;
          QString              event_handler;
          double               execution_time;
          bool                 has_been_checked;
          unsigned int         host_id;
          bool                 is_flapping;
          time_t               last_check;
          short                last_hard_state;
          time_t               last_hard_state_change;
          time_t               last_notification;
          time_t               last_state_change;
          time_t               last_update;
          double               latency;
          short                max_check_attempts;
          unsigned int         modified_attributes;
          time_t               next_check;
          time_t               next_notification;
          bool                 no_more_notifications;
          bool                 obsess_over;
          QString              output;
          bool                 passive_checks_enabled;
          double               percent_state_change;
          QString              perf_data;
          bool                 problem_has_been_acknowledged;
          double               retry_interval;
          short                scheduled_downtime_depth;
          bool                 should_be_scheduled;
          short                state_type;
                               host_service_status();
                               host_service_status(host_service_status const& hss);
          virtual              ~host_service_status();
          host_service_status& operator=(host_service_status const& hss);
        };
      }
    }
  }
}

#endif /* !CCB_NEB_HOST_SERVICE_STATUS_HH_ */