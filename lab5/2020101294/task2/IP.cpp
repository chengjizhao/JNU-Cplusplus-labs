#include <iostream>
#include <cstdint>
#include <vector>

class IPHeader {
public:
    IPHeader(const std::vector<uint8_t>& data) {
        if (data.size() >= 20) {
            version = (data[0] >> 4) & 0xF;
            headerLength = data[0] & 0xF;
            tos = data[1];
            totalLength = (data[2] << 8) | data[3];
            identification = (data[4] << 8) | data[5];
            flags = ((data[6] >> 5) & 0x7);
            fragmentOffset = ((data[6] & 0x1F) << 8) | data[7];
            ttl = data[8];
            protocol = data[9];
            headerChecksum = (data[10] << 8) | data[11];
            sourceIP = (static_cast<uint32_t>(data[12]) << 24) | (static_cast<uint32_t>(data[13]) << 16) | (static_cast<uint32_t>(data[14]) << 8) | data[15];
            destinationIP = (static_cast<uint32_t>(data[16]) << 24) | (static_cast<uint32_t>(data[17]) << 16) | (static_cast<uint32_t>(data[18]) << 8) | data[19];

            if (headerLength > 5) {
                for (size_t i = 20; i < headerLength * 4; ++i) {
                    options.push_back(data[i]);
                }
            }
        }
    }

    void PrintDataHex() const {
        size_t dataStart = headerLength * 4;
        for (size_t i = dataStart; i < options.size(); ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(options[i]) << " ";
        }
        std::cout << std::endl;
    }

private:
    uint8_t version;
    uint8_t headerLength;
    uint8_t tos;
    uint16_t totalLength;
    uint16_t identification;
    uint8_t flags;
    uint16_t fragmentOffset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t headerChecksum;
    uint32_t sourceIP;
    uint32_t destinationIP;
    std::vector<uint8_t> options;
};

int main() {
    std::vector<uint8_t> ipPacket = { /* 添加您的数据包字节数据 */ };
    IPHeader ipHeader(ipPacket);
    ipHeader.PrintDataHex();
    return 0;
}