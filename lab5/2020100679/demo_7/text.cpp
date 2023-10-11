
#include <iostream>
#include <vector>

class IPParser {
public:
    IPParser(const std::vector<uint8_t>& data) : packetData(data) {}

    void parseAndPrintData() {
        // 解析和打印IP包数据
        for (size_t i = 0; i < packetData.size(); ++i) {
            if (i % 16 == 0)
                std::cout << std::hex << std::uppercase << static_cast<int>(packetData[i]);
            else if (i % 16 == 15)
                std::cout << " " << std::hex << std::uppercase << static_cast<int>(packetData[i]) << std::endl;
            else
                std::cout << " " << std::hex << std::uppercase << static_cast<int>(packetData[i]);
        }
        std::cout << std::dec << std::nouppercase;
    }

private:
    std::vector<uint8_t> packetData;
};

int main() {
    std::vector<uint8_t> packet = {0x45, 0x00, 0x00, 0x3C, 0x1F, 0x23, 0x40, 0x00, 0x40, 0x06, 0x00, 0x00, 0xC0, 0xA8, 0x01, 0x01,
                                   0xC0, 0xA8, 0x01, 0x02, 0xD4, 0x70, 0x00, 0x50, 0xF4, 0x5B, 0xB8, 0x3C, 0x00, 0x00, 0x00, 0x00};

    IPParser parser(packet);
    parser.parseAndPrintData();

    return 0;
}
