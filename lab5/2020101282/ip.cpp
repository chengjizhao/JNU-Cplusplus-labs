#include <iostream>
#include <iomanip>  // 用于格式化输出
#include <vector>

class IPHeader {
public:
    // 构造函数，接收IP数据包的原始字节数据
    IPHeader(const std::vector<uint8_t>& data);
    
    // 获取IP头部字段的方法
    uint8_t getVersion() const;  // 获取版本
    uint8_t getHeaderLength() const;  // 获取头部长度
    uint16_t getTotalLength() const;  // 获取总长度
    // 可以添加更多方法来获取其他IP头部字段
    
    // 打印数据部分的16进制表示
    void printData() const;

private:
    std::vector<uint8_t> rawData;  // 存储原始数据
};

// 构造函数实现
IPHeader::IPHeader(const std::vector<uint8_t>& data) : rawData(data) {}

// 获取版本号
uint8_t IPHeader::getVersion() const {
    // 版本号存储在第一个字节的前4位
    return (rawData[0] >> 4) & 0xF;
}

// 获取头部长度
uint8_t IPHeader::getHeaderLength() const {
    // 头部长度存储在第一个字节的后4位
    return rawData[0] & 0xF;
}

// 获取总长度
uint16_t IPHeader::getTotalLength() const {
    // 总长度存储在第3和第4个字节（16位）
    return (rawData[2] << 8) | rawData[3];
}

// 打印数据部分的16进制表示
void IPHeader::printData() const {
    // 数据部分在IP头部之后
    // 在这个简化的示例中，我们假设数据部分从第20个字节开始（可以根据实际情况调整）
    std::cout << "数据部分的16进制表示: ";
    for (size_t i = 20; i < rawData.size(); ++i) {
        // setw(2)设置每个字节输出2位，setfill('0')不足2位用0填充
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(rawData[i]) << " ";
    }
    std::cout << std::dec << "\n";  // 切换回十进制输出
}

int main() {
    // 示例IP数据包数据（简化演示）
    std::vector<uint8_t> ipPacket = {0x45, 0x00, 0x00, 0x1C, 0x12, 0x34, 0x00, 0x00, 0x40, 0x06, 0x00, 0x00, 0xC0, 0xA8, 0x01, 0x01, 0xC0, 0xA8, 0x01, 0x02};

    // 创建IPHeader对象
    IPHeader ipHeader(ipPacket);

    // 提取并打印IP头部字段
    std::cout << "版本: " << unsigned(ipHeader.getVersion()) << "\n";
    std::cout << "头部长度: " << unsigned(ipHeader.getHeaderLength()) << " 字（32位字）\n";
    std::cout << "总长度: " << ipHeader.getTotalLength() << " 字节\n";

    // 打印数据部分的16进制表示
    ipHeader.printData();

    return 0;
}
