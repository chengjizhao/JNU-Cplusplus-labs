#ifndef IP_H
#define IP_H
#include<stdint.h>
class IPHeader
{
public:
	struct IPheader
{
    uint8_t ip_versionlen;//版本号&IP包头长度
	uint8_t ip_tos;//服务类型
	uint16_t ip_tolallen; //总长度
	uint16_t ip_id;//标识符
	uint16_t ip_flagsoff; //标记&片偏移
	uint8_t ip_ttl; //生存时间
	uint8_t ip_protocol; //协议
	uint16_t ip_checksum; //首部检验和
	uint32_t ip_sourceadd;//源地址
	uint32_t ip_destadd;//目标地址
	//数据类型的字节数对应IP头部各个内容所需的字节数
};
void print();

};
#endif