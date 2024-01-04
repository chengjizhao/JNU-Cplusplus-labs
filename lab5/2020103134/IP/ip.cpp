#include<iostream>
#include<iomanip>

using namespace std;

class IP_packet
{
    private:
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

    public:
    void show() 
    {
        cout<<hex<<VerLen<<""<<TOS<<""<<TotalLen<<""<<ID<<""<<FlagsFragOff<<endl;
        cout<<hex<<TTL<<""<<Protocol<<""<<Checksum<<""<<SrcAddr<<""<<DstAddr<<endl;
    };
    
};