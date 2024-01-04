#include "iostream"
#include "header.h"

cPerson XiaoMing;                           //用默认构造函数创建


int main()
{
    Test test1;
    Test test2(1);                              //隐式调用构建
    Test test3 = Test(1);                       //显式调用构建
    Test* test4 = new Test(1);                  //用new显式调用构建   

    cout << "输出4种创建方法的大小:" << endl;
    cout << sizeof(test1) << endl;
    cout << sizeof(test2) << endl;
    cout << sizeof(test3) << endl;
    cout << sizeof(test4) << endl;

    delete test4;
    cout << "前三种都是创建了实体,根据class的定义来开辟内存区域。理论上应该是13个字节,但是因为内存对齐," << endl;
    cout << "故补到16字节.最后用new的方法,应该是存到了Test(1)构建后的地址,只有8字节" << endl;

    int task;

    cout << "请输入姓名(英文):" << endl;
    cin >> XiaoMing.name;

    while(1)
    {
        cout << "请选择要执行的操作(1:写入 2:读取)" << endl;
        cin >> task;
        if(task == 1)
        {
            cout << "请选择要写入的数据" << endl;
            cout << "1.生日  2.性别  3.身高  4.体重" << endl;
            cin >> task;
            XiaoMing.data_write(task);
        }
        else if(task == 2)
        {
            XiaoMing.data_read();
        }
    }
    return 0;
}
