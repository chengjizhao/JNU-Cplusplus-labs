#include<iostream>
#include<iomanip>
#include<stdint.h>
using namespace std;
class IP
{
    private:
        uint8_t  ip_verLen;        // 版本号 + 头长度
        uint8_t  ip_tOS;           // 服务类型
        uint16_t ip_totalLen;      // 总长度
        uint16_t ip_id;            // 标识
        uint16_t ip_flagsfragOff;  // 标志 + 片偏移
        uint8_t  ip_ttL;           // 生存时间
        uint8_t  ip_protocol;      // 协议号
        uint16_t ip_checksum;      // 校验和
        uint32_t ip_srcAddr;       // 源 IP 地址
        uint32_t ip_dstAddr;       // 目的 IP 地址
public:
void show()
{
    cout << hex <<ip_verLen << " "<<ip_checksum<< " " << ip_dstAddr << " "<< ip_flagsfragOff<< " " << ip_id << " "<< ip_protocol << " "<< ip_srcAddr << " "<< ip_tOS << " "<< ip_totalLen << " "<< ip_ttL << " ";
}

};