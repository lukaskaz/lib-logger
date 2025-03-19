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
        setlevel{std::get<level>(config)}, settime{std::get<time>(config)},
        settags{std::get<tags>(config)}
    {}

    std::string getinfo() const
    {
        return info;
    }

    void log(level loglevel, const std::string& tag, const std::string& msgs)
    {
        if (setlevel >= loglevel)
            output(getmessages(loglevel, tag, msgs));
    }

  private:
    static const std::string info;
    const level setlevel;
    const time settime;
    const tags settags;
    std::mutex mtx;

    void output(const std::vector<std::string>& messages)
    {
        std::lock_guard lock(mtx);
        std::ranges::for_each(messages, [](const std::string& message) {
            std::cout << message << std::endl;
        });
    }

    std::vector<std::string> getmessages(level loglvl,
                                         const std::string& logtag,
                                         const std::string& logmsgs) const
    {
        std::vector<std::string> msgsvect;
        const auto tim =
            settime == time::show ? "[" + gettimestampus() + "]" : "";
        const auto lvl = "[" + getlevelname(loglvl) + "]";
        const auto tag = settags == tags::show ? "[" + logtag + "]" : "";
        static const auto separator = std::string(" ");

        std::ranges::for_each(
            getmultiline(logmsgs), [&](const std::string& msg) {
                msgsvect.emplace_back(tim + lvl + tag + separator + msg);
            });

        return msgsvect;
    }

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
