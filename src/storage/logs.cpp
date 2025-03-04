#include "logs/interfaces/storage/logs.hpp"

#include "logs/helpers.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <unordered_map>

namespace logs::storage
{

static const std::filesystem::path defaultpath{"logs/traces.log"};

const std::unordered_map<level, std::string> levelNameMap = {
    {level::critical, "CRIT"},
    {level::error, "ERR"},
    {level::warning, "WARN"},
    {level::info, "INFO"},
    {level::debug, "DBG"}};

struct Log::Handler
{
  public:
    Handler(const config_t& config) :
        fs{std::get<1>(config), defaultpath}, setlevel{std::get<0>(config)}
    {}

    class Filesystem
    {
      public:
        Filesystem(const std::filesystem::path& usepath,
                   const std::filesystem::path& defpath)
        {
            path = !usepath.empty() ? usepath : defpath;
            if (!path.has_parent_path())
                throw std::runtime_error(
                    "Cannot use storage path for logging " + path.native());

            std::filesystem::create_directories(path.parent_path());
            storage.open(path, std::ios::out | std::ios::trunc);
            if (!storage.is_open())
                throw std::runtime_error(
                    "Cannot open storage file for logging: " + path.native());

            storage << "Logging started at " << gettimestr() << std::endl;
        }
        ~Filesystem() = default;

      public:
        std::ofstream storage;

      private:
        std::filesystem::path path;
    } fs;

    std::string getinfo() const
    {
        return info;
    }

    void log(level loglevel, const std::string& tag, const std::string& msg)
    {
        if (loglevel <= setlevel)
        {
            std::ranges::for_each(
                getmultiline(msg),
                [this, loglevel, &tag](const std::string& line) {
                    fs.storage << "[" << getlevelname(loglevel) << "][" << tag
                               << "] " << line << std::endl;
                });
        }
    }

  private:
    static const std::string info;
    level setlevel{level::error};

    std::string getlevelname(level lvl) const
    {
        return levelNameMap.contains(lvl) ? levelNameMap.at(lvl) : "UNDEF";
    }
};
const std::string Log::Handler::info{"storage"};

Log::Log(const config_t& config) : handler{std::make_unique<Handler>(config)}
{}

Log::~Log() = default;

std::string Log::info() const
{
    return handler->getinfo();
}

void Log::log(level loglevel, const std::string& tag, const std::string& msg)
{
    handler->log(loglevel, tag, msg);
}

} // namespace logs::storage
