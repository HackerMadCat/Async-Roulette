#pragma once

#include <string>
#include <stdint-gcc.h>

namespace address {
    const std::string SERVER_HOST{"127.0.0.1"};
    const uint16_t SERVER_PORT = 7777;
}
namespace command {
    const std::string GET_PUBLIC_KEY{"get_public_key"};
};
