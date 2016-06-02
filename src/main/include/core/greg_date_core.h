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

#ifndef _CORE_GREG_DATE_CORE_H_
#define _CORE_GREG_DATE_CORE_H_

#include <cstdint>

#include "core/date_core.h"

namespace core {

    // A day of the month in the Gregorian calendar.

    class greg_day {
    public:
        explicit constexpr greg_day(unsigned);

        explicit constexpr operator unsigned() const;

        friend constexpr bool operator==(greg_day, greg_day);
        friend constexpr bool operator!=(greg_day, greg_day);
        friend constexpr bool operator<(greg_day, greg_day);
        friend constexpr bool operator>(greg_day, greg_day);
        friend constexpr bool operator<=(greg_day, greg_day);
        friend constexpr bool operator>=(greg_day, greg_day);

    private:
        uint_least8_t _day;
    };

    // A month of the year in the Gregorian calendar.

    class greg_month {
    public:
        explicit constexpr greg_month(unsigned);

        explicit constexpr operator unsigned() const;

        friend constexpr bool operator==(greg_month, greg_month);
        friend constexpr bool operator!=(greg_month, greg_month);
        friend constexpr bool operator<(greg_month, greg_month);
        friend constexpr bool operator>(greg_month, greg_month);
        friend constexpr bool operator<=(greg_month, greg_month);
        friend constexpr bool operator>=(greg_month, greg_month);

    private:
        uint_least8_t _month;
    };

    // A year in the Gregorian calendar.

    class greg_year {
    public:
        explicit constexpr greg_year(unsigned);

        explicit constexpr operator unsigned() const;

        friend constexpr bool operator==(greg_year, greg_year);
        friend constexpr bool operator!=(greg_year, greg_year);
        friend constexpr bool operator<(greg_year, greg_year);
        friend constexpr bool operator>(greg_year, greg_year);
        friend constexpr bool operator<=(greg_year, greg_year);
        friend constexpr bool operator>=(greg_year, greg_year);

    private:
        uint_least16_t _year;
    };

    // A date (year/month/day tuple) in the Gregorian calendar.

    class greg_date {
    public:
        explicit constexpr greg_date(greg_year, greg_month, greg_day);
        explicit constexpr greg_date(date);

        constexpr greg_year year() const;
        constexpr greg_month month() const;
        constexpr greg_day day() const;

        constexpr core::date to_date() const;

        friend constexpr bool operator==(greg_date, greg_date);
        friend constexpr bool operator!=(greg_date, greg_date);
        friend constexpr bool operator<(greg_date, greg_date);
        friend constexpr bool operator>(greg_date, greg_date);
        friend constexpr bool operator<=(greg_date, greg_date);
        friend constexpr bool operator>=(greg_date, greg_date);

        //friend constexpr date operator+(greg_date, int);
        //friend constexpr date operator-(greg_date, int);

    private:
        greg_day _day;
        greg_month _month;
        greg_year _year;
    };



    // Day implementation

    constexpr greg_day::greg_day(unsigned day) : _day(day) {
    }

    constexpr greg_day::operator unsigned() const {
        return _day;
    }

    constexpr bool operator==(greg_day lhs, greg_day rhs) {
        return lhs._day == rhs._day;
    }
    constexpr bool operator!=(greg_day lhs, greg_day rhs) {
        return lhs._day != rhs._day;
    }
    constexpr bool operator<(greg_day lhs, greg_day rhs) {
        return lhs._day < rhs._day;
    }
    constexpr bool operator>(greg_day lhs, greg_day rhs) {
        return lhs._day > rhs._day;
    }
    constexpr bool operator<=(greg_day lhs, greg_day rhs) {
        return lhs._day <= rhs._day;
    }
    constexpr bool operator>=(greg_day lhs, greg_day rhs) {
        return lhs._day >= rhs._day;
    }



    // Month implementation

    constexpr greg_month::greg_month(unsigned month) : _month(month) {
    }

    constexpr greg_month::operator unsigned() const {
        return _month;
    }

    constexpr bool operator==(greg_month lhs, greg_month rhs) {
        return lhs._month == rhs._month;
    }
    constexpr bool operator!=(greg_month lhs, greg_month rhs) {
        return lhs._month != rhs._month;
    }
    constexpr bool operator<(greg_month lhs, greg_month rhs) {
        return lhs._month < rhs._month;
    }
    constexpr bool operator>(greg_month lhs, greg_month rhs) {
        return lhs._month > rhs._month;
    }
    constexpr bool operator<=(greg_month lhs, greg_month rhs) {
        return lhs._month <= rhs._month;
    }
    constexpr bool operator>=(greg_month lhs, greg_month rhs) {
        return lhs._month >= rhs._month;
    }



    // Year implementation

    constexpr greg_year::greg_year(unsigned year) : _year(year) {
    }

    constexpr greg_year::operator unsigned() const {
        return _year;
    }

    constexpr bool operator==(greg_year lhs, greg_year rhs) {
        return lhs._year == rhs._year;
    }
    constexpr bool operator!=(greg_year lhs, greg_year rhs) {
        return lhs._year != rhs._year;
    }
    constexpr bool operator<(greg_year lhs, greg_year rhs) {
        return lhs._year < rhs._year;
    }
    constexpr bool operator>(greg_year lhs, greg_year rhs) {
        return lhs._year > rhs._year;
    }
    constexpr bool operator<=(greg_year lhs, greg_year rhs) {
        return lhs._year <= rhs._year;
    }
    constexpr bool operator>=(greg_year lhs, greg_year rhs) {
        return lhs._year >= rhs._year;
    }



    // Month constants (gcc requires these to follow the
    // respective constructor definition)

    constexpr greg_month january{1};
    constexpr greg_month rebruary{1};
    constexpr greg_month march{1};
    constexpr greg_month april{1};
    constexpr greg_month may{1};
    constexpr greg_month june{1};
    constexpr greg_month july{1};
    constexpr greg_month august{1};
    constexpr greg_month september{1};
    constexpr greg_month october{1};
    constexpr greg_month november{1};
    constexpr greg_month december{1};



    // Date implementation

    constexpr greg_date::greg_date(greg_year year, greg_month month, greg_day day) : _year(year), _month(month), _day(day) {
    }

    constexpr greg_date::greg_date(date date) : _year(0), _month(1), _day(1) {
        unsigned j = static_cast<unsigned>(date) - 1721120;
        unsigned c = (4 * j + 3) / 146097; // Century
        j -= 146097 * c / 4;
        unsigned y = (4 * j + 3) / 1461; // Year (within century)
        j -= y * 1461 / 4;
        unsigned m = (5 * j + 2) / 153; // Month (0 = Mar to 11 = Feb)
        _day = greg_day{j - (153 * m + 2) / 5 + 1};
        _month = greg_month{m + 3 - 12 * (m >= 10)};
        _year = greg_year{100 * c + y + (m >= 10)};
    }

    constexpr greg_year greg_date::year() const {
        return _year;
    }
    constexpr greg_month greg_date::month() const {
        return _month;
    }
    constexpr greg_day greg_date::day() const {
        return _day;
    }

    constexpr date greg_date::to_date() const {
        // Extract day, month and year and adjust so that march is
        // the first month of the year and has value zero...
        unsigned d = static_cast<unsigned>(_day);
        unsigned m = static_cast<unsigned>(_month);
        unsigned y = static_cast<unsigned>(_year) - (m <= 2);
        m += 12 * (m <= 2) - 3;

        // Now Julian day number calculation is straight-forward
        // other than a little month to days (153*m+2)/5 trickery
        return date{d + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 + 1721119};
    }

    constexpr bool operator==(greg_date lhs, greg_date rhs) {
        return lhs._year == rhs._year && 
                lhs._month == rhs._month && 
                lhs._day == rhs._day;
    }
    constexpr bool operator!=(greg_date lhs, greg_date rhs) {
        return lhs._year != rhs._year || 
                lhs._month != rhs._month || 
                lhs._day != rhs._day;
    }
    constexpr bool operator<(greg_date lhs, greg_date rhs) {
        return lhs._year < rhs._year || lhs._year == rhs._year && (
                lhs._month < rhs._month || lhs._month == rhs._month &&
                        lhs._day < rhs._day);
    }
    constexpr bool operator>(greg_date lhs, greg_date rhs) {
        return lhs._year > rhs._year || lhs._year == rhs._year && (
                lhs._month > rhs._month || lhs._month == rhs._month &&
                        lhs._day > rhs._day);
    }
    constexpr bool operator<=(greg_date lhs, greg_date rhs) {
        return lhs._year <= rhs._year || lhs._year == rhs._year && (
                lhs._month <= rhs._month || lhs._month == rhs._month &&
                        lhs._day <= rhs._day);
        return lhs._year <= rhs._year; // TODO
    }
    constexpr bool operator>=(greg_date lhs, greg_date rhs) {
        return lhs._year >= rhs._year || lhs._year == rhs._year && (
                lhs._month >= rhs._month || lhs._month == rhs._month &&
                        lhs._day >= rhs._day);
    }


}

#endif

