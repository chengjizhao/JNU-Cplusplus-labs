#include <iostream>
#include <iomanip>
// #include <arpa/inet.h>

class IPPacket {
public:
    struct IPHeader {
        uint8_t  VerLen;        // 版本号 + 头长度
        uint8_t  TOS;           // 服务类型
        uint16_t TotalLen;      // 总长度
        uint16_t ID;            // 标识
        uint16_t FlagsFragOff;  // 标志 + 片偏移
        uint8_t  TTL;           // 生存时间
        uint8_t  Protocol;      // 协议号
        uint16_t Checksum;      // 校验和
        uint32_t SrcAddr;       // 源 IP 地址
        uint32_t DstAddr;       // 目的 IP 地址
    };

    IPPacket(const char* buf, int len);

    void printData();

private:
    IPHeader header_;
    const char* data_;
    int data_len_;
};

// 构造函数
IPPacket::IPPacket(const char* buf, int len) : data_(buf + sizeof(IPHeader)), data_len_(len - sizeof(IPHeader)) {
    memcpy(&header_, buf, sizeof(IPHeader));
}

// 打印数据区
void IPPacket::printData() {
    std::cout << "Data (" << std::dec << data_len_ << " bytes): " ;
    for (int i = 0; i < data_len_; ++i) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)(uint8_t)data_[i] << " ";
    }
    std::cout << std::endl;
}

// 示例用法
int main() {
    // 构造一个 IP 数据包
    uint8_t buf[] = {
        0x45, 0x00, 0x00, 0x3c, 0x18, 0xd1, 0x40, 0x00, 0x40, 0x06,
        0xe7, 0x77, 0xc0, 0xa8, 0x01, 0x01, 0xac, 0x10, 0x03, 0xfa,
        0x08, 0x00, 0x6a, 0x8a, 0x00, 0x02, 0xdd, 0xef, 0x7e, 0x80,
        0x10, 0x00, 0xe5, 0xb7, 0x93, 0xcd, 0x00, 0x00
    };
    IPPacket packet((const char*)buf, sizeof(buf));

    // 打印数据区
    packet.printData();

    return 0;
}
