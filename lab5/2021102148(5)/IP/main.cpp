#include "IP.h"

#include <iostream>
#include <cstdint>



int main() 
{
    std::vector<uint8_t> payloadData = { 'L', 'Y', 'X', '2', '0', '0', '3', '0', '1', '0', '5' };
    IPv4Datagram packet(4, 5, 20, 13525, 0, 64, 6, 0, 0xC0A80101, 0xC0A80102, payloadData);
    std::vector<uint8_t> data(packet.getPayload());

    for (auto i : data) {
        std::cout << "0x" << std::hex << (int)i << ' ';
    }
    std::cout << '\n';

    return 0;
}