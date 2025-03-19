#include "logs/interfaces/console/logs.hpp"
#include "logs/interfaces/group/logs.hpp"
#include "logs/interfaces/storage/logs.hpp"

#include <iostream>

int main(int argc, [[maybe_unused]] char** argv)
{
    try
    {
        if (argc > 3)
        {
            auto lvl = (logs::level)atoi(argv[1]);
            auto time = (logs::time)atoi(argv[2]);
            auto tag = (logs::tags)atoi(argv[3]);

            using namespace logs;
            auto logconsole = Factory::create<console::Log, console::config_t>(
                {lvl, time, tag});
            auto logstorage = Factory::create<storage::Log, storage::config_t>(
                {lvl, time, tag, {}});
            auto logIf = Factory::create<group::Log, group::config_t>(
                {logconsole, logstorage});

            logIf->log(level::info, "tag", "Test log number one");
            logIf->log(level::critical, "tag",
                       "Additional test log\nMore information here");
        }
    }
    catch (std::exception& err)
    {
        std::cerr << "[ERROR] " << err.what() << '\n';
    }

    return 0;
}
