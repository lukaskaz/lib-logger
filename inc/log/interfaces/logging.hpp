#pragma once

#include <memory>
#include <string>

namespace logging
{

enum class type
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

    virtual void log(type, const std::string&, const std::string&) = 0;
    virtual std::string info() const = 0;
};

} // namespace logging
