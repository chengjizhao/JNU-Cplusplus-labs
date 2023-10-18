#include <iostream>
#include <iomanip>
#include <vector>
class IPPacketParser 
{
public:
 IPPacketParser(const std::vector<unsigned char>& packet) : packet(packet) {}
 void printData() const {
 std::cout << "Version: " << static_cast<int>(packet[0] >>4) << std::endl;
 std::cout << "Header Length: " << static_cast<int>(packet[0] &0x0F) *4 << " bytes" << std::endl;
 std::cout << "Service Type:0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[1]) << std::endl;
 std::cout << "Total Length: " << static_cast<int>(packet[2]) << static_cast<int>(packet[3]) << " bytes" << std::endl;
 std::cout << "Identification:0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[4]) << static_cast<int>(packet[5]) << std::endl;
 std::cout << "Flags:0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[6] >>5) << std::endl;
 std::cout << "Fragment Offset: " << static_cast<int>((packet[6] &0x1F) <<8) + static_cast<int>(packet[7]) << std::endl;
 std::cout << "Time to Live: " << static_cast<int>(packet[8]) << std::endl;
 std::cout << "Protocol: " << static_cast<int>(packet[9]) << std::endl;
 std::cout << "Checksum:0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[10]) << static_cast<int>(packet[11]) << std::endl;
 std::cout << "Source IP Address: ";
 for (int i =12; i <16; ++i) {
 std::cout << static_cast<int>(packet[i]);
 if (i !=15) {
 std::cout << ".";
 }
 }
 std::cout << std::endl;
 std::cout << "Destination IP Address: ";
 for (int i =16; i <20; ++i) {
 std::cout << static_cast<int>(packet[i]);
 if (i !=19) {
 std::cout << ".";
 }
 }
 std::cout << std::endl;
 std::cout << "Data: ";
 for (unsigned int i =20; i < packet.size(); ++i) {
 std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[i]) << " ";
 if ((i +1) %16 ==0) {
 std::cout << std::endl;
 }
 }
 std::cout << std::dec << std::endl;
 }
private:
 std::vector<unsigned char> packet;
};
int main() {
 std::vector<unsigned char> packet = {0x45,0x00,0x00,0x2C,0x7C,0x4A,0x40,0x00,0x40,0x06,0x00,0x00,0xC0,0xA8,0x01,0x01,0xC0,0xA8,0x01,0x02};
 IPPacketParser parser(packet);
 parser.printData();
 return 0;
}