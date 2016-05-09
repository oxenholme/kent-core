#include <fstream>

#include "core/tzfile.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class tzfile_test : public test::test {
public:
    tzfile_test() : test::test("TZFileTest") {}

protected:
    void operator()() {
        std::ifstream in{"src/test/data/London"};
        core::tzfile tz{in};
        core::tzfile::info info = tz.get_info(0);
        if (info.start > 0) {
            throw ::test::test_failure("Start time is positive");
        }
        if (info.end <= 0) {
            throw ::test::test_failure("End time is not positive");
        }
    }
};

static test::test_registrar my_registrar{new tzfile_test{}};

