#include "logs/helpers.hpp"

#include <time.h>

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace logs
{

std::string gettimestr()
{
    time_t rawtime{0};
    tm* timeinfo{0};

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::string timestr{asctime(timeinfo)};
    timestr.erase(std::remove(timestr.begin(), timestr.end(), '\n'),
                  timestr.end());
    return timestr;
}

inline uint32_t numpower(uint32_t base, uint32_t exp)
{
    if (!exp)
        return 1;
    if (!base)
        return 0;
    uint32_t res{base};
    while (--exp)
        res *= base;
    return res;
}

std::string gettimestampus()
{
    const auto currtimepoint{std::chrono::system_clock::now()};
    const auto currtime{std::chrono::system_clock::to_time_t(currtimepoint)};
    const auto currlocaltime{*std::localtime(&currtime)};
    const auto currtimeepoch{currtimepoint.time_since_epoch()};
    const auto currtimems{
        duration_cast<std::chrono::microseconds>(currtimeepoch).count() %
        1000000};

    std::ostringstream oss;
    oss << std::put_time(&currlocaltime, "%Y%m%d_%H%M%S") << "_" << std::setw(6)
        << std::setfill('0') << currtimems;

    return oss.str();
}

std::vector<std::string> getmultiline(const std::string& msg)
{
    std::vector<std::string> output;
    std::istringstream input{msg};
    for (std::string line; std::getline(input, line);)
    {
        output.push_back(line);
    }
    return output;
}

} // namespace logs
