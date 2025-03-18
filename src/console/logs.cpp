#include "logs/interfaces/console/logs.hpp"

#include "logs/helpers.hpp"

#include <algorithm>
#include <iostream>
#include <mutex>
#include <unordered_map>

namespace logs::console
{

const std::unordered_map<level, std::string> levelNameMap = {
    {level::critical, "CRIT"},
    {level::error, "ERR "},
    {level::warning, "WARN"},
    {level::info, "INFO"},
    {level::debug, "DBG "}};

struct Log::Handler
{
  public:
    Handler(const config_t& config) :
        setlevel{std::get<level>(config)}, settags{std::get<tags>(config)}
    {}

    std::string getinfo() const
    {
        return info;
    }

    void log(level loglevel, const std::string& tag, const std::string& msg)
    {
        if (setlevel >= loglevel)
        {
            std::lock_guard lock(mtx);
            std::string tagtxt = settags == tags::show ? "[" + tag + "]" : "";
            std::ranges::for_each(
                getmultiline(msg),
                [this, loglevel, &tagtxt](const std::string& line) {
                    std::cout << "[" << getlevelname(loglevel) << "]" << tagtxt
                              << " " << line << std::endl;
                });
        }
    }

  private:
    static const std::string info;
    const level setlevel{level::error};
    const tags settags{tags::show};
    std::mutex mtx;

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
