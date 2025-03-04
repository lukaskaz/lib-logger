#include "logs/interfaces/group/logs.hpp"

#include <algorithm>

namespace logs::group
{

struct Log::Handler
{
  public:
    Handler(const config_t& config) : loggers{config}
    {}

    std::string getinfo() const
    {
        std::string infos;
        std::ranges::for_each(
            loggers, [&infos](auto logger) { infos += logger->info() + " "; });
        return infos;
    }

    void log(level loglevel, const std::string& tag, const std::string& msg)
    {
        std::ranges::for_each(loggers, [loglevel, &tag, &msg](auto logger) {
            logger->log(loglevel, tag, msg);
        });
    }

  private:
    const std::vector<std::shared_ptr<LogIf>> loggers;
};

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

} // namespace logs::group
