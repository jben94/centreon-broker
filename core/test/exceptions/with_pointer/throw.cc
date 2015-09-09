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

#include <cstdlib>
#include <cstring>
#include "com/centreon/broker/exceptions/msg.hh"
#include "com/centreon/broker/exceptions/with_pointer.hh"
#include "com/centreon/broker/io/raw.hh"

using namespace com::centreon::broker;

/**
 *  Check that exception is properly thrown.
 *
 *  @return EXIT_SUCCESS on success.
 */
int main() {
  // Error flag.
  bool error(false);

  // First throw.
  try {
    try {
      exceptions::msg base;
      base << "foobar" << 42 << -789654ll;
      misc::shared_ptr<io::data> dat(new io::raw);
      throw (exceptions::with_pointer(base, dat));
      error = true;
    }
    catch (exceptions::with_pointer const& e) { // Properly caught.
      error = (error || strcmp(e.what(), "foobar42-789654"));
    }
  }
  catch (...) {
    error = true;
  }

  // Second throw.
  try {
    try {
      exceptions::msg base;
      base << "bazqux" << -74125896321445ll << 36;
      misc::shared_ptr<io::data> dat(new io::raw);
      throw (exceptions::with_pointer(base, dat));
      error = true;
    }
    catch (std::exception const& e) {
      error = (error || strcmp(e.what(), "bazqux-7412589632144536"));
    }
  }
  catch (...) {
    error = true;
  }

  // Return test result.
  return (error ? EXIT_FAILURE : EXIT_SUCCESS);
}
