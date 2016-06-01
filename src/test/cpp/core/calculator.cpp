#include "core/calculator.h"
#include "test/test.h"
#include "test/testFailure.h"
#include "test/testRegistrar.h"

class my_data {
public:
    my_data(int i = 0) : _i(i) {}

    int get() const {return _i;}
    void set(int i) {_i = i;}

private:
    int _i;
};

class inc_calc {
public:
    bool calc(my_data& data, bool mutated) {
        data.set(data.get() + 1);
    }
};

class dec_calc {
public:
    bool calc(my_data& data, bool mutated) {
        data.set(data.get() - 1);
    }
};

class shift_calc {
public:
    bool calc(my_data& data, bool mutated) {
        data.set(data.get() << 1);
    }
};

using my_calc = core::calculator<dec_calc, shift_calc, inc_calc, my_data&>;

class calculator_test : public test::test {
public:
    calculator_test() : test::test("CalculatorTest") {}

protected:
    void operator()() {
        my_data data{1};
        my_calc calc{dec_calc{}, shift_calc{}, inc_calc{}, data};
        if (calc.calc()) {
            throw ::test::test_failure("Mutated returned true");
        }
        if (data.get() != 3) {
            throw ::test::test_failure("Result mis-match");
        }
    }
};

static test::test_registrar my_registrar{new calculator_test{}};

