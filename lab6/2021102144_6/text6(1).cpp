#include<iostream>
using namespace std;
class Myclass
{
    private:
    int a=10;
    void f();
    public:
    //void f();
};
void Myclass::f()
{
    cout<<a<<endl;
}
void F(void(Myclass::*f)(),Myclass &M)
{
    (M.*f)();
}
int main()
{
    Myclass M;
    F(&Myclass::f,M);
    return 0;
}