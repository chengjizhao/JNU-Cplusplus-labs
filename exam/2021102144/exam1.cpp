/*6.定义一个抽象基类Drawable，
包含纯虚函数void draw()。
从Drawable派生两个子类，Circle和Square，
分别实现draw函数以绘制圆和正方形。
定义一个接口Resizable，包含纯虚函数void resize(int factor)。
Circle和Square分别继承Resizable接口，并实现resize函数。
在main函数中创建一个Drawable指针数组，
包含一个Circle和一个Square对象，然后通过指针调用draw和resize函数，画UML图。*/
#include<iostream>
using namespace std;
class Drawable
{
    public:
    virtual void draw()=0;
};
class Circle:public Drawable
{
    public:
    virtual void draw()
    {
        cout<<"this is circle"<<endl;
    }
};
class Square:public Drawable
{
    public:
    virtual void draw()
    {
        cout<<"this is square"<<endl;
    }
};
class Resizeable 
{
   public:
   virtual void resize (int factor)=0 ;
};
class Circlere :public Resizeable
{
    public:
    virtual void resize(int factor)
    {
        cout<<"Circler's "<<factor<<endl;
    }
};
class Squarere :public Resizeable
{
    public:
    virtual void resize(int factor)
    {
        cout<<" Squares's "<<factor<<endl;
    }
};
int main()
{
    Drawable* ob[] = {new Circle, new Square};  
    ob[0]->draw();
    ob[1]->draw();
    Resizeable* ab[] = {new Circlere, new Squarere};  
    ab[0]->resize(1);
    ab[1]->resize(2);
    return 0;  
}