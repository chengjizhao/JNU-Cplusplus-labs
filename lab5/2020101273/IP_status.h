#include <iostream>  
#include <vector>  
#include <bitset>  
#include <cstring>

// IPHeader 结构体  
struct IPHeader {  
    char version_ihl; // 版本和头部长度  
    char type_of_service;  
    char total_length;  
    char identification;  
    char flags_fragment_offset;  
    char time_to_live;  
    char protocol;  
    char header_checksum;  
    char source_ip;  
    char destination_ip;  
};

// IPPacket 类  
class IPPacket {  
public:  
    IPPacket(const std::vector<char>& data) : data_(data) {  
        parseIPHeader();  
    }

    void printDataInHex() {  
        std::string hex_data = toHexString(data_);  
        std::cout << "数据部分(16 进制)：" << hex_data << std::endl;  
    }

private:  
    void parseIPHeader() {  
        if (data_.size() < sizeof(IPHeader)) {  
            throw std::runtime_error("IP 数据包长度不足");  
        }

        IPHeader header;  
        std::memcpy(&header, data_.data(), sizeof(IPHeader));

        version_ = header.version_ihl >> 4;  
        ihl_ = header.version_ihl & 0x0F;  
        type_of_service_ = header.type_of_service;  
        total_length_ = header.total_length;  
        identification_ = header.identification;  
        flags_fragment_offset_ = header.flags_fragment_offset;  
        time_to_live_ = header.time_to_live;  
        protocol_ = header.protocol;  
        header_checksum_ = header.header_checksum;  
        source_ip_ = header.source_ip;  
        destination_ip_ = header.destination_ip;  
    }

    std::string toHexString(const std::vector<char>& data) {  
        std::string hex_data;  
        for (const auto& byte : data) {  
            hex_data += std::to_string(byte);  
        }  
        return hex_data;  
    }

    char version_;  
    char ihl_;  
    char type_of_service_;  
    char total_length_;  
    char identification_;  
    char flags_fragment_offset_;  
    char time_to_live_;  
    char protocol_;  
    char header_checksum_;  
    char source_ip_;  
    char destination_ip_;

    std::vector<char> data_;  
};