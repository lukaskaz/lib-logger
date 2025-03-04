#pragma once

#include "log/interfaces/log.hpp"

#include <memory>

namespace logs
{

class Factory
{
  public:
    template <typename T, typename C>
    static std::shared_ptr<LogIf> create(const C& config)
    {
        return std::shared_ptr<T>(new T(config));
    }
};

} // namespace logs
