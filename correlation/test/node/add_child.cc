/*
** Copyright 2011 Merethis
**
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

#include "com/centreon/broker/correlation/node.hh"

using namespace com::centreon::broker;

/**
 *  Check that link creation works properly.
 *
 *  @return 0 on success.
 */
int main() {
  // Objects.
  correlation::node n1;
  correlation::node n2;

  // Create link.
  n1.add_child(&n2);

  // Check.
  return (n1.children().isEmpty()
          || (*n1.children().begin() != &n2)
          || n2.parents().isEmpty()
          || (*n2.parents().begin() != &n1));
}