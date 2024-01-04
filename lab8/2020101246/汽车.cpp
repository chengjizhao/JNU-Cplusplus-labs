#include<iostream>
using namespace std;

class Car{
    public:   
    virtual double calculatePrice ( ){return 0;};
};

class Sedan:public Car{
    private:
    double n_inprice;
    public:
    Sedan(const double & y){
        n_inprice=y;
    };
    double calculatePrice()override  
    {   
        double outprice=1000;
        double inprice=n_inprice;
        double price=outprice*5+inprice*300;
        return price;
    }
};

class Nvida:public Car{
    private:
    double s_inprice;
    public:
     Nvida(const double & y){
        s_inprice=y;
    };
    double calculatePrice( )override{
         double outprice,inprice;
        outprice=1000;
        inprice=s_inprice;
        double price=outprice*1.5+inprice*2400;
    return price;
    }
};

int main()
{   Sedan n_car(30000);
    Sedan* p=new Sedan(3000);
    p->calculatePrice();
    Sedan seda(3);
    Nvida Nvi(3);
   cout<<"The Sedan summary price is1 "<<Nvi.calculatePrice()<<endl;
   cout<<"The Nvida summary price is1 "<<seda.calculatePrice()<<endl;
return 0;
}