#include <iostream>
#include <iomanip>
#include <vector>

class IPDataPacket {
public:
    IPDataPacket(const std::vector<unsigned char>& data) : rawData(data) {}

    void printData() const {
        for (unsigned char byte : rawData) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<unsigned char> rawData;
};

int main() {
    // 示例 IP 数据包的原始数据
    std::vector<unsigned char> packetData = {0x45, 0x00, 0x00, 0x1c, 0x7c, 0x8f, 0x40, 0x00, 0x40, 0x06, 0x00, 0x00, 0xac, 0x10, 0x02, 0x0a, 0xac, 0x10, 0x02, 0x14};

    IPDataPacket packet(packetData);
    packet.printData();

    return 0;
}