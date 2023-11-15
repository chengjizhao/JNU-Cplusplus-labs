#include <iostream>
using namespace std;
//菱形继承
class Top
{
    public:
        int top;
};

class Left : public Top
{
    public:
        double left;
};

class Right : public Top
{
    public:
        double right;
};

class Bottom : public Left, public Right
{
    public:
        int bottom;
};

int main()
{
    Bottom obj;

    int *top_left_ptr = reinterpret_cast<int*>(&obj.Left::top);
    int *top_right_ptr = reinterpret_cast<int*>(&obj.Right::top);
    int *left_ptr = reinterpret_cast<int*>(&obj.left);
    int *right_ptr = reinterpret_cast<int*>(&obj.right);
    int *bottom_ptr = reinterpret_cast<int*>(&obj.bottom);

    cout << "top_left: " << reinterpret_cast<void*>(top_left_ptr) << endl;
    cout << "left: " << reinterpret_cast<void*>(left_ptr) << endl;
    cout << "top_right: " << reinterpret_cast<void*>(top_right_ptr) << endl;
    cout << "right: " << reinterpret_cast<void*>(right_ptr) << endl;
    cout << "bottom: " << reinterpret_cast<void*>(bottom_ptr) << endl;
}