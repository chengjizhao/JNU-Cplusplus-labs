#include<string>
#include<iostream>
using namespace std;

class CIP
{
private:
    int version;
    int head_length;
    int service;
    int total_length;
    int identification;
    int flag;
    int Foffset;
    int TTL;
    int protocol;
    int head_checksum;
    int source_ip_address;
    int destination_ip_address;
    int option;
public:
    void set(){
        cout<<hex<<version<<head_length<<service<<total_length
        <<identification<<flag<<Foffset<<TTL<<protocol<<head_checksum<<source_ip_address<<destination_ip_address<<option;
    }
};
