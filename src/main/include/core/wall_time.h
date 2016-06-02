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

#ifndef _CORE_WALL_TIME_H_
#define _CORE_WALL_TIME_H_

#include <ctime>

#include "core/date_core.h"

namespace core {

    class tz_info;

    class wall_time {
    public:
        wall_time(const tz_info& tz);

        date get_date() const;

    private:
        void set_tz(time_t now);
        void set_day(time_t now);

        const tz_info& _tz;
        time_t _day_end;
        time_t _tz_end;
        time_t _offset;
    };

    inline wall_time::wall_time(const core::tz_info& tz) : _tz(tz) {
        set_tz(time(NULL));
    }

    inline date wall_time::get_date() const {
        time_t now = time(NULL);
        if (now > _tz_end) {
            const_cast<wall_time*>(this)->set_tz(now);
        }
        else if (now > _day_end) {
            const_cast<wall_time*>(this)->set_day(now);
        }
        return date::from_time_t(now + _offset);
    }

}

#endif

