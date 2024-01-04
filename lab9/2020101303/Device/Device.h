#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
using namespace std;

class Device
{
    public:
        virtual void runApp()
        {
            cout << "run:App_Device !!!" << endl; 
        }
        void run_Device()
        {
            cout << "run:Device !!!" << endl;
        }
};

class Computer :  public virtual Device 
{
    public:
        void runApp() override
        {
            cout << "run:App_Computer !!!" << endl;
        }
        void run()
        {
            cout << "run:Computer !!!" << endl;
        }
};

class Phone : public virtual Device
{
    public:
        void runApp() override
        {
            cout << "run:App_Phone !!!" << endl;
        }
        void run()
        {
            cout << "run:Phone !!!" << endl;
        }
};

class SmartDevice : public Computer, public Phone
{
    public:
        void runApp() override
        {
            cout << "run:App_SmartDevice !!!" << endl;
        }
};

#endif