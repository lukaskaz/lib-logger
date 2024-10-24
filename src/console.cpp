#include "log/interfaces/console.hpp"

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
    Handler(type lvl)
    {
        setlevel(lvl);
    }

    std::string getinfo() const
    {
        return info;
    }

    void setlevel(type newlevel)
    {
        level = newlevel;
    }

    void log(type type, const std::string& msg)
    {
        if (type <= level)
            std::cout << "[" << gettypename(type) << "] " << msg << "\n";
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

void Log::setlevel(type level)
{
    return handler->setlevel(level);
}

void Log::log(type type, const std::string& msg)
{
    handler->log(type, msg);
}

} // namespace logging::console
