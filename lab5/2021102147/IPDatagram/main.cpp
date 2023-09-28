#include "IPv4Datagram.h"

#include <iostream>
#include <cstdint>

using std::cout, std::endl;

int main() {
    // 示例用法
    std::vector<uint8_t> payloadData = { 'H', 'E', 'L', 'L', 'O', ',', 'W', 'O', 'R', 'L', 'D','!' };
    IPv4Datagram packet(4, 5, 20, 12345, 0, 64, 6, 0, 0xC0A80101, 0xC0A80102, payloadData);
    std::vector<uint8_t> data(packet.getPayload());

    for (auto i : data) {
        std::cout << "0x" << std::hex << (int)i << ' ';
    }
    std::cout << '\n';

    return 0;
}