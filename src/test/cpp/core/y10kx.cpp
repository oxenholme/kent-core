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

class y10kx_test : public test::test {
public:
    y10kx_test() : test::test("Y10KXTest") {}

protected:
    void operator()() {
        // 0000-03-01 Gregorian, origin day for this library
        unsigned j = 1721120;
        unsigned y = 0;
        unsigned m = 3;
        unsigned d = 1;

        do {
            core::date j_date{j};
            core::greg_date g_date{j_date}; 

            if (g_date.year() != core::greg_year{y}) {
                throw ::test::test_failure("Year mis-match");
            }
            if (g_date.month() != core::greg_month{m}) {
                throw ::test::test_failure("Month mis-match");
            }
            if (g_date.day() != core::greg_day{d}) {
                throw ::test::test_failure("Day mis-match");
            }

            if (g_date.to_date() != j_date) {
                throw ::test::test_failure("Julian mis-match");
            }

            ++j;
            ++d;
            if (d > daysInMonth(y, m)) {
                d = 1;
                ++m;
                if (m == 13) {
                    m = 1;
                    ++y;
                }
            }
        }
        while (y < 0x1000);
    }

private:
    unsigned daysInMonth(unsigned year, unsigned month) {
        switch (month) {
        case 2:
            return 28 + (year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0);
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
        }
    }

};

static test::test_registrar my_registrar{new y10kx_test{}};

