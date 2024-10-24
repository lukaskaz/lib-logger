#include "log/interfaces/console.hpp"

#include <iostream>
#include <unordered_map>

namespace logging::console
{

const std::unordered_map<logtype, std::string> typeNameMap = {
    {logtype::critical, "CRIT"},
    {logtype::error, "ERR"},
    {logtype::warning, "WARN"},
    {logtype::info, "INFO"},
    {logtype::debug, "DBG"}};

struct Log::Handler
{
  public:
    Handler(logtype lvl)
    {
        setlevel(lvl);
    }

    std::string getinfo() const
    {
        return info;
    }

    void setlevel(logtype newlevel)
    {
        level = newlevel;
    }

    void log(logtype type, const std::string& msg)
    {
        if (type <= level)
            std::cout << "[" << gettypename(type) << "] " << msg << "\n";
    }

  private:
    const std::string info{"console"};
    logtype level{logtype::error};

    std::string gettypename(logtype type)
    {
        return typeNameMap.contains(type) ? typeNameMap.at(type) : "UNDEF";
    }
};

Log::Log(logtype lvl) : handler{std::make_unique<Handler>(lvl)}
{}

Log::~Log() = default;

std::string Log::info() const
{
    return handler->getinfo();
}

void Log::setlevel(logtype level)
{
    return handler->setlevel(level);
}

void Log::log(logtype type, const std::string& msg)
{
    handler->log(type, msg);
}

} // namespace logging::console
