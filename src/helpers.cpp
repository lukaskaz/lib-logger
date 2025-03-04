#include "log/helpers.hpp"

#include <time.h>

#include <algorithm>
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
