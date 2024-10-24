#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>
#include <vector>

namespace logging::collection
{

class Log : public LogIf
{
  public:
    ~Log();

    void log(logtype, const std::string&) override;
    void setlevel(logtype);
    std::string info() const override;

  private:
    friend class logging::LogFactory;
    Log(std::vector<std::shared_ptr<LogIf>>&&);
    struct Handler;
    std::unique_ptr<Handler> handler;
};

} // namespace logging::collection
