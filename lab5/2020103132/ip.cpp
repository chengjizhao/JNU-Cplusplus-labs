/*创建一个类，它能处理IP数据包的解析，包头结构如下，具体定义可以参考
    https://zhuanlan.zhihu.com/p/142199583，用16进制打印出数据部分。
*/
#include<iostream>
#include<iomanip>
#include<stdint.h>
using namespace std;
class IP
{
    private:
        uint8_t  ip_verLen; //无符号8位整数类型
        uint8_t  ip_TOS;           
        uint16_t ip_totalLen;      
        uint16_t ip_id;          
        uint16_t ip_flagsfragOff; 
        uint8_t  ip_ttL;         
        uint8_t  ip_protocol;    
        uint16_t ip_checksum;      
        uint32_t ip_srcAddr;      
        uint32_t ip_dstAddr;       
public:
void show(){}
};

void IP::show() 
{
    cout << hex <<ip_verLen << " "<<ip_checksum<< " " << ip_dstAddr << " "\
    << ip_flagsfragOff<< " " << ip_id << " "<< ip_protocol << " "\
    << ip_srcAddr << " "<< ip_TOS << " "<< ip_totalLen << " "<< ip_ttL << " ";
}

int main() 
{
    uint8_t buf[] ={
        0x45, 0x00, 0x00, 0x3c, 0x18, 0xd1, 0x40, 0x00, 0x40, 0x06,
        0xe7, 0x77, 0xc0, 0xa8, 0x01, 0x01, 0xac, 0x10, 0x03, 0xfa,
        0x08, 0x00, 0x6a, 0x8a, 0x00, 0x02, 0xdd, 0xef, 0x7e, 0x80,
        0x10, 0x00, 0xe5, 0xb7, 0x93, 0xcd, 0x00, 0x00
    };
    IP show();

    return 0;
}