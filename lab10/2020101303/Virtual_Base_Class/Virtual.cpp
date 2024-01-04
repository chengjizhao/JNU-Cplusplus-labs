#include <iostream>
using namespace std;

class Top
{
    public:
        int top;
        virtual void Public() {cout << "Public !" << endl;}
        void (*fptr)() = nullptr;
};

class Left : virtual public Top
{
    public:
        double left;
        virtual void left_() {cout << "Left !!!" << endl;}
};

class Right : virtual public Top
{
    public:
        double right;
        virtual void right_() {cout << "Right !!!" << endl;}
};

class Bottom : public Left, public Right
{
    public:
        int bottom;
        void Public() override {cout << "override !" << endl;}
        virtual void bottom_() {cout << "Bottom !!!" << endl;}
};

int main()
{
    Bottom obj;

    int *top_ptr = reinterpret_cast<int*>(&obj.top);
    int *left_ptr = reinterpret_cast<int*>(&obj.left);
    int *right_ptr = reinterpret_cast<int*>(&obj.right);
    int *bottom_ptr = reinterpret_cast<int*>(&obj.bottom);
    void *f = &obj.fptr;
    void (Bottom::*fptr_public)() = &Bottom::Public;
    void (Bottom::*fptr_left)() = &Bottom::left_;
    void (Bottom::*fptr_right)() = &Bottom::right_;
    void (Bottom::*fptr_bottom)() = &Bottom::bottom_;

    cout << "top: " << reinterpret_cast<void*>(top_ptr) << endl;
    cout << "left: " << reinterpret_cast<void*>(left_ptr) << endl;
    cout << "right: " << reinterpret_cast<void*>(right_ptr) << endl;
    cout << "bottom: " << reinterpret_cast<void*>(bottom_ptr) << endl;
    //虚函数
    cout << "left_: " << reinterpret_cast<void*>(obj.*fptr_left) << endl;
    cout << "right_: " << reinterpret_cast<void*>(obj.*fptr_right) << endl;
    cout << "Public: " << reinterpret_cast<void*>(obj.*fptr_public) << "     ";
    (obj.*fptr_public)();
    cout << "bottom_: " << reinterpret_cast<void*>(obj.*fptr_bottom) << endl;
}