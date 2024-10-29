#pragma once

#include <string>
#include <vector>

namespace logging
{

std::string gettimestr();
std::vector<std::string> getmultiline(const std::string&);

} // namespace logging
