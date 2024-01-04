#include<iostream>

using namespace std;

class Car
{
    private:
    int price;

    public:
    virtual void calculatePrice(int p)
    {
        cout<<"计算价格"<<endl;
        price=p;
        cout<<"价格为："<<price<<endl;
    };
};

class Sedan : public Car
{
    public:
    void calculatePrice(int i) override
    {
        int p=i;
        Car::calculatePrice(p);
    }
};

class SUV : public Car
{
    public:
    void calculatePrice(int i) override
    {
        int p=i;
        Car::calculatePrice(p);
    }
};

int main()
{
    Sedan sedan;
    sedan.calculatePrice(12);

    SUV suv;
    suv.calculatePrice(13);

    return 0;
}