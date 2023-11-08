#include <iostream>
#include "Device.h"
using namespace std;

int main()
{
    SmartDevice obj;
    
    Device* ptr1 = &obj;
    Computer* ptr2 = &obj;
    Phone* ptr3 = &obj;
    ptr1 -> runApp();
    ptr2 -> runApp();
    ptr3 -> runApp();

    obj.run_Device();

    obj.Computer::run();
    obj.Phone::run();

    return 0;
}