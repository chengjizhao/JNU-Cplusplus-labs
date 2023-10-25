// C++code5.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//circle rectangle triangle 是shape的继承类
//start系列的文件是初始化三角形 圆 正方形
//getarea是获取面积
//show是显示图形信息
//set是设置图形的基本信息
//三角形求面积用了海伦公式
//用while循环确保输入的长宽等必要信息符合要求（>0）
//用switch设置循环菜单形式 可多次进行调试
//类里面的信息用private 函数用public
#include <iostream>  //输入输出流头文件
#include "shape.h"  //导入头文件

using namespace std;
void startcircle();
void startrectangle();
void starttriangle();
int main()
{
    while (true)
    {
        int shape;
        cout << "please input shape: \n 1.circle 2.rectangle 3.triangle\n( input 0 quit)" << endl;
        cin >> shape;
        switch (shape)
        {
        case 1:startcircle(); break;
        case 2:startrectangle(); break;
        case 3:starttriangle(); break;
        default:return 0;
        }
        
    }
}
void startcircle()
{
    int a, b, r1;
    cout << "please input circle x1,y1,r;" << endl;//x1,y1为圆心坐标 r为半径
    cin >> a >> b >> r1;
    while (r1 < 0)
    {
        cout << "请输入正确的半径：（>0）" << endl;
        cin >> r1;
    }
    circle yuan;
    yuan.set(a, b, r1);
    double s;
    s = yuan.getarea();
    cout << "the circle s = " << s << endl;
    yuan.show();
}
void startrectangle()
{
    int x2, y2;
    cout << "please input rectangle x2,y2;" << endl;//x2,y2为长，宽
    cin >> x2 >> y2;
    while (x2 < 0 || y2 < 0)   //长宽都应该>0
    {
        cout << "重新输入长和宽(>0)" << endl;
        cin >> x2 >> y2;
    }
    rectangle rec;
    rec.set(x2, y2);
    double s;
    s = rec.getarea();
    cout << "the rectangle s = " << s << endl;
    rec.show();
}
void starttriangle() {
    int x31, y31, x32, y32, x33, y33;
    cout << "input 3 point location:\n1:";//输入三个顶点坐标
    cin >> x31 >> y31;
    cout << "2:";
    cin >> x32 >> y32;
    cout << "3:";
    cin >> x33 >> y33;
    triangle tri;
    tri.set(x31, y31, x32, y32, x33, y33);
    tri.show();
    double sq;
    sq = tri.getarea();
    cout << "the triangle s = " << sq << endl;
    
}