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

#ifndef CCB_BAM_DIMENSION_BA_BV_RELATION_EVENT_HH
#  define CCB_BAM_DIMENSION_BA_BV_RELATION_EVENT_HH

#  include "com/centreon/broker/io/data.hh"
#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/timestamp.hh"

CCB_BEGIN()

namespace                bam {
  /**
   *  @class dimension_ba_bv_relation_event dimension_ba_bv_relation_event.hh "com/centreon/broker/bam/dimension_ba_bv_relation_event.hh"
   *  @brief Dimension Ba Bv relation event
   *
   */
  class                  dimension_ba_bv_relation_event : public io::data {
  public:
                         dimension_ba_bv_relation_event();
                         dimension_ba_bv_relation_event(
                           dimension_ba_bv_relation_event const& other);
                         ~dimension_ba_bv_relation_event();
    dimension_ba_bv_relation_event&
                         operator=(
                           dimension_ba_bv_relation_event const& other);
    bool                 operator==(
                           dimension_ba_bv_relation_event const& other) const;
    unsigned int         type() const;

    unsigned int         ba_id;
    unsigned int         bv_id;

  private:
    void                 _internal_copy(
                           dimension_ba_bv_relation_event const& other);
  };
}

CCB_END()

#endif // !CCB_BAM_DIMENSION_BA_BV_RELATION_EVENT_HH
