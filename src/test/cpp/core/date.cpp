#include "core/date_core.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class date_test : public test::test {
public:
    date_test() : test::test("DateTest") {}

protected:
    void operator()() {
        core::date any_day{2457496};

        if (static_cast<unsigned>(any_day) != 2457496) {
            throw ::test::test_failure("Julian day mis-match");
        }

        if (any_day.weekday() != core::sunday) {
            throw ::test::test_failure("Weekday mis-match");
        }
    }
};

static test::test_registrar my_registrar{new date_test{}};

