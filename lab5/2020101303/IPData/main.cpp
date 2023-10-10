#include "IPData.h"

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    vector<uint8_t> MyData = {'S', 't', 'u', 'd', 'e', 'n', 't', '1'};
    IPData MyIP = IPData(0b00101010, 2, 4, 6, 8, 10, 12, 14, 16, 18, MyData);
    vector<uint8_t> mydata(MyIP.getData());
    cout << "以十六进制输出数据部分：" << endl;
    for (auto i : mydata) 
    {
        cout << "0x" << hex << (int)i << ' ';
    }
    cout << endl;
    return 0;
}