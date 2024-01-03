#include <iostream>  
#include <cstring>  
#include <cstdint>  

class IPPacket {
public:
    IPPacket(const uint8_t* data) : raw_data(data) {
        parse();
    }

private:
    const uint8_t* raw_data;
    uint8_t version_header;
    uint8_t header_length;
    uint8_t type_of_service;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_and_fragment_offset;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_ip;
    uint32_t destination_ip;

    void parse() {
        // Checksum omitted for brevity  
        version_header = (*raw_data >> 4) & 0x0F;
        header_length = *raw_data & 0x0F;
        raw_data += 1;

        type_of_service = *raw_data++;
        total_length = ntohs(*reinterpret_cast<uint16_t*>(raw_data));
        raw_data += 2;

        identification = ntohs(*reinterpret_cast<uint16_t*>(raw_data));
        raw_data += 2;

        flags_and_fragment_offset = ntohs(*reinterpret_cast<uint16_t*>(raw_data));
        raw_data += 2;

        time_to_live = *raw_data++;
        protocol = *raw_data++;
        header_checksum = ntohs(*reinterpret_cast<uint16_t*>(raw_data));
        raw_data += 2;

        source_ip = ntohl(*reinterpret_cast<uint32_t*>(raw_data));
        raw_data += 4;

        destination_ip = ntohl(*reinterpret_cast<uint32_t*>(raw_data));
        raw_data += 4;
    }
};

int main() {
    // Example usage: Replace this with your actual IP packet data.  
    const uint8_t ip_packet[] = { 0x45, 0x00, 0x00, 0x3c, 0x54, 0x4d, 0x40, 0x00, 0x40, 0x11, 0xf8, 0x79, 0x0a, 0x78, 0x7a, 0xf8, 0x08, 0x00, 0x45, 0x00, 0x01, 0x58, 0xc7, 0x6b, 0xfc, 0x45, 0xac, 0x12, 0x3e, 0x1b, 0xd8, 0x3c, 0xd4, 0xf9 }; // Example IP packet in hex format. Adjust this accordingly.  
    IPPacket packet(ip_packet);
    std::cout << "Data (first 16 bytes): " << std::hex << std::setw(32) << std::setfill('0') << std::right << packet.raw_data << std::endl; // Print the first 16 bytes of the data part in hexadecimal format. Adjust the length as needed.  
    return 0;
}