#include<cstdint>
#include<vector>
using namespace std;
class IP
{
private:
    uint8_t version :4;             //版本号
    uint8_t headerlen :4;           //首部长度
	uint8_t tos;                    //服务类型
	uint16_t tolallen;              //总长度
	uint16_t identification;        //标识符
	uint16_t flag :3;               //标志位
    uint16_t offset :13;            //片偏移
	uint8_t ttl;                    //生存时间
	uint8_t protocol;               //协议
	uint16_t headerchecksum;        //首部检验和
	uint32_t ip_sourceadd;          //源地址
	uint32_t ip_destadd;            //目标地址
	vector<uint8_t>data;            //数据
public:
    IP(vector<uint8_t>& IP_packet);
    void printf_data_hex();
    void printf_data_ASCII();
    bool get_DF();
    bool get_MF();
    ~IP();
};
