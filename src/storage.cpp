#include "log/interfaces/storage.hpp"

#include "log/helpers.hpp"

#include <filesystem>
#include <fstream>
#include <unordered_map>

namespace logging::storage
{

const std::string filename = "traces.log";
const std::string directory = "logs/";

const std::unordered_map<logtype, std::string> typeNameMap = {
    {logtype::critical, "CRIT"},
    {logtype::error, "ERR"},
    {logtype::warning, "WARN"},
    {logtype::info, "INFO"},
    {logtype::debug, "DBG"}};

struct Log::Handler
{
  public:
    Handler(const std::string& dir, const std::string& file, logtype lvl) :
        fs{dir, file}
    {
        setlevel(lvl);
    }

    class Filesystem
    {
      public:
        Filesystem(const std::string& dirname, const std::string& filename) :
            basedir{dirname}, filename{filename}
        {
            if (std::filesystem::exists(basedir))
                std::filesystem::remove_all(basedir);
            std::filesystem::create_directories(basedir);
            storage.open(basedir + filename, std::ios::out);
            if (!storage.is_open())
            {
                throw std::runtime_error("Cannot open storage for logging");
            }
            storage << "Logging started at " << gettimestr() << "\n";
        }
        ~Filesystem() = default;

      public:
        std::ofstream storage;

      private:
        const std::string basedir;
        const std::string filename;
    } fs;

    std::string getinfo() const
    {
        return info;
    }

    void setlevel(logtype newlevel)
    {
        level = newlevel;
    }

    void log(logtype type, const std::string& msg)
    {
        if (type <= level)
            fs.storage << "[" << gettypename(type) << "] " << msg << "\n";
    }

  private:
    const std::string info{"storage"};
    logtype level{logtype::error};

    std::string gettypename(logtype type)
    {
        return typeNameMap.contains(type) ? typeNameMap.at(type) : "UNDEF";
    }
};

Log::Log(logtype lvl) :
    handler{std::make_unique<Handler>(directory, filename, lvl)}
{}

Log::~Log() = default;

std::string Log::info() const
{
    return handler->getinfo();
}

void Log::setlevel(logtype level)
{
    return handler->setlevel(level);
}

void Log::log(logtype type, const std::string& msg)
{
    handler->log(type, msg);
}

} // namespace logging::storage
