#include<iostream>
#include<string>
using namespace std;
class Car
{
    public:
    virtual void cP()
    {
      cout<<price<<endl;
    }
    const double price=12;
};
class Bmw: public Car
{
    public:
    virtual void cP()
    {
        cout<<price/2<<endl;
    }
};
class Meisaidesi:public Car
{
  public:
  virtual void cP()
  {
    cout<<price/3<<endl;
  }
};
int main()
{
    Car* car1=new Bmw();
    Car* car2=new Meisaidesi();
    car1->cP();
    car2->cP();
    delete car1;
    delete car2;
    return 0;
}
