#include<iostream>

using namespace std;

class Car
{
    public:
    virtual int calculatePrice()
    {
        return 0;
    }
    private:
    int wheels;
    float weight;
    int people ;
};
class Sedan : public Car
{
    public:
    virtual int calculatePrice()
    {
        return price;
    }
    private:
    int price=200000;

};
class SUV : public Car
{
    public:
    virtual int calculatePrice()
    {
        return price;
    }
    private:
    int price=300000;

};
int main()
{
    Sedan car1;
    SUV car2;
    cout<< "Sedan:" << car1.calculatePrice() <<endl;
    cout<< "SUV:" << car2.calculatePrice() <<endl;
    return 0;

}