#include <iostream>

#include "core/tzfile.h"

void core::tzfile::check_magic(std::istream& in)
{
    uint32_t magic;
    in.read(reinterpret_cast<char*>(&magic), sizeof(magic));
    magic = ntohl(magic);
    if (magic != magic_number) {
        throw std::domain_error("Bad magic number in timezone file");
    }
}

unsigned core::tzfile::check_version(std::istream& in, unsigned min)
{
    unsigned ver;
    uint8_t ver_buff[16];
    in.read(reinterpret_cast<char*>(&ver_buff), sizeof(ver_buff));
    switch (ver_buff[0]) {
    case version_1:
        ver = 1;
        break;

    case version_2:
        ver = 2;
        break;

    case version_3:
        ver = 3;
        break;

    default:
        throw std::domain_error("Bad version number in timezone file");
    }

    if (ver < min) {
        throw std::domain_error("Version number in timezine file too low");
    }

    return ver;
}

std::unique_ptr<int32_t[]> core::tzfile::read_times(std::istream& in, unsigned count)
{
    auto times = std::make_unique<int32_t[]>(count);
    in.read(reinterpret_cast<char*>(times.get()), sizeof(int32_t) * count);
    for (unsigned i = 0; i < count; ++i) {
        times[i] = ntohl(times[i]);
        //time_t time = times[i];
        //std::cout << "times[" << i << "] is " << std::asctime(gmtime(&time));
    }
    return times;
}

std::unique_ptr<uint8_t[]> core::tzfile::read_bytes(std::istream& in, unsigned count)
{
    auto bytes = std::make_unique<uint8_t[]>(count);
    in.read(reinterpret_cast<char*>(bytes.get()), sizeof(uint8_t) * count);
    //for (unsigned i = 0; i < count; ++i) {
    //    std::cout << "bytes[" << i << "] is " << static_cast<int>(bytes[i]) << std::endl;
    //}
    return bytes;
}

auto core::tzfile::read_types(std::istream& in, unsigned count) -> std::unique_ptr<tztype[]>
{
    auto types = std::make_unique<tztype[]>(count);
    for (unsigned i = 0; i < count; ++i) {
        in.read(reinterpret_cast<char*>(&types[i]), 6); // TODO 6 not sizeof(tztype) due to alignment
        types[i].gmtoff = ntohl(types[i].gmtoff);
        //std::cout << "infos[" << i << "] offset is " << types[i].gmtoff << std::endl;
        //std::cout << "infos[" << i << "] DST is " << static_cast<int>(types[i].isdst) << std::endl;
        //std::cout << "infos[" << i << "] index is " << static_cast<int>(types[i].abbrind) << std::endl;
    }
    return types;
}

core::tzfile::tzfile(std::istream& in)
{
    check_magic(in);

    unsigned version = check_version(in, 0);

    uint32_t counts[count_count];
    in.read(reinterpret_cast<char*>(&counts), sizeof(counts));
    for (unsigned i = 0; i < count_count; ++i) {
        counts[i] = ntohl(counts[i]);
    }

    //std::cout << counts[is_gmt_count] << " is_gmts" << std::endl;
    //std::cout << counts[is_std_count] << " is_stds" << std::endl;
    //std::cout << counts[leap_count] << " leaps" << std::endl;
    //std::cout << counts[time_count] << " times" << std::endl;
    //std::cout << counts[type_count] << " types" << std::endl;
    //std::cout << counts[char_count] << " chars" << std::endl;

    auto times = read_times(in, counts[time_count]);
    auto codes = read_bytes(in, counts[time_count]);
    auto types = read_types(in, counts[type_count]);

    auto chars = std::make_unique<char[]>(counts[char_count]);
    in.read(reinterpret_cast<char*>(chars.get()), sizeof(char) * counts[char_count]);
    //for (unsigned i = 0; i < counts[char_count]; ++i) {
    //    std::cout << "chars[" << i << "] is " << chars[i] << std::endl;
    //}

    auto leaps = std::make_unique<int32_t[]>(counts[leap_count << 1]);
    in.read(reinterpret_cast<char*>(times.get()), sizeof(int32_t) * counts[leap_count] << 1);
    for (unsigned i = 0; i < counts[leap_count] << 1; i += 2) {
        leaps[i] = ntohl(leaps[i]);
        leaps[i + 1] = ntohl(leaps[i + 1]);
        //time_t time = leaps[i];
        //std::cout << "leaps[" << i << "] is " << std::ctime(&time) << std::endl;
    }

    auto is_stds = read_bytes(in, counts[is_std_count]);
    auto is_gmts = read_bytes(in, counts[is_gmt_count]);

    if (!in.good()) {
        throw std::domain_error("Data error in timezone file");
    }

    if (version == 2) {
        check_magic(in);
        check_version(in, version);
        // TODO read 64bit tables, POSIX rule string
    }

    // Find first non-daylight type entry
    // or use first if none
    unsigned pre = 0;
    for (unsigned i = 0; i < counts[type_count]; ++i) {
        if (types[i].isdst == 0) {
            pre = i;
            break;
        }
    }

    time_t now = time(NULL);

    index = 0; // guess for now
    infos.reserve(counts[time_count] + 1);   
    if (counts[time_count] > 0) {
        infos.push_back(info{
                std::numeric_limits<time_t>::min(), 
                times[0], 
                types[pre].gmtoff, 
                types[pre].isdst != 0, 
                std::string{chars[types[pre].abbrind]}});
        for (unsigned i = 0; i < counts[time_count]; ++i) {
            time_t start = times[i];
            time_t end = (i == counts[time_count] - 1) ? std::numeric_limits<time_t>::max() : times[i + 1];
            tztype& type = types[codes[i]];
            infos.push_back(info{
                    start, 
                    end, 
                    type.gmtoff, 
                    type.isdst != 0, 
                    std::string{chars[type.abbrind]}});
            if (start <= now && now < end) {
                index = i;
                //std::cout << "Setting index to " << i << std::endl;
                //std::cout << "Start is " << ctime(&start) << std::endl;
                //std::cout << "End is " << ctime(&end) << std::endl;
            }
        }
    }
    else {
        infos.push_back(info{
                std::numeric_limits<time_t>::min(), 
                std::numeric_limits<time_t>::max(), 
                types[pre].gmtoff, 
                types[pre].isdst != 0, 
                std::string{chars[types[pre].abbrind]}});
    }
}

core::tzfile::info core::tzfile::get_info(time_t gmt) const
{
    int i = index;
    if (infos[i].start > gmt) {
        while (infos[--i].start > gmt);
    }
    else if (infos[i].end >= gmt) {
        while (infos[++i].start > gmt);
    }
    return infos[i];
}

std::time_t core::tzfile::get_offset(time_t gmt) const
{
    return get_info(gmt).offset;
}


