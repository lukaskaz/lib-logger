#include "logs/interfaces/console/logs.hpp"

#include "logs/helpers.hpp"

#include <algorithm>
#include <iostream>
#include <unordered_map>

namespace logs::console
{

const std::unordered_map<level, std::string> levelNameMap = {
    {level::critical, "CRIT"},
    {level::error, "ERR"},
    {level::warning, "WARN"},
    {level::info, "INFO"},
    {level::debug, "DBG"}};

struct Log::Handler
{
  public:
    Handler(const config_t& config) : setlevel{config}
    {}

    std::string getinfo() const
    {
        return info;
    }

    void log(level loglevel, const std::string& tag, const std::string& msg)
    {
        if (loglevel <= setlevel)
        {
            std::ranges::for_each(
                getmultiline(msg),
                [this, loglevel, &tag](const std::string& line) {
                    std::cout << "[" << getlevelname(loglevel) << "][" << tag
                              << "] " << line << std::endl;
                });
        }
    }

  private:
    static const std::string info;
    level setlevel{level::error};

    std::string getlevelname(level lvl) const
    {
        return levelNameMap.contains(lvl) ? levelNameMap.at(lvl) : "UNDEF";
    }
};
const std::string Log::Handler::info{"console"};

Log::Log(const config_t& config) : handler{std::make_unique<Handler>(config)}
{}

Log::~Log() = default;

std::string Log::info() const
{
    return handler->getinfo();
}

void Log::log(level loglevel, const std::string& tag, const std::string& msg)
{
    handler->log(loglevel, tag, msg);
}

} // namespace logs::console
