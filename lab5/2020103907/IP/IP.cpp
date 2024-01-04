#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
class IPHeaderParser {
public:
    IPHeaderParser(const vector<uint8_t>& packet) : packet_(packet) {}

    void ParseAndPrintHeader() {
        if (packet_.size() < 20) {
            cout << "Invalid IP packet size." << endl;
            return;
        }

        cout << "IP Header:" << endl;
        cout << "Version: " << (packet_[0] >> 4) << endl;
        cout << "Header Length: " << (packet_[0] & 0x0F) * 4 << " bytes" << endl;
        cout << "Service Type: 0x" << hex << static_cast<int>(packet_[1]) << endl;
        cout << "Total Length: " << static_cast<int>((packet_[2] << 8) | packet_[3]) << " bytes" << endl;
        cout << "ID: 0x" << hex << static_cast<int>((packet_[4] << 8) | packet_[5]) << endl;
        cout << "Flags: 0x" << hex << static_cast<int>((packet_[6] >> 5) & 0x07) << endl;
        cout << "Fragment Offset: " << static_cast<int>(((packet_[6] & 0x1F) << 8) | packet_[7]) << " bytes" << endl;
        cout << "Time to Live (TTL): " << static_cast<int>(packet_[8]) << endl;
        cout << "Protocol: " << static_cast<int>(packet_[9]) << endl;
        cout << "Header Checksum: 0x" << hex << static_cast<int>((packet_[10] << 8) | packet_[11]) << endl;
        cout << "Source IP Address: ";
        for (int i = 12; i < 16; ++i) {
            cout << static_cast<int>(packet_[i]);
            if (i < 15) cout << ".";
        }
        cout << endl;

        cout << "Destination IP Address: ";
        for (int i = 16; i < 20; ++i) {
            cout << static_cast<int>(packet_[i]);
            if (i < 19) cout << ".";
        }
        cout << endl;
    }

    void PrintData() {
        if (packet_.size() > 20) {
            cout << "Data:" << endl;
            for (size_t i = 20; i < packet_.size(); ++i) {
                cout << hex << setw(2) << setfill('0') << static_cast<int>(packet_[i]) << " ";
                if ((i - 19) % 16 == 0) cout << endl;
            }
            cout << dec << endl;
        }
    }

private:
    std::vector<uint8_t> packet_;
};

int main() {
    // 示例IP数据包（以十六进制表示）
    std::vector<uint8_t> packet = {
        0x45, 0x00, 0x00, 0x54, 0x12, 0x34, 0x40, 0x00,
        0x40, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x01,
        0xc0, 0xa8, 0x01, 0x02, 0x01, 0x02, 0x03, 0x04,
        0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c
    };

    IPHeaderParser parser(packet);
    parser.ParseAndPrintHeader();
    parser.PrintData();

    return 0;
}

