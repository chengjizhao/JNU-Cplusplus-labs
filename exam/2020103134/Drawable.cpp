#include<iostream>

class Drawable{
    public:
    virtual void draw()=0;
};

class Resizeable{
    public:
    virtual void resize(int factor)=0;
};

class Circle:public Drawable,public Resizeable{
    private:
    int r;
    public:
    void draw(){std::cout<<"画一个圆,半径为："<<r<<std::endl;}
    void resize(int factor){r=factor;}
};

class Square:public Drawable,public Resizeable{
    private:
    int a;
    public:
    void draw(){std::cout<<"画一个正方形,边长为："<<a<<std::endl;}
    void resize(int factor){a=factor;}
};

int main(){
    Circle obj1;
    Square obj2;
    Drawable *p[2]={&obj1,&obj2};
    *p[0]->resize(1);
    *p[0]->draw();
    *p[1]->resize(2);
    *p[1]->draw();
    
    return 0;
}