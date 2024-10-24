#include "log/interfaces/collection.hpp"
#include "log/interfaces/console.hpp"
#include "log/interfaces/storage.hpp"

#include <iostream>

int main()
{
    try
    {
        auto lvl = logging::logtype::debug;
        auto logconsole =
            logging::LogFactory::create<logging::console::Log>(lvl);
        auto logstorage =
            logging::LogFactory::create<logging::storage::Log>(lvl);
        auto logIf = logging::LogFactory::create<logging::collection::Log>(
            {logconsole, logstorage});
        logIf->log(logging::logtype::info, "Test log number one");
        logIf->log(logging::logtype::critical, "Additional test log");
    }
    catch (std::exception& err)
    {
        std::cerr << "[ERROR] " << err.what() << '\n';
    }

    return 0;
}
