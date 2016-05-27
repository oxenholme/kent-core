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

