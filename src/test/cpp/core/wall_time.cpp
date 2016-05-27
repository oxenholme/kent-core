#include <fstream>

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

        if (static_cast<unsigned>(today) != 2457536) {
            throw ::test::test_failure("Today mis-match");
        }
    }
};

static test::test_registrar my_registrar{new wall_time_test{}};

