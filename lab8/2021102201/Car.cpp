#include <iostream>

using namespace std;

class Car
{
    public:
        virtual void calculatePrice(int n)
        {
            cout << "The car is 100000 yuan." << endl;
        }
};

class Sedan : public Car
{
    private:
        int price = 200000;
    public:
        void calculatePrice(int n) override
        {
            cout << n << " sedans are " << n * price << " yuan." << endl;
        }
};

class SUV : public Car
{
    private:
        int price = 300000;
    public:
        void calculatePrice(int n) override
        {
            cout << n << " suvs are " << n * price << " yuan." << endl;
        }
};

int main()
{
    Car* car1 = new Sedan();
    Car* car2 = new SUV();

    car1 -> calculatePrice(2);
    car2 -> calculatePrice(3);

    delete car1;
    delete car2;

    return 0;
}