#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>
#include <vector>

namespace logging::group
{

class Log : public LogIf
{
  public:
    ~Log();

    void log(type, const std::string&) override;
    std::string info() const override;

  private:
    friend class logging::LogFactory;
    explicit Log(std::vector<std::shared_ptr<LogIf>>&&);
    struct Handler;
    std::unique_ptr<Handler> handler;
};

} // namespace logging::group
