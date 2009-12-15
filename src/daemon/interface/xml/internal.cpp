/*
**  Copyright 2009 MERETHIS
**  This file is part of CentreonBroker.
**
**  CentreonBroker is free software: you can redistribute it and/or modify it
**  under the terms of the GNU General Public License as published by the Free
**  Software Foundation, either version 2 of the License, or (at your option)
**  any later version.
**
**  CentreonBroker is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
**  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
**  for more details.
**
**  You should have received a copy of the GNU General Public License along
**  with CentreonBroker.  If not, see <http://www.gnu.org/licenses/>.
**
**  For more information : contact@centreon.com
*/

#include "events/events.h"
#include "interface/xml/internal.h"

using namespace Events;
using namespace Interface::XML;

const NameField<Acknowledgement> Interface::XML::acknowledgement_fields[] =
  {
    NameField<Acknowledgement>("acknowledgement_type",
      &Acknowledgement::acknowledgement_type),
    NameField<Acknowledgement>("author_name",
      &Acknowledgement::author),
    NameField<Acknowledgement>("comment_data",
      &Acknowledgement::comment),
    NameField<Acknowledgement>("entry_time",
      &Acknowledgement::entry_time),
    NameField<Acknowledgement>("is_sticky",
      &Acknowledgement::is_sticky),
    NameField<Acknowledgement>("notify_contacts",
      &Acknowledgement::notify_contacts),
    NameField<Acknowledgement>("persistent_comment",
      &Acknowledgement::persistent_comment),
    NameField<Acknowledgement>("state",
      &Acknowledgement::state),
    NameField<Acknowledgement>("type",
      &Acknowledgement::type),
    NameField<Acknowledgement>()
  };

const NameField<Comment> Interface::XML::comment_fields[] =
  {
    NameField<Comment>("author_name",
      &Comment::author),
    NameField<Comment>("comment_data",
      &Comment::comment),
    NameField<Comment>("comment_time",
      &Comment::comment_time),
    NameField<Comment>("comment_type",
      &Comment::comment_type),
    NameField<Comment>("deletion_time",
      &Comment::deletion_time),
    NameField<Comment>("entry_time",
      &Comment::entry_time),
    NameField<Comment>("entry_type",
      &Comment::entry_type),
    NameField<Comment>("expire_time",
      &Comment::expire_time),
    NameField<Comment>("expires",
      &Comment::expires),
    NameField<Comment>("host_name",
      &Comment::host),
    NameField<Comment>("internal_id",
      &Comment::internal_id),
    NameField<Comment>("persistent",
      &Comment::persistent),
    NameField<Comment>("service_description",
      &Comment::service),
    NameField<Comment>("source",
      &Comment::source),
    NameField<Comment>("type",
      &Comment::type),
    NameField<Comment>()
  };

const NameField<Downtime> Interface::XML::downtime_fields[] =
  {
    NameField<Downtime>("author_name",
      &Downtime::author),
    NameField<Downtime>("comment_data",
      &Downtime::comment),
    NameField<Downtime>("downtime_id",
      &Downtime::id),
    NameField<Downtime>("downtime_type",
      &Downtime::downtime_type),
    NameField<Downtime>("duration",
      &Downtime::duration),
    NameField<Downtime>("end_time",
      &Downtime::end_time),
    NameField<Downtime>("entry_time",
      &Downtime::entry_time),
    NameField<Downtime>("fixed",
      &Downtime::fixed),
    NameField<Downtime>("host_name",
      &Downtime::host),
    NameField<Downtime>("service_description",
      &Downtime::service),
    NameField<Downtime>("start_time",
      &Downtime::start_time),
    NameField<Downtime>("triggered_by",
      &Downtime::triggered_by),
    NameField<Downtime>("was_cancelled",
      &Downtime::was_cancelled),
    NameField<Downtime>("was_started",
      &Downtime::was_started),
    NameField<Downtime>("type",
      &Downtime::type),
    NameField<Downtime>()
  };

const NameField<Host> Interface::XML::host_fields[] =
  {
    NameField<Host>("acknowledgement_type",
      &Host::acknowledgement_type),
    NameField<Host>("action_url",
      &Host::action_url),
    NameField<Host>("active_checks_enabled",
      &Host::active_checks_enabled),
    NameField<Host>("address",
      &Host::address),
    NameField<Host>("alias",
      &Host::alias),
    NameField<Host>("check_command",
      &Host::check_command),
    NameField<Host>("check_interval",
      &Host::check_interval),
    NameField<Host>("check_freshness",
      &Host::check_freshness),
    NameField<Host>("check_period",
      &Host::check_period),
    NameField<Host>("check_type",
      &Host::check_type),
    NameField<Host>("current_check_attempt",
      &Host::current_check_attempt),
    NameField<Host>("current_notification_number",
      &Host::current_notification_number),
    NameField<Host>("current_state",
      &Host::current_state),
    NameField<Host>("display_name",
      &Host::display_name),
    NameField<Host>("event_handler",
      &Host::event_handler),
    NameField<Host>("event_handler_enabled",
      &Host::event_handler_enabled),
    NameField<Host>("execution_time",
     &Host::execution_time),
    NameField<Host>("failure_prediction_enabled",
      &Host::failure_prediction_enabled),
    NameField<Host>("first_notification_delay",
      &Host::first_notification_delay),
    NameField<Host>("flap_detection_enabled",
      &Host::flap_detection_enabled),
    NameField<Host>("flap_detection_on_down",
      &Host::flap_detection_on_down),
    NameField<Host>("flap_detection_on_unreachable",
      &Host::flap_detection_on_unreachable),
    NameField<Host>("flap_detection_on_up",
      &Host::flap_detection_on_up),
    NameField<Host>("freshness_threshold",
      &Host::freshness_threshold),
    NameField<Host>("has_been_checked",
      &Host::has_been_checked),
    NameField<Host>("have_2d_coords",
      &Host::have_2d_coords),
    NameField<Host>("high_flap_threshold",
      &Host::high_flap_threshold),
    NameField<Host>("host_id",
      &Host::host_id),
    NameField<Host>("host_name",
      &Host::host),
    NameField<Host>("icon_image",
      &Host::icon_image),
    NameField<Host>("icon_image_alt",
      &Host::icon_image_alt),
    NameField<Host>("is_flapping",
      &Host::is_flapping),
    NameField<Host>("last_check",
      &Host::last_check),
    NameField<Host>("last_hard_state",
      &Host::last_hard_state),
    NameField<Host>("last_hard_state_change",
      &Host::last_hard_state_change),
    NameField<Host>("last_notification",
      &Host::last_notification),
    NameField<Host>("last_state_change",
      &Host::last_state_change),
    NameField<Host>("last_time_down",
      &Host::last_time_down),
    NameField<Host>("last_time_unreachable",
      &Host::last_time_unreachable),
    NameField<Host>("last_time_up",
      &Host::last_time_up),
    NameField<Host>("last_update",
      &Host::last_update),
    NameField<Host>("latency",
      &Host::latency),
    NameField<Host>("long_output",
      &Host::long_output),
    NameField<Host>("low_flap_threshold",
      &Host::low_flap_threshold),
    NameField<Host>("max_check_attempts",
      &Host::max_check_attempts),
    NameField<Host>("modified_attributes",
      &Host::modified_attributes),
    NameField<Host>("next_check",
      &Host::next_check),
    NameField<Host>("next_host_notification",
      &Host::next_notification),
    NameField<Host>("no_more_notifications",
      &Host::no_more_notifications),
    NameField<Host>("notes",
      &Host::notes),
    NameField<Host>("notes_url",
      &Host::notes_url),
    NameField<Host>("notification_interval",
      &Host::notification_interval),
    NameField<Host>("notification_period",
      &Host::notification_period),
    NameField<Host>("notifications_enabled",
      &Host::notifications_enabled),
    NameField<Host>("notify_on_down",
      &Host::notify_on_down),
    NameField<Host>("notify_on_downtime",
      &Host::notify_on_downtime),
    NameField<Host>("notify_on_flapping",
      &Host::notify_on_flapping),
    NameField<Host>("notify_on_recovery",
      &Host::notify_on_recovery),
    NameField<Host>("notify_on_unreachable",
      &Host::notify_on_unreachable),
    NameField<Host>("obsess_over_host",
      &Host::obsess_over),
    NameField<Host>("output",
      &Host::output),
    NameField<Host>("passive_checks_enabled",
      &Host::passive_checks_enabled),
    NameField<Host>("percent_state_change",
      &Host::percent_state_change),
    NameField<Host>("perf_data",
      &Host::perf_data),
    NameField<Host>("problem_has_been_acknowledged",
      &Host::problem_has_been_acknowledged),
    NameField<Host>("process_performance_data",
      &Host::process_performance_data),
    NameField<Host>("retain_nonstatus_information",
      &Host::retain_nonstatus_information),
    NameField<Host>("retain_status_information",
      &Host::retain_status_information),
    NameField<Host>("retry_interval",
      &Host::retry_interval),
    NameField<Host>("scheduled_downtime_depth",
      &Host::scheduled_downtime_depth),
    NameField<Host>("should_be_scheduled",
      &Host::should_be_scheduled),
    NameField<Host>("stalk_on_down",
      &Host::stalk_on_down),
    NameField<Host>("stalk_on_unreachable",
      &Host::stalk_on_unreachable),
    NameField<Host>("stalk_on_up",
      &Host::stalk_on_up),
    NameField<Host>("state_type",
      &Host::state_type),
    NameField<Host>("statusmap_image",
      &Host::statusmap_image),
    NameField<Host>("vrml_image",
      &Host::vrml_image),
    NameField<Host>("x_2d",
      &Host::x_2d),
    NameField<Host>("y_2d",
      &Host::y_2d),
    NameField<Host>()
  };

const NameField<HostGroup> Interface::XML::host_group_fields[] =
  {
    NameField<HostGroup>("action_url",
      &HostGroup::action_url),
    NameField<HostGroup>("alias",
      &HostGroup::alias),
    NameField<HostGroup>("hostgroup_name",
      &HostGroup::name),
    NameField<HostGroup>("members",
      &HostGroup::members),
    NameField<HostGroup>("notes",
      &HostGroup::notes),
    NameField<HostGroup>("notes_url",
      &HostGroup::notes_url),
    NameField<HostGroup>()
  };

const NameField<HostStatus> Interface::XML::host_status_fields[] =
  {
    NameField<HostStatus>("acknowledgement_type",
      &HostStatus::acknowledgement_type),
    NameField<HostStatus>("active_checks_enabled",
      &HostStatus::active_checks_enabled),
    NameField<HostStatus>("check_command",
      &HostStatus::check_command),
    NameField<HostStatus>("check_interval",
      &HostStatus::check_interval),
    NameField<HostStatus>("check_period",
      &HostStatus::check_period),
    NameField<HostStatus>("check_type",
      &HostStatus::check_type),
    NameField<HostStatus>("current_check_attempt",
      &HostStatus::current_check_attempt),
    NameField<HostStatus>("current_notification_number",
      &HostStatus::current_notification_number),
    NameField<HostStatus>("current_state",
      &HostStatus::current_state),
    NameField<HostStatus>("event_handler",
      &HostStatus::event_handler),
    NameField<HostStatus>("event_handler_enabled",
      &HostStatus::event_handler_enabled),
    NameField<HostStatus>("execution_time",
      &HostStatus::execution_time),
    NameField<HostStatus>("failure_prediction_enabled",
      &HostStatus::failure_prediction_enabled),
    NameField<HostStatus>("flap_detection_enabled",
      &HostStatus::flap_detection_enabled),
    NameField<HostStatus>("has_been_checked",
      &HostStatus::has_been_checked),
    NameField<HostStatus>("is_flapping",
      &HostStatus::is_flapping),
    NameField<HostStatus>("last_check",
      &HostStatus::last_check),
    NameField<HostStatus>("last_hard_state",
      &HostStatus::last_hard_state),
    NameField<HostStatus>("last_hard_state_change",
      &HostStatus::last_hard_state_change),
    NameField<HostStatus>("last_notification",
      &HostStatus::last_notification),
    NameField<HostStatus>("last_state_change",
      &HostStatus::last_state_change),
    NameField<HostStatus>("last_time_down",
      &HostStatus::last_time_down),
    NameField<HostStatus>("last_time_unreachable",
      &HostStatus::last_time_unreachable),
    NameField<HostStatus>("last_time_up",
      &HostStatus::last_time_up),
    NameField<HostStatus>("last_update",
      &HostStatus::last_update),
    NameField<HostStatus>("latency",
      &HostStatus::latency),
    NameField<HostStatus>("long_output",
      &HostStatus::long_output),
    NameField<HostStatus>("max_check_attempts",
      &HostStatus::max_check_attempts),
    NameField<HostStatus>("modified_attributes",
      &HostStatus::modified_attributes),
    NameField<HostStatus>("next_check",
      &HostStatus::next_check),
    NameField<HostStatus>("next_host_notification",
      &HostStatus::next_notification),
    NameField<HostStatus>("no_more_notifications",
      &HostStatus::no_more_notifications),
    NameField<HostStatus>("notifications_enabled",
      &HostStatus::notifications_enabled),
    NameField<HostStatus>("obsess_over_host",
      &HostStatus::obsess_over),
    NameField<HostStatus>("output",
      &HostStatus::output),
    NameField<HostStatus>("passive_checks_enabled",
      &HostStatus::passive_checks_enabled),
    NameField<HostStatus>("percent_state_change",
      &HostStatus::percent_state_change),
    NameField<HostStatus>("perf_data",
      &HostStatus::perf_data),
    NameField<HostStatus>("problem_has_been_acknowledged",
      &HostStatus::problem_has_been_acknowledged),
    NameField<HostStatus>("process_performance_data",
      &HostStatus::process_performance_data),
    NameField<HostStatus>("retry_interval",
      &HostStatus::retry_interval),
    NameField<HostStatus>("scheduled_downtime_depth",
      &HostStatus::scheduled_downtime_depth),
    NameField<HostStatus>("should_be_scheduled",
      &HostStatus::should_be_scheduled),
    NameField<HostStatus>("state_type",
      &HostStatus::state_type),
    NameField<HostStatus>()
  };

// XXX : Log is here !
/*
const NameField<Log> Interface::XML::log_fields[] =
  {
    NameField<Log>("ctime",
      &Log::c_time),
    NameField<Log>("host_name",
      &Log::host),
    NameField<Log>("msg_type",
      &Log::msg_type),
    NameField<Log>("notification_cmd",
      &Log::notification_cmd),
    NameField<Log>("notification_contact",
      &Log::notification_contact),
    NameField<Log>("output",
      &Log::output),
    NameField<Log>("retry",
      &Log::retry),
    NameField<Log>("service_description",
      &Log::service),
    NameField<Log>("status",
      &Log::status),
    NameField<Log>("type",
      &Log::type),
    NameField<Log>()
  };
*/

const NameField<ProgramStatus> Interface::XML::program_status_fields[] =
  {
    NameField<ProgramStatus>("active_host_checks_enabled",
      &ProgramStatus::active_host_checks_enabled),
    NameField<ProgramStatus>("active_service_checks_enabled",
      &ProgramStatus::active_service_checks_enabled),
    NameField<ProgramStatus>("daemon_mode",
      &ProgramStatus::daemon_mode),
    NameField<ProgramStatus>("event_handlers_enabled",
      &ProgramStatus::event_handler_enabled),
    NameField<ProgramStatus>("failure_prediction_enabled",
      &ProgramStatus::failure_prediction_enabled),
    NameField<ProgramStatus>("flap_detection_enabled",
      &ProgramStatus::flap_detection_enabled),
    NameField<ProgramStatus>("global_host_event_handler",
      &ProgramStatus::global_host_event_handler),
    NameField<ProgramStatus>("global_service_event_handler",
      &ProgramStatus::global_service_event_handler),
    NameField<ProgramStatus>("instance_name",
      &ProgramStatus::instance),
    NameField<ProgramStatus>("is_running",
      &ProgramStatus::is_running),
    NameField<ProgramStatus>("last_alive",
      &ProgramStatus::last_alive),
    NameField<ProgramStatus>("last_command_check",
      &ProgramStatus::last_command_check),
    NameField<ProgramStatus>("last_log_rotation",
      &ProgramStatus::last_log_rotation),
    NameField<ProgramStatus>("modified_host_attributes",
      &ProgramStatus::modified_host_attributes),
    NameField<ProgramStatus>("modified_service_attributes",
      &ProgramStatus::modified_service_attributes),
    NameField<ProgramStatus>("notifications_enabled",
      &ProgramStatus::notifications_enabled),
    NameField<ProgramStatus>("obsess_over_hosts",
      &ProgramStatus::obsess_over_hosts),
    NameField<ProgramStatus>("obsess_over_services",
      &ProgramStatus::obsess_over_services),
    NameField<ProgramStatus>("passive_host_checks_enabled",
      &ProgramStatus::passive_host_checks_enabled),
    NameField<ProgramStatus>("passive_service_checks_enabled",
      &ProgramStatus::passive_service_checks_enabled),
    NameField<ProgramStatus>("pid",
      &ProgramStatus::pid),
    NameField<ProgramStatus>("process_performance_data",
      &ProgramStatus::process_performance_data),
    NameField<ProgramStatus>("program_end",
      &ProgramStatus::program_end),
    NameField<ProgramStatus>("program_start",
      &ProgramStatus::program_start),
    NameField<ProgramStatus>()
  };

const NameField<Service> Interface::XML::service_fields[] =
  {
    NameField<Service>("acknowledgement_type",
      &Service::acknowledgement_type),
    NameField<Service>("action_url",
      &Service::action_url),
    NameField<Service>("active_checks_enabled",
      &Service::active_checks_enabled),
    NameField<Service>("check_command",
      &Service::check_command),
    NameField<Service>("check_interval",
      &Service::check_interval),
    NameField<Service>("check_freshness",
      &Service::check_freshness),
    NameField<Service>("check_period",
      &Service::check_period),
    NameField<Service>("check_type",
      &Service::check_type),
    NameField<Service>("current_attempt",
      &Service::current_check_attempt),
    NameField<Service>("current_notification_number",
      &Service::current_notification_number),
    NameField<Service>("current_state",
      &Service::current_state),
    NameField<Service>("default_active_checks_enabled",
      &Service::active_checks_enabled),
    NameField<Service>("default_event_handler_enabled",
      &Service::event_handler_enabled),
    NameField<Service>("default_failure_prediction_enabled",
      &Service::failure_prediction_enabled),
    NameField<Service>("default_flap_detection_enabled",
      &Service::flap_detection_enabled),
    NameField<Service>("default_notifications_enabled",
      &Service::notifications_enabled),
    NameField<Service>("default_passive_checks_enabled",
      &Service::passive_checks_enabled),
    NameField<Service>("default_process_performance_data",
      &Service::process_performance_data),
    NameField<Service>("display_name",
      &Service::display_name),
    NameField<Service>("event_handler",
      &Service::event_handler),
    NameField<Service>("event_handler_enabled",
      &Service::event_handler_enabled),
    NameField<Service>("execution_time",
      &Service::execution_time),
    NameField<Service>("failure_prediction_enabled",
      &Service::failure_prediction_enabled),
    NameField<Service>("failure_prediction_options",
      &Service::failure_prediction_options),
    NameField<Service>("first_notification_delay",
      &Service::first_notification_delay),
    NameField<Service>("flap_detection_enabled",
      &Service::flap_detection_enabled),
    NameField<Service>("flap_detection_on_critical",
      &Service::flap_detection_on_critical),
    NameField<Service>("flap_detection_on_ok",
      &Service::flap_detection_on_ok),
    NameField<Service>("flap_detection_on_unknown",
      &Service::flap_detection_on_unknown),
    NameField<Service>("flap_detection_on_warning",
      &Service::flap_detection_on_warning),
    NameField<Service>("freshness_threshold",
      &Service::freshness_threshold),
    NameField<Service>("has_been_checked",
      &Service::has_been_checked),
    NameField<Service>("high_flap_threshold",
      &Service::high_flap_threshold),
    NameField<Service>("host_id",
      &Service::host_id),
    NameField<Service>("host_name",
      &Service::host),
    NameField<Service>("icon_image",
      &Service::icon_image),
    NameField<Service>("icon_image_alt",
      &Service::icon_image_alt),
    NameField<Service>("is_flapping",
      &Service::is_flapping),
    NameField<Service>("is_volatile",
      &Service::is_volatile),
    NameField<Service>("last_check",
      &Service::last_check),
    NameField<Service>("last_hard_state",
      &Service::last_hard_state),
    NameField<Service>("last_hard_state_change",
      &Service::last_hard_state_change),
    NameField<Service>("last_notification",
      &Service::last_notification),
    NameField<Service>("last_state_change",
      &Service::last_state_change),
    NameField<Service>("last_time_critical",
      &Service::last_time_critical),
    NameField<Service>("last_time_ok",
      &Service::last_time_ok),
    NameField<Service>("last_time_unknown",
      &Service::last_time_unknown),
    NameField<Service>("last_time_warning",
      &Service::last_time_warning),
    NameField<Service>("last_update",
      &Service::last_update),
    NameField<Service>("latency",
      &Service::latency),
    NameField<Service>("long_output",
      &Service::long_output),
    NameField<Service>("low_flap_threshold",
      &Service::low_flap_threshold),
    NameField<Service>("max_check_attempts",
      &Service::max_check_attempts),
    NameField<Service>("modified_attributes",
      &Service::modified_attributes),
    NameField<Service>("next_check",
      &Service::next_check),
    NameField<Service>("next_notification",
      &Service::next_notification),
    NameField<Service>("no_more_notifications",
      &Service::no_more_notifications),
    NameField<Service>("notes",
      &Service::notes),
    NameField<Service>("notes_url",
      &Service::notes_url),
    NameField<Service>("notification_interval",
      &Service::notification_interval),
    NameField<Service>("notification_period",
      &Service::notification_period),
    NameField<Service>("notifications_enabled",
      &Service::notifications_enabled),
    NameField<Service>("notified_on_critical",
      &Service::notified_on_critical),
    NameField<Service>("notified_on_unknown",
      &Service::notified_on_unknown),
    NameField<Service>("notified_on_warning",
      &Service::notified_on_warning),
    NameField<Service>("notify_on_downtime",
      &Service::notify_on_downtime),
    NameField<Service>("notify_on_flapping",
      &Service::notify_on_flapping),
    NameField<Service>("notify_on_recovery",
      &Service::notify_on_recovery),
    NameField<Service>("obsess_over_service",
      &Service::obsess_over),
    NameField<Service>("output",
      &Service::output),
    NameField<Service>("passive_checks_enabled",
      &Service::passive_checks_enabled),
    NameField<Service>("percent_state_change",
      &Service::percent_state_change),
    NameField<Service>("perf_data",
      &Service::perf_data),
    NameField<Service>("problem_has_been_acknowledged",
      &Service::problem_has_been_acknowledged),
    NameField<Service>("process_performance_data",
      &Service::process_performance_data),
    NameField<Service>("retain_nonstatus_information",
      &Service::retain_nonstatus_information),
    NameField<Service>("retain_status_information",
      &Service::retain_status_information),
    NameField<Service>("retry_interval",
      &Service::retry_interval),
    NameField<Service>("scheduled_downtime_depth",
      &Service::scheduled_downtime_depth),
    NameField<Service>("service_description",
      &Service::service),
    NameField<Service>("service_id",
      &Service::service_id),
    NameField<Service>("should_be_scheduled",
      &Service::should_be_scheduled),
    NameField<Service>("stalk_on_critical",
      &Service::stalk_on_critical),
    NameField<Service>("stalk_on_ok",
      &Service::stalk_on_ok),
    NameField<Service>("stalk_on_unknown",
      &Service::stalk_on_unknown),
    NameField<Service>("stalk_on_warning",
      &Service::stalk_on_warning),
    NameField<Service>("state_type",
      &Service::state_type),
    NameField<Service>()
  };

const NameField<ServiceStatus> Interface::XML::service_status_fields[] =
  {
    NameField<ServiceStatus>("acknowledgement_type",
      &ServiceStatus::acknowledgement_type),
    NameField<ServiceStatus>("active_checks_enabled",
      &ServiceStatus::active_checks_enabled),
    NameField<ServiceStatus>("check_command",
      &ServiceStatus::check_command),
    NameField<ServiceStatus>("check_interval",
      &ServiceStatus::check_interval),
    NameField<ServiceStatus>("check_period",
      &ServiceStatus::check_period),
    NameField<ServiceStatus>("check_type",
      &ServiceStatus::check_type),
    NameField<ServiceStatus>("current_attempt",
      &ServiceStatus::current_check_attempt),
    NameField<ServiceStatus>("current_notification_number",
      &ServiceStatus::current_notification_number),
    NameField<ServiceStatus>("current_state",
      &ServiceStatus::current_state),
    NameField<ServiceStatus>("event_handler",
      &ServiceStatus::event_handler),
    NameField<ServiceStatus>("event_handler_enabled",
      &ServiceStatus::event_handler_enabled),
    NameField<ServiceStatus>("execution_time",
      &ServiceStatus::execution_time),
    NameField<ServiceStatus>("failure_prediction_enabled",
      &ServiceStatus::failure_prediction_enabled),
    NameField<ServiceStatus>("flap_detection_enabled",
      &ServiceStatus::flap_detection_enabled),
    NameField<ServiceStatus>("has_been_checked",
      &ServiceStatus::has_been_checked),
    NameField<ServiceStatus>("is_flapping",
      &ServiceStatus::is_flapping),
    NameField<ServiceStatus>("last_check",
      &ServiceStatus::last_check),
    NameField<ServiceStatus>("last_hard_state",
      &ServiceStatus::last_hard_state),
    NameField<ServiceStatus>("last_hard_state_change",
      &ServiceStatus::last_hard_state_change),
    NameField<ServiceStatus>("last_notification",
      &ServiceStatus::last_notification),
    NameField<ServiceStatus>("last_state_change",
      &ServiceStatus::last_state_change),
    NameField<ServiceStatus>("last_time_critical",
      &ServiceStatus::last_time_critical),
    NameField<ServiceStatus>("last_time_ok",
      &ServiceStatus::last_time_ok),
    NameField<ServiceStatus>("last_time_unknown",
      &ServiceStatus::last_time_unknown),
    NameField<ServiceStatus>("last_time_warning",
      &ServiceStatus::last_time_warning),
    NameField<ServiceStatus>("last_update",
      &ServiceStatus::last_update),
    NameField<ServiceStatus>("latency",
      &ServiceStatus::latency),
    NameField<ServiceStatus>("long_output",
      &ServiceStatus::long_output),
    NameField<ServiceStatus>("max_check_attempts",
      &ServiceStatus::max_check_attempts),
    NameField<ServiceStatus>("modified_attributes",
      &ServiceStatus::modified_attributes),
    NameField<ServiceStatus>("next_check",
      &ServiceStatus::next_check),
    NameField<ServiceStatus>("next_notification",
      &ServiceStatus::next_notification),
    NameField<ServiceStatus>("no_more_notifications",
      &ServiceStatus::no_more_notifications),
    NameField<ServiceStatus>("notifications_enabled",
      &ServiceStatus::notifications_enabled),
    NameField<ServiceStatus>("obsess_over_service",
      &ServiceStatus::obsess_over),
    NameField<ServiceStatus>("output",
      &ServiceStatus::output),
    NameField<ServiceStatus>("passive_checks_enabled",
      &ServiceStatus::passive_checks_enabled),
    NameField<ServiceStatus>("percent_state_change",
      &ServiceStatus::percent_state_change),
    NameField<ServiceStatus>("perf_data",
      &ServiceStatus::perf_data),
    NameField<ServiceStatus>("problem_has_been_acknowledged",
      &ServiceStatus::problem_has_been_acknowledged),
    NameField<ServiceStatus>("process_performance_data",
      &ServiceStatus::process_performance_data),
    NameField<ServiceStatus>("retry_interval",
      &ServiceStatus::retry_interval),
    NameField<ServiceStatus>("scheduled_downtime_depth",
      &ServiceStatus::scheduled_downtime_depth),
    NameField<ServiceStatus>("should_be_scheduled",
      &ServiceStatus::should_be_scheduled),
    NameField<ServiceStatus>("state_type",
      &ServiceStatus::state_type),
    NameField<ServiceStatus>()
  };
