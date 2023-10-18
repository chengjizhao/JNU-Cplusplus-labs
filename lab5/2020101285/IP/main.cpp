#include<iostream>
#include<vector>
#include<cstdint>
#include"ip.h"
using namespace std;

int main()
{
    vector<uint8_t>packet=
    {
        0x45, 0x00, 0x00, 0x23, 0x00, 0x00, 0x40, 0x00, 0x40, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x01,
        0xc0, 0xa8, 0x01, 0x02, 0x00, 0x00, 0x19, 0x87, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f,
        0x72, 0x6c, 0x64
    };
    IP ip1(packet);
    cout<<"Print out the data portion in hexadecimal"<<endl;
    ip1.printf_data_hex();
    cout<<endl<<"Print out the data portion in ASCII character"<<endl;
    ip1.printf_data_ASCII();
    return 0;
}