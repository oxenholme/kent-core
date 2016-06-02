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

