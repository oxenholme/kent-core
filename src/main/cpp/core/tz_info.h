#ifndef _CORE_TZ_INFO_H_
#define _CORE_TZ_INFO_H_

#include <cstdint>
#include <ctime>
#include <limits>
#include <memory>
#include <vector>

#ifdef WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

namespace core {

    class tz_info {
    public:
        struct info {
            time_t start;
            time_t end;
            time_t offset;
            bool daylight;
            std::string code;
        };

        tz_info(std::istream& in);

        info get_info(time_t gmt) const;
        time_t get_offset(time_t gmt) const;

    private:
        struct tztype {
            int32_t gmtoff;
            int8_t isdst;
            uint8_t abbrind;
        };

        void check_magic(std::istream& in);
        unsigned check_version(std::istream& in, unsigned min);
        std::unique_ptr<int32_t[]> read_times(std::istream& in, unsigned count);
        std::unique_ptr<uint8_t[]> read_bytes(std::istream& in, unsigned count);
        std::unique_ptr<tztype[]> read_types(std::istream& in, unsigned count);

        uint32_t index;
        std::vector<info> infos;

        static const uint32_t magic_number = ('T' << 24) + ('Z' << 16) + ('i' << 8) + 'f';

        static const uint8_t version_1 = 0;
        static const uint8_t version_2 = '2';
        static const uint8_t version_3 = '3';

        static const uint32_t count_count = 6;
        static const uint32_t is_gmt_count = 0;
        static const uint32_t is_std_count = 1;
        static const uint32_t leap_count = 2;
        static const uint32_t time_count = 3;
        static const uint32_t type_count = 4;
        static const uint32_t char_count = 5;
    };

}

#endif

