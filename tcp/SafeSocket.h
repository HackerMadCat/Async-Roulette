#pragma once


#include "Socket.h"
#include <string>

class SafeSocket {
private:
    bool empty = false;
    Socket socket;

public:
    explicit SafeSocket(Socket &socket) : socket(socket.descriptor) {}; // NOLINT

    explicit SafeSocket(socket_t descriptor) : socket(descriptor) {}; // NOLINT

    void send(const char *message) {
        socket.send(message);
    }

    void send(const std::string &message) {
        socket.send(message);
    }

    std::string receive() {
        if (empty) throw Socket::error("socket is already read");
        empty = true;
        return socket.receive();
    }
};
