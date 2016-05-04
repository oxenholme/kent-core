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

