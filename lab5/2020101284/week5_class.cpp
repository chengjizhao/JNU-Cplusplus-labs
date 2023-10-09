#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class IPHeaderParser {
private:
    vector<uint8_t> data;

public:
    IPHeaderParser(const vector<uint8_t>& packetData) : data(packetData) {}

    void parseAndPrintData() {
        cout << "数据部分的十六进制值: ";

        for (size_t i = 0; i < data.size(); i++) {
            cout << hex << setw(2) << setfill('0') << static_cast<int>(data[i]) << " ";
        }

        cout << endl;
    }
};

int main() {
    vector<uint8_t> packetData = {
        0x45, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x40, 0x00, 0x40, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x01,
        0xc0, 0xa8, 0x01, 0x02
    };

    IPHeaderParser parser(packetData);
    parser.parseAndPrintData();

    return 0;
}