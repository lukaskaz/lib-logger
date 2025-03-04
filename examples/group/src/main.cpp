#include "log/interfaces/console/log.hpp"
#include "log/interfaces/group/log.hpp"
#include "log/interfaces/storage/log.hpp"

#include <iostream>

int main(int argc, [[maybe_unused]] char** argv)
{
    try
    {
        if (argc > 1)
        {
            using namespace logs;
            auto lvl = (level)atoi(argv[1]);
            auto logconsole =
                Factory::create<console::Log, console::config_t>(lvl);
            auto logstorage =
                Factory::create<storage::Log, storage::config_t>({lvl, {}});
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
