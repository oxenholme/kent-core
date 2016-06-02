/*
 * Copyright 2016 Helm Solutions Ltd
 *
 * This file is part of the Kentside Core Utilities Library
 *
 * The Kentside Core Utilities Library is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * The Kentside Core Utilities Library is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Kentside Core Utilities Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <fstream>

#include "core/tz_info.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class tz_info_test : public test::test {
public:
    tz_info_test() : test::test("TZFileTest") {}

protected:
    void operator()() {
        std::ifstream in{"src/test/data/London"};
        core::tz_info tz{in};
        core::tz_info::info info = tz.get_info(0);
        if (info.start > 0) {
            throw ::test::test_failure("Start time is positive");
        }
        if (info.end <= 0) {
            throw ::test::test_failure("End time is not positive");
        }
        if (info.offset != 3600 && info.offset != 0) {
            throw ::test::test_failure("Offset is not one/two hour(s)");
        }
    }
};

static test::test_registrar my_registrar{new tz_info_test{}};

