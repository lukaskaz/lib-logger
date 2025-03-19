#pragma once

#include <string>
#include <vector>

namespace logs
{

std::string gettimestr();
std::string gettimestampus();
std::vector<std::string> getmultiline(const std::string&);

} // namespace logs
