#include "log/interfaces/group.hpp"

#include <algorithm>

namespace logging::group
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

    void log(type type, const std::string& module, const std::string& msg)
    {
        std::ranges::for_each(loggers, [type, &module, &msg](auto logger) {
            logger->log(type, module, msg);
        });
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

void Log::log(type type, const std::string& module, const std::string& msg)
{
    handler->log(type, module, msg);
}

} // namespace logging::group
