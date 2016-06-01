#ifndef _CORE_CALCULATOR_H_
#define _CORE_CALCULATOR_H_

namespace core {

    template <typename... Ts>
    class calculator;


    template <typename Data>
    class calculator<Data> {
    public:
        calculator(const Data& data) : _data(data) {}
        calculator(const calculator&) = delete;
        calculator(calculator&&) = delete;

        bool calc() {
            return false;
        }

    protected:
        Data _data;
    };


    template <typename Calc, typename... Ts>
    class calculator<Calc, Ts...> : protected calculator<Ts...> {
    public:
        calculator(const Calc& calc, const Ts&... ts) : calculator<Ts...>(ts...), _calc(calc) {}
        calculator(const calculator&) = delete;
        calculator(calculator&&) = delete;

        bool calc() {
            bool ret = calculator<Ts...>::calc();
            return _calc.calc(calculator<Ts...>::_data, ret);
        }

    protected:
        Calc _calc;
    };

}

#endif

