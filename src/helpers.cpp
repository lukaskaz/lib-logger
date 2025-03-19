#include "logs/helpers.hpp"

#include <time.h>

#include <algorithm>
#include <chrono>
#include <concepts>
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

template <typename T>
concept Numerical = std::is_arithmetic_v<T>;

namespace it
{
// non-recurion, iterative variant
inline auto pow(Numerical auto base, uint32_t exp) -> decltype(base)
{
    if (!exp)
        return 1;
    if (!base)
        return 0;
    decltype(base) res{1};
    while (exp--)
        res *= base;
    return res;
}
} // namespace it

namespace tr
{
// tail recursion variant
template <class T>
    requires requires(T a) { a* a; }
inline auto pow(T base, uint32_t exp, T res = 1) -> T
{
    if (!exp)
        return res;
    if (!base)
        return 0;
    return pow(base, exp - 1, res * base);
}
} // namespace tr

namespace sr
{
// standard recursion variant
inline auto pow(Numerical auto base, uint32_t exp) -> decltype(base)
{
    if (!exp)
        return 1;
    if (!base)
        return 0;
    return base * pow(base, exp - 1);
}
} // namespace sr

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
    oss << std::put_time(&currlocaltime, "%Y%m%d_%H%M%S") << "." << std::setw(6)
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
