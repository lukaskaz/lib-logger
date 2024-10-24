#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>

namespace logging::storage
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
    explicit Log(logtype);
    struct Handler;
    std::unique_ptr<Handler> handler;
};

} // namespace logging::storage
