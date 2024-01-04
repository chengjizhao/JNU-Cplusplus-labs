#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend void goodfriend(Building *building); // 全局函数goodfriend是Building的友元
    friend void usefunc2(Building &build);

public:
    string m_sittingroom = "客厅";
    void func1();

private:
    string m_bedroom = "卧室";
    void func2();
};

// 全局函数
void goodfriend(Building *building)
{
    cout << "好朋友正在访问： " << building->m_bedroom << endl;
}
void usefunc2(Building &build)
{
    void (Building::*pfunc2)(); // 绑定类函数func1指针
    pfunc2 = &Building::func2;
    (build.*pfunc2)();
}
//  成员函数定义
void Building::func1()
{
    cout << "成功调用类的pubilc成员函数func1" << endl;
}
void Building::func2()
{
    cout << "成功调用类的private成员函数func2" << endl;
}

// 主函数
int main()
{
    Building building;

    // goodfriend(&building);

    void (Building::*pfunc1)(); // 绑定类函数func1指针
    pfunc1 = &Building::func1;
    (building.*pfunc1)();

    usefunc2(building);

    return 0;
}