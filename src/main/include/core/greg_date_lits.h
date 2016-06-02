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

#ifndef _CORE_DATE_LITS_H_
#define _CORE_DATE_LITS_H_

#include "core/date_core.h"

namespace core {

    inline namespace lits {

        // (Gregorian) year literals

        greg_year operator"" _gy(unsigned long long int gy) {
            return greg_year{static_cast<unsigned>(gy)};
        }


        // (Gregorian) month constants

        constexpr greg_month january{1};
        constexpr greg_month february{2};
        constexpr greg_month march{3};
        constexpr greg_month april{4};
        constexpr greg_month may{5};
        constexpr greg_month june{6};
        constexpr greg_month july{7};
        constexpr greg_month august{8};
        constexpr greg_month september{9};
        constexpr greg_month october{10};
        constexpr greg_month november{11};
        constexpr greg_month december{12};

        // (Gregorian) month literals

        greg_month operator"" _gm(unsigned long long int gm) {
            return greg_month{static_cast<unsigned>(gm)};
        }

        // (Gregorian) day literals

        greg_day operator"" _gd(unsigned long long int gd) {
            return greg_day{static_cast<unsigned>(gd)};
        }

    }
}

#endif

