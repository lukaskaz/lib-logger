#pragma once

#include "log/factory.hpp"

#include <memory>
#include <string>
#include <tuple>

namespace logs::storage
{

using config_t = std::tuple<level, std::string>;

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

} // namespace logs::storage
