#include "log/interfaces/console.hpp"

#include "log/helpers.hpp"

#include <algorithm>
#include <iostream>
#include <unordered_map>

namespace logging::console
{

const std::unordered_map<type, std::string> typeNameMap = {
    {type::critical, "CRIT"},
    {type::error, "ERR"},
    {type::warning, "WARN"},
    {type::info, "INFO"},
    {type::debug, "DBG"}};

struct Log::Handler
{
  public:
    Handler(type lvl) : level{lvl}
    {}

    std::string getinfo() const
    {
        return info;
    }

    void log(type type, const std::string& module, const std::string& msg)
    {
        if (type <= level)
        {
            std::ranges::for_each(
                getmultiline(msg),
                [this, type, &module](const std::string& line) {
                    std::cout << "[" << gettypename(type) << "][" << module
                              << "] " << line << "\n";
                });
        }
    }

  private:
    const std::string info{"console"};
    type level{type::error};

    std::string gettypename(type type)
    {
        return typeNameMap.contains(type) ? typeNameMap.at(type) : "UNDEF";
    }
};

Log::Log(type lvl) : handler{std::make_unique<Handler>(lvl)}
{}

Log::~Log() = default;

std::string Log::info() const
{
    return handler->getinfo();
}

void Log::log(type type, const std::string& module, const std::string& msg)
{
    handler->log(type, module, msg);
}

} // namespace logging::console
