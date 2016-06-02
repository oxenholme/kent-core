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

#include "core/tz_info.h"
#include "core/wall_time.h"

void core::wall_time::set_tz(time_t now)
{
    core::tz_info::info info = _tz.get_info(now);

    _offset = info.offset;
    _tz_end = info.end;

    set_day(now);
}

void core::wall_time::set_day(time_t now)
{
    _day_end = now + date::secs_per_day - now % date::secs_per_day;
}

