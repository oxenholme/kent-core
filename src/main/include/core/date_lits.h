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

        // (Julian) date literals

        date operator"" _jd(unsigned long long int jd) {
            return date{static_cast<unsigned>(jd)};
        }

        // Weekday constants

        constexpr weekday monday{0};
        constexpr weekday tuesday{1};
        constexpr weekday wednesday{2};
        constexpr weekday thursday{3};
        constexpr weekday friday{4};
        constexpr weekday saturday{5};
        constexpr weekday sunday{6};

        // Weekday literals

        weekday operator"" _wd(unsigned long long int wd) {
            return weekday{static_cast<unsigned>(wd)};
        }

    }
}

#endif

