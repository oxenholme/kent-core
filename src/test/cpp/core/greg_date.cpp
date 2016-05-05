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

