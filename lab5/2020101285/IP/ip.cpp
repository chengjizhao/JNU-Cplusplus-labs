#include<iostream>
#include<iomanip>
#include"ip.h"

IP::~IP(){}

IP::IP(vector<uint8_t>& ip_packet){
    if (ip_packet.size()<20)
    {
        cout<<"The min size of packet are 20 byte!\n packet wrong!";
        return;
    }
    this->version = ip_packet[0] >> 4;
    this->headerlen = ip_packet[0] & 0x0f;
    this->tos = ip_packet[1];
    this->tolallen = (ip_packet[2]<<8)|(ip_packet[3]);
    this->identification = (ip_packet[4]<<8)|(ip_packet[5]);
    this->flag = ip_packet[6]>>5;
    this->offset = ((ip_packet[6]&0x1f)<<8)|(ip_packet[7]);
    this->ttl = ip_packet[8];
    this->protocol = ip_packet[9];
    this->headerchecksum = (ip_packet[10]<<8)|(ip_packet[11]);
    this->ip_sourceadd = (ip_packet[12]<<24)|(ip_packet[13]<<16)|(ip_packet[14]<<8)|(ip_packet[15]);
    this->ip_destadd = (ip_packet[16]<<24)|(ip_packet[17]<<16)|(ip_packet[18]<<8)|(ip_packet[19]);

    uint32_t data_len = this->tolallen - this->headerlen*4;  //计算数据段长度
    this->data.resize(data_len);
    if (data_len!=0)
    {
        for (int i = 0;i<data_len;i++)
        {
            this->data[i]=(ip_packet[this->headerlen*4 + i]) ;
        }
    }
}

void IP::printf_data_hex(){
    int i = 0;
    for (auto it = this->data.begin(); it!=this->data.end(); it++){
        printf("0x%02x ",(unsigned int)*it);
        i++;
        if (i == 8){ 
            cout<<endl; //按8个字节一行输出
            i=0;
        }
    }
}

void IP::printf_data_ASCII(){
    for (auto it = this->data.begin(); it!=this->data.end(); it++){
        printf("%c",*it);
    }
}


bool IP::get_DF(){
    if ((this->flag>>1)&1 == 1)
        return true;
    else
        return false;
    
}
bool IP::get_MF(){
    if ((this->flag)&1 == 1)
        return true;
    else
        return false;
}