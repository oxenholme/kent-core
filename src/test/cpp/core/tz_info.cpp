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

