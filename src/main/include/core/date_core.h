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

#ifndef _CORE_DATE_CORE_H_
#define _CORE_DATE_CORE_H_

#include <cstdint>
#include <ctime>

namespace core {

    // A day of the week (irrespective of wether that day is 
    // traditionally a day of work or a day of rest).

    class weekday {
    public:
        explicit constexpr weekday(unsigned);

        explicit constexpr operator unsigned() const;

        friend constexpr bool operator==(weekday, weekday);
        friend constexpr bool operator!=(weekday, weekday);
        friend constexpr bool operator<(weekday, weekday);
        friend constexpr bool operator>(weekday, weekday);
        friend constexpr bool operator<=(weekday, weekday);
        friend constexpr bool operator>=(weekday, weekday);

    private:
        uint_fast8_t _wd;
    };

    // A day in time (the use of Julian Day Numbers as indicies
    // in unsigned 32 bit integers means days earlier than around 
    // 4800BC in the Julian/Gregorian calendar cannot be represented.

    class date {
    public:
        explicit constexpr date(unsigned);

        static constexpr date from_time_t(time_t);

        constexpr core::weekday weekday() const;

        explicit constexpr operator unsigned() const;

        static constexpr uint_least32_t secs_per_day = 24 * 60 * 60;

#if defined __unix__ || defined _WIN32 
        static constexpr uint_least32_t epoch = 2440588;
#endif

        friend constexpr bool operator==(date, date);
        friend constexpr bool operator!=(date, date);
        friend constexpr bool operator<(date, date);
        friend constexpr bool operator>(date, date);
        friend constexpr bool operator<=(date, date);
        friend constexpr bool operator>=(date, date);

        friend constexpr date operator+(date, int);
        friend constexpr date operator-(date, int);

    private:
        uint_least32_t _julian;
    };



    // Weekday implementation

    constexpr weekday::weekday(unsigned wd) : _wd(wd) {
    }

    constexpr weekday::operator unsigned() const {
        return _wd;
    }

    constexpr bool operator==(weekday lhs, weekday rhs) {
        return lhs._wd == rhs._wd;
    }
    constexpr bool operator!=(weekday lhs, weekday rhs) {
        return lhs._wd != rhs._wd;
    }
    constexpr bool operator<(weekday lhs, weekday rhs) {
        return lhs._wd < rhs._wd;
    }
    constexpr bool operator>(weekday lhs, weekday rhs) {
        return lhs._wd > rhs._wd;
    }
    constexpr bool operator<=(weekday lhs, weekday rhs) {
        return lhs._wd <= rhs._wd;
    }
    constexpr bool operator>=(weekday lhs, weekday rhs) {
        return lhs._wd >= rhs._wd;
    }



    // Date implementation

    constexpr date::date(unsigned julian) : _julian(julian) {
    }

    constexpr date date::from_time_t(time_t time) {
        return date{static_cast<uint_least32_t>(time / secs_per_day + epoch)};
    }

    constexpr core::weekday date::weekday() const {
        return core::weekday{_julian % 7};
    }

    constexpr date::operator unsigned() const {
        return _julian;
    }

    constexpr bool operator==(date lhs, date rhs) {
        return lhs._julian == rhs._julian;
    }
    constexpr bool operator!=(date lhs, date rhs) {
        return lhs._julian != rhs._julian;
    }
    constexpr bool operator<(date lhs, date rhs) {
        return lhs._julian < rhs._julian;
    }
    constexpr bool operator>(date lhs, date rhs) {
        return lhs._julian > rhs._julian;
    }
    constexpr bool operator<=(date lhs, date rhs) {
        return lhs._julian <= rhs._julian;
    }
    constexpr bool operator>=(date lhs, date rhs) {
        return lhs._julian >= rhs._julian;
    }

    constexpr date operator+(date lhs, int rhs) {
        return date{lhs._julian + rhs};
    }
    constexpr date operator-(date lhs, int rhs) {
        return date{lhs._julian - rhs};
    }


}

#endif

