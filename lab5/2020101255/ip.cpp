#include <iostream>
#include <iomanip>
// #include <arpa/inet.h>

class IPPacket {
public:
    struct IPHeader {
        uint8_t  VerLen;        // �汾�� + ͷ����
        uint8_t  TOS;           // ��������
        uint16_t TotalLen;      // �ܳ���
        uint16_t ID;            // ��ʶ
        uint16_t FlagsFragOff;  // ��־ + Ƭƫ��
        uint8_t  TTL;           // ����ʱ��
        uint8_t  Protocol;      // Э���
        uint16_t Checksum;      // У���
        uint32_t SrcAddr;       // Դ IP ��ַ
        uint32_t DstAddr;       // Ŀ�� IP ��ַ
    };

    IPPacket(const char* buf, int len);

    void printData();

private:
    IPHeader header_;
    const char* data_;
    int data_len_;
};

// ���캯��
IPPacket::IPPacket(const char* buf, int len) : data_(buf + sizeof(IPHeader)), data_len_(len - sizeof(IPHeader)) {
    memcpy(&header_, buf, sizeof(IPHeader));
}

// ��ӡ������
void IPPacket::printData() {
    std::cout << "Data (" << std::dec << data_len_ << " bytes): " ;
    for (int i = 0; i < data_len_; ++i) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)(uint8_t)data_[i] << " ";
    }
    std::cout << std::endl;
}

// ʾ���÷�
int main() {
    // ����һ�� IP ���ݰ�
    uint8_t buf[] = {
        0x45, 0x00, 0x00, 0x3c, 0x18, 0xd1, 0x40, 0x00, 0x40, 0x06,
        0xe7, 0x77, 0xc0, 0xa8, 0x01, 0x01, 0xac, 0x10, 0x03, 0xfa,
        0x08, 0x00, 0x6a, 0x8a, 0x00, 0x02, 0xdd, 0xef, 0x7e, 0x80,
        0x10, 0x00, 0xe5, 0xb7, 0x93, 0xcd, 0x00, 0x00
    };
    IPPacket packet((const char*)buf, sizeof(buf));

    // ��ӡ������
    packet.printData();

    return 0;
}
