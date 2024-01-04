#include <iostream>
using namespace std;

class Car
{
    public:
        virtual void calculate_price() {};
};

class Sedan : public Car
{
    public:
        Sedan(int base_price_, int other_price_) : base_price(base_price_), other_price(other_price_) {};
        void calculate_price() override
        {
            cout << "Sedan的总价格: " << base_price + other_price << endl;
        }
    private:
        int base_price;
        int other_price;
};

class SUV : public Car
{
    public:
        SUV(int base_price_, int other_price_1_, int other_price_2_) : base_price(base_price_), other_price_1(other_price_1_), other_price_2(other_price_2_) {};
        void calculate_price() override
        {
            cout << "SUV的总价格: " << base_price + other_price_1 + other_price_2 << endl;
        }
    private:
        int base_price;
        int other_price_1;
        int other_price_2;
};

int main()
{
    Car *sedan = new Sedan(200000,5000);
    Car *suv = new SUV(150000,6000,800);

    sedan -> calculate_price();
    suv -> calculate_price();

    return 0;
}