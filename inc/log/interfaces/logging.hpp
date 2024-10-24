#pragma once

#include <memory>
#include <string>

namespace logging
{

enum class logtype
{
    critical,
    error,
    warning,
    info,
    debug
};

class LogIf
{
  public:
    virtual ~LogIf() = default;

    virtual void log(logtype, const std::string&) = 0;
    virtual void setlevel(logtype) = 0;
    virtual std::string info() const = 0;
};

} // namespace logging
