#pragma once

#include <memory>
#include <string>

namespace logs
{

enum class level
{
    critical,
    error,
    warning,
    info,
    debug
};

enum class tags
{
    hide,
    show
};

class LogIf
{
  public:
    virtual ~LogIf() = default;

    virtual void log(level, const std::string&, const std::string&) = 0;
    virtual std::string info() const = 0;
};

} // namespace logs
