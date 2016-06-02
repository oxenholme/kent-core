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

#include "core/greg_date_core.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class greg_date_test : public test::test {
public:
    greg_date_test() : test::test("GregDateTest") {}

protected:
    void operator()() {
        core::date d20000101{2451545};
        core::greg_date g20000101{core::greg_year{2000}, core::greg_month{1}, core::greg_day{1}};

        // Extractors
        if (g20000101.year() != core::greg_year{2000}) {
            throw ::test::test_failure("Year mis-match");
        }
        if (g20000101.month() != core::greg_month{1}) {
            throw ::test::test_failure("Month mis-match");
        }
        if (g20000101.day() != core::greg_day{1}) {
            throw ::test::test_failure("Day mis-match");
        }

        // Gregorian to Julian conversions
        if (g20000101.to_date() != d20000101) {
            throw ::test::test_failure("Julian date mis-match");
        }
        if (core::greg_date{d20000101} != g20000101) {
            throw ::test::test_failure("Gregorian date mis-match");
        }
    }
};

static test::test_registrar my_registrar{new greg_date_test{}};

