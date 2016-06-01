#include <fstream>

#include "core/greg_date_core.h"
#include "core/tz_info.h"
#include "core/wall_time.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class wall_time_test : public test::test {
public:
    wall_time_test() : test::test("WallTimeTest") {}

protected:
    void operator()() {
        std::ifstream in{"src/test/data/London"};
        core::tz_info tz{in};
        core::wall_time wt{tz};
        core::date today = wt.get_date();

        std::time_t now = std::time(NULL);
        struct tm* tm = localtime(&now);
        core::greg_date greg{core::greg_year{tm->tm_year + 1900u}, core::greg_month{tm->tm_mon + 1u}, core::greg_day{tm->tm_mday + 0u}};

        if (today != greg.to_date()) {
            throw ::test::test_failure("Today mis-match");
        }
    }
};

static test::test_registrar my_registrar{new wall_time_test{}};

