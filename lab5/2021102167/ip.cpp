#include<iostream>
#include<iomanip>
#include<stdint.h>
using namespace std;
class IP
{
    public:
        uint8_t  verLen;       
        uint8_t  tOS;          
        uint16_t totalLen;     
        uint16_t id;            
        uint16_t flagsfragOff;  
        uint8_t  ttL;          
        uint8_t  protocol;      
        uint16_t checksum;
        uint32_t srcAddr;       
        uint32_t dstAddr;  
	public:
void show()
{
    cout << hex <<verLen << " "<<checksum<< " " << dstAddr << " "<< flagsfragOff<< " " << id << " "<< protocol << " "<< srcAddr << " "<< tOS << " "<< totalLen << " "<< ttL << " ";
}

};
