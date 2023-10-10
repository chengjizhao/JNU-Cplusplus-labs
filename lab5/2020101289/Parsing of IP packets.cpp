
#include <iostream>
#include <iomanip>
#include <vector>

class IPHeader {
private:
    std::vector<unsigned char> data;

public:
    IPHeader(const std::vector<unsigned char>& packetData) : data(packetData) {}

    void printHexData() const {
        std::cout << "版本: " << static_cast<int>(data[0] >> 4) << std::endl;
        std::cout << "头部长度: " << (data[0] & 0x0F) * 4 << " bytes" << std::endl;
        std::cout << "服务类型: 0x" << std::hex << static_cast<int>(data[1]) << std::endl;
        std::cout << "总长度: " << (data[2] << 8) + data[3] << " bytes" << std::endl;
        std::cout << "ID标识符: 0x" << std::hex << ((data[4] << 8) + data[5]) << std::endl;
        std::cout << "标记: 0x" << std::hex << ((data[6] & 0xE0) >> 5) << std::endl;
        std::cout << "分片偏移: " << ((data[6] & 0x1F) << 8) + data[7] << std::endl;
        std::cout << "生存时间: " << static_cast<int>(data[8]) << std::endl;
        std::cout << "协议: " << static_cast<int>(data[9]) << std::endl;
        std::cout << "报头校验和: 0x" << std::hex << ((data[10] << 8) + data[11]) << std::endl;
        std::cout << "源IP地址: ";
        for (int i = 12; i < 16; ++i) {
            std::cout << static_cast<int>(data[i]);
            if (i != 15)
                std::cout << ".";
        }
        std::cout << std::endl;
        std::cout << "目的IP地址: ";
        for (int i = 16; i < 20; ++i) {
            std::cout << static_cast<int>(data[i]);
            if (i != 19)
                std::cout << ".";
        }
        std::cout << std::endl;

        // 可选字段的处理
        int optionalFieldsStartIndex = (data[0] & 0x0F) * 4;
        if (optionalFieldsStartIndex > 20) {
            std::cout << "可选字段: ";
            for (int i = 20; i < optionalFieldsStartIndex; ++i) {
                std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // 示例用IP数据包（仅包含部分字段）
    std::vector<unsigned char> packetData = {
        0x45, 0x00, 0x00, 0x3C, 0x1E, 0xC5, 0x40, 0x00,
        0x40, 0x06, 0xB8, 0x7B, 0xC0, 0xA8, 0x01, 0x02,
        0xC0, 0xA8, 0x01, 0x01
    };

    IPHeader ipHeader(packetData);
    ipHeader.printHexData();

    return 0;
}