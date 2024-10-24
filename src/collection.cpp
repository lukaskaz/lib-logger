#include "log/interfaces/collection.hpp"

#include <algorithm>

namespace logging::collection
{

struct Log::Handler
{
  public:
    Handler(std::vector<std::shared_ptr<LogIf>>&& loggers) :
        loggers{std::move(loggers)}
    {}

    std::string getinfo() const
    {
        std::string infos;
        std::ranges::for_each(
            loggers, [&infos](auto logger) { infos += logger->info() + " "; });
        return infos;
    }

    void setlevel(logtype newlevel)
    {
        std::ranges::for_each(
            loggers, [newlevel](auto logger) { logger->setlevel(newlevel); });
    }

    void log(logtype type, const std::string& msg)
    {
        std::ranges::for_each(
            loggers, [type, &msg](auto logger) { logger->log(type, msg); });
    }

  private:
    const std::vector<std::shared_ptr<LogIf>> loggers;
};

Log::Log(std::vector<std::shared_ptr<LogIf>>&& loggers) :
    handler{std::make_unique<Handler>(std::move(loggers))}
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

} // namespace logging::collection
