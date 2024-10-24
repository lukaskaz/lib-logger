#pragma once

#include "log/interfaces/logging.hpp"

#include <memory>
#include <vector>

namespace logging
{

class LogFactory
{
  public:
    template <typename T>
    static std::shared_ptr<LogIf> create(logtype lvl)
    {
        return std::shared_ptr<T>(new T(lvl));
    }

    template <typename T>
    static std::shared_ptr<LogIf>
        create(std::vector<std::shared_ptr<LogIf>>&& loggers)
    {
        return std::shared_ptr<T>(new T(std::move(loggers)));
    }
};

} // namespace logging
