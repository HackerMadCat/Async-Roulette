#include "Server.h"


Server::Server(int domain, int type, int protocol, address_t &address
) : CryptoServer(domain, type, protocol, address) {
}

bool Server::crypto_handle(id_t id, address_t address, const std::string &message) {
    if (message == "close")
        return true;
    std::string transformed(message.length(), 0);
    std::transform(message.begin(), message.end(), transformed.begin(), ::toupper);
    send(id, transformed);
    return false;
}

bool Server::handle(id_t id, address_t address, const std::string &message) {
    std::cout << TCPServer::format(id, address) << " message receive with length " << message.length() << std::endl;
    return CryptoServer::handle(id, address, message);
}

void Server::connect_handle(id_t id, address_t address) {
    CryptoServer::connect_handle(id, address);
    std::cout << TCPServer::format(id, address) << " client connected" << std::endl;
}

void Server::disconnect_handle(id_t id, address_t address) {
    CryptoServer::disconnect_handle(id, address);
    std::cout << TCPServer::format(id, address) << " client disconnected" << std::endl;
}