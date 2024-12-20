#include "log/interfaces/console.hpp"
#include "log/interfaces/group.hpp"
#include "log/interfaces/storage.hpp"

#include <iostream>

int main()
{
    try
    {
        auto lvl = logging::type::debug;
        auto logconsole =
            logging::LogFactory::create<logging::console::Log>(lvl);
        auto logstorage =
            logging::LogFactory::create<logging::storage::Log>(lvl);
        auto logIf = logging::LogFactory::create<logging::group::Log>(
            {logconsole, logstorage});
        logIf->log(logging::type::info, "module", "Test log number one");
        logIf->log(logging::type::critical, "module",
                   "Additional test log\nMore information here");
    }
    catch (std::exception& err)
    {
        std::cerr << "[ERROR] " << err.what() << '\n';
    }

    return 0;
}
