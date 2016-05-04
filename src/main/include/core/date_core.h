#ifndef _CORE_DATE_CORE_H_
#define _CORE_DATE_CORE_H_

#include <cstdint>

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

        constexpr core::weekday weekday() const;

        explicit constexpr operator unsigned() const;

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



    // Weekday literals (gcc requires these to follow the
    // above constructor definition)

    constexpr weekday monday{0};
    constexpr weekday tuesday{1};
    constexpr weekday wednesday{2};
    constexpr weekday thursday{3};
    constexpr weekday friday{4};
    constexpr weekday saturday{5};
    constexpr weekday sunday{6};



    // Date implementation

    constexpr date::date(unsigned julian) : _julian(julian) {
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

