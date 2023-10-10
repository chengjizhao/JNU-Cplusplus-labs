#include <iostream>
#include <iomanip>
#include <vector>

class IpPacketParser {
public:
    IpPacketParser(const std::vector<uint8_t>& packetData) : packetData(packetData) {}

    void ParseAndPrintData() {
        if (packetData.size() < 20) {
            std::cout << "Invalid IP packet size." << std::endl;
            return;
        }

        // 解析IP数据包
        uint8_t ipVersion = (packetData[0] >> 4) & 0x0F;
        uint8_t headerLength = (packetData[0] & 0x0F) * 4;
        uint8_t protocol = packetData[9];

        std::cout << "IP Version: " << static_cast<int>(ipVersion) << std::endl;
        std::cout << "Header Length: " << static_cast<int>(headerLength) << " bytes" << std::endl;
        std::cout << "Protocol: " << static_cast<int>(protocol) << std::endl;

        std::cout << "Data (in hex): ";
        for (size_t i = headerLength; i < packetData.size(); ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packetData[i]) << " ";
        }
        std::cout << std::dec << std::endl;
    }

private:
    std::vector<uint8_t> packetData;
};

int main() {
    // 示例IP数据包，以16进制表示
    std::vector<uint8_t> packetData = {
        0x45, 0x00, 0x00, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x40, 0x06, 0x00, 0x00, 0xC0, 0xA8, 0x01, 0x01,
        0xC0, 0xA8, 0x01, 0x02, 0x08, 0x00, 0x31, 0x39, 0x02, 0xE4, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x02,
        0xFF, 0xFF, 0x16, 0xE2, 0x00, 0x00, 0x02, 0x04, 0x05, 0xB4, 0x04, 0x02, 0x08, 0x0A, 0x00, 0x00,
        0x03, 0xD4, 0x00, 0x00, 0x00, 0x00
    };

    IpPacketParser parser(packetData);
    parser.ParseAndPrintData();

    return 0;
}
//此程序定义了一个IpPacketParser类，该类接受一个包含IP数据包的字节向量，并解析其中的IP头部信息以及以16进制形式打印出数据部分。在主程序中，我们创建了一个示例IP数据包并使用IpPacketParser类来解析和打印数据。请注意，此示例仅支持IPv4，并且仅解析了IP头部的一些字段。根据需要，您可以扩展该类以支持更多的IP头部字段或处理更复杂的情况。
