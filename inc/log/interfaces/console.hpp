#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>

namespace logging::console
{

class Log : public LogIf
{
  public:
    ~Log();

    void log(type, const std::string&, const std::string&) override;
    std::string info() const override;

  private:
    friend class logging::LogFactory;
    explicit Log(type);
    struct Handler;
    std::unique_ptr<Handler> handler;
};

} // namespace logging::console
