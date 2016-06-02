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

#include "core/date_core.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class date_test : public test::test {
public:
    date_test() : test::test("DateTest") {}

protected:
    void operator()() {
        core::date sunday{2457496};
        core::date monday{2457497};

        if (static_cast<unsigned>(sunday) != 2457496) {
            throw ::test::test_failure("Julian day mis-match");
        }
        if (static_cast<unsigned>(monday) != 2457497) {
            throw ::test::test_failure("Julian day mis-match");
        }

        if (sunday.weekday() != core::sunday) {
            throw ::test::test_failure("Weekday mis-match");
        }
        if (monday.weekday() != core::monday) {
            throw ::test::test_failure("Weekday mis-match");
        }

        if (sunday + 1 != monday) {
            throw ::test::test_failure("Add compare mis-match");
        }
        if (sunday != monday - 1) {
            throw ::test::test_failure("Subtract compare mis-match");
        }
    }
};

static test::test_registrar my_registrar{new date_test{}};

