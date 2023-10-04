#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class IP_Packet {
public:
    IP_Packet(const char* packet) {
        version = packet[0] >> 4;
        header_length = (packet[0] & 15) * 4;
        ttl = packet[8];
        protocol = packet[9];
        source_ip = packet + 12;
        destination_ip = packet + 16;
        data = packet + header_length;
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << "IP Packet:\n\tVersion: " << version << "\n\tHeader Length: " << header_length << " bytes\n\tTTL: " << static_cast<int>(ttl) << "\n\tProtocol: " << static_cast<int>(protocol) << "\n\tSource IP: " << ip_to_string(source_ip) << "\n\tDestination IP: " << ip_to_string(destination_ip) << "\n\tData: " << data_to_hex();
        return ss.str();
    }

private:
    int version;
    int header_length;
    char ttl;
    char protocol;
    const char* source_ip;
    const char* destination_ip;
    const char* data;

    std::string ip_to_string(const char* ip) const {
        std::stringstream ss;
        for (int i = 0; i < 4; ++i) {
            ss << static_cast<int>(static_cast<unsigned char>(ip[i]));
            if (i != 3) {
                ss << ".";
            }
        }
        return ss.str();
    }

    std::string data_to_hex() const {
        std::stringstream ss;
        for (int i = 0; i < strlen(data); ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<unsigned char>(data[i]));
        }
        return ss.str();
    }
};