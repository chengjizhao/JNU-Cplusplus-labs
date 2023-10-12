#include <iostream>
#include <iomanip>
#include <vector>

struct IPHeader
{
    uint8_t  VerLen;
    uint8_t  TOS;
    uint16_t TotalLen;
    uint16_t ID;
    uint16_t FlagsFragOff;
    uint8_t  TTL;
    uint8_t  Protocol;
    uint16_t Checksum;
    uint32_t SrcAddr;
    uint32_t DstAddr;
};

void printData(const std::vector<uint8_t>& data)
{
    std::cout << "Data (" << data.size() << " bytes): ";
    for (const auto& byte : data)
    {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<uint8_t> buf = {
        0x77, 0x16, 0x00, 0x3c, 0x18, 0xd1, 0x40, 0x00, 0x40, 0x06,
        0xe7, 0x77, 0xc0, 0xa8, 0xd1, 0x01, 0xac, 0x7e, 0x03, 0xfa,
        0x08, 0xfa, 0x6a, 0x8a, 0x4a, 0xcd, 0xdd, 0xcf, 0x7e, 0x80,
        0x10, 0x07, 0xe5, 0xb7, 0x73, 0x02, 0x00, 0x05, 0xa6, 0xb7,
        0xce, 0x6e, 0x45, 0x3b, 0x1d, 0x00, 0x04, 0x53, 0xc4, 0xb6
    };

    IPHeader header;
    std::memcpy(&header, buf.data(), sizeof(IPHeader));

    std::vector<uint8_t> data(buf.begin() + sizeof(IPHeader), buf.end());

    printData(data);

    return 0;
}
