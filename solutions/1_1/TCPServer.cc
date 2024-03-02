module;

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <optional>

export module server;

export class TCPServer
{
public:
    TCPServer(int port) : port(port), server_fd(socket(AF_INET, SOCK_STREAM, 0))
    {
        if (server_fd == 0)
        {
            throw std::runtime_error("Socket creation failed");
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        memset(address.sin_zero, '\0', sizeof(address.sin_zero));

        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
        {
            throw std::runtime_error("Bind failed");
        }

        if (listen(server_fd, 10) < 0)
        {
            throw std::runtime_error("Listen failed");
        }
    }

    std::optional<int> acceptConnection()
    {
        int addrlen = sizeof(address);
        int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0)
        {
            std::cerr << "Acceptance failed" << std::endl;
            return std::nullopt;
        }
        return new_socket;
    }

    void run()
    {
        std::cout << "Server listening on port " << port << "..." << std::endl;
        auto new_socket = acceptConnection();
        if (new_socket.has_value())
        {
            char buffer[1024] = {0};
            long valread = read(new_socket.value(), buffer, 1024);
            std::cout << "Command received: " << buffer << std::endl;
            std::string response = "Command received\n";
            send(new_socket.value(), response.c_str(), response.length(), 0);
            std::cout << "Response sent" << std::endl;
            close(new_socket.value());
        }
    }

    ~TCPServer()
    {
        close(server_fd);
    }

private:
    int server_fd;
    struct sockaddr_in address;
    int port;
};
