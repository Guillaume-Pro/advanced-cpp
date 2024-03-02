#include <iostream>

import server;

int main()
{
    try
    {
        constexpr int PORT = 8080;

        TCPServer server(PORT);
        server.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
