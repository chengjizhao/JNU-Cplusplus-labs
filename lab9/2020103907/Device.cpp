#include <iostream>

using namespace std;
class Device {
public:
    virtual void runAPP()
    {
        cout << "Running app" << endl;
    }
};

class Computer : virtual public Device {
public: 
    void runComputer()
    {cout << "open the computer" << endl;}
};

class Phone : virtual public Device {
public:
    void runPhone()
    {cout << "open the phone" << endl;}
};

class SmartDevice : public Computer, public Phone 
{
    
};

int main() {
    SmartDevice smartdevice;
    smartdevice.runAPP();
    smartdevice.runComputer();
    smartdevice.runPhone();

    return 0;
}

