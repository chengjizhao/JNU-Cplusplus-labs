#include <iostream>
#include <iomanip>
#include <cstdint>

class IPPacket 
{
public:
    struct IPHeader
    {
        uint8_t  versionLength;
        uint8_t  tos;
        uint16_t totalLength;
        uint16_t id;
        uint16_t flagsFragOff;
        uint8_t  ttl;
        uint8_t  protocol;
        uint16_t checksum;
        uint32_t srcAddr;
        uint32_t dstAddr;
    };

    IPPacket(const char* buf, int len);

    void printData();

private:
    IPHeader header_;
    const char* data_;
    int dataLength;
};

IPPacket::IPPacket(const char* buf, int len) : data_(buf + sizeof(IPHeader)), dataLength(len - sizeof(IPHeader)) 
{
    memcpy(&header_, buf, sizeof(IPHeader));
}

void IPPacket::printData() 
{
    std::cout << "Data (" << std::dec << dataLength << " bytes): " ;
    for (int k = 0; k < dataLength; ++k) 
    {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(static_cast<uint8_t>(data_[k])) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    uint8_t buffer[] = 
    {
        0x77, 0x16, 0x00, 0x3c, 0x18, 0xd1, 0x40, 0x00, 0x40, 0x06,
        0xe7, 0x77, 0xc0, 0xa8, 0xd1, 0x01, 0xac, 0x7e, 0x03, 0xfa,
        0x08, 0xfa, 0x6a, 0x8a, 0x4a, 0xcd, 0xdd, 0xcf, 0x7e, 0x80,
        0x10, 0x07, 0xe5, 0xb7, 0x73, 0x02, 0x00, 0x05, 0xa6, 0xb7,
        0xce, 0x6e, 0x45, 0x3b, 0x1d, 0x00, 0x04, 0x53, 0xc4, 0xb6
    };
    IPPacket packet(reinterpret_cast<const char*>(buffer), sizeof(buffer));

    packet.printData();

    return 0;
}