/*
** Copyright 2011 Centreon
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

#include "com/centreon/broker/correlation/issue.hh"
#include "com/centreon/broker/correlation/node.hh"

using namespace com::centreon::broker;

/**
 *  Check that node can be properly assigned.
 *
 *  @return 0 on success.
 */
int main() {
  // Base object.
  correlation::node bn;
  bn.host_id = 42;
  bn.in_downtime = true;
  bn.my_issue.reset(new correlation::issue);
  bn.my_issue->end_time = 234;
  bn.my_issue->start_time = 7678353;
  bn.service_id = 765334;
  bn.since = 3945239074u;
  bn.state = 2;

  // Linked objects.
  correlation::node n1;
  correlation::node n2;
  correlation::node n3;
  correlation::node n4;
  bn.add_child(&n1);
  bn.add_depended(&n2);
  bn.add_dependency(&n3);
  bn.add_parent(&n4);

  // Copy.
  correlation::node cn;
  cn = bn;

  // Reset base object.
  bn.host_id = 23;
  bn.in_downtime = false;
  bn.my_issue.reset();
  bn.service_id = 2347;
  bn.since = 553445;
  bn.state = 1;
  bn.remove_child(&n1);
  bn.remove_dependency(&n3);

  // Check copy construction.
  return ((bn.host_id != 23)
          || bn.in_downtime
          || bn.my_issue.get()
          || (bn.service_id != 2347)
          || (bn.since != 553445)
          || (bn.state != 1)
          || !bn.children().isEmpty()
          || (bn.depended_by().size() != 1)
          || !bn.depends_on().isEmpty()
          || (bn.parents().size() != 1)
          || (cn.host_id != 42)
          || !cn.in_downtime
          || !cn.my_issue.get()
          || (cn.my_issue->end_time != 234)
          || (cn.my_issue->start_time != 7678353)
          || (cn.service_id != 765334)
          || (cn.since != static_cast<time_t>(3945239074u))
          || (cn.state != 2)
          || (cn.children().size() != 1)
          || (*cn.children().begin() != &n1)
          || (cn.depended_by().size() != 1)
          || (*cn.depended_by().begin() != &n2)
          || (cn.depends_on().size() != 1)
          || (*cn.depends_on().begin() != &n3)
          || (cn.parents().size() != 1)
          || (*cn.parents().begin() != &n4)
          || (n1.parents().size () != 1)
          || (n2.depends_on().size() != 2)
          || (n3.depended_by().size() != 1)
          || (n4.children().size() != 2));
}
