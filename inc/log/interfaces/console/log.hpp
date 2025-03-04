#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>

namespace logs::console
{

using config_t = level;

class Log : public LogIf
{
  public:
    ~Log();

    void log(level, const std::string&, const std::string&) override;
    std::string info() const override;

  private:
    friend class logs::Factory;
    explicit Log(const config_t&);
    struct Handler;
    std::unique_ptr<Handler> handler;
};

} // namespace logs::console
