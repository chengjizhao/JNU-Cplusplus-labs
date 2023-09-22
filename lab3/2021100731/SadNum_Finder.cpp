#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring> 
#include <map> 
#include <list>

using namespace std;

int Num_Judge(int Num);

vector<int> sad_num_vec;    //存储忧伤数
int feedback;
int input;

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        feedback = Num_Judge(i);
        //cout << feedback << endl;
        if(feedback != 0)
        {
            sad_num_vec.push_back(feedback);
        }
    }

    //打印忧伤数
    int length = sad_num_vec.size();
    int cnt    = 0;
    for (int i = 0; i < length; i++)
    {
        cout << sad_num_vec[i] << ",";
        cnt++;
        if (cnt == 5)
        {
            cout << endl;
            cnt = 0;
        }
        
    }
    return 0;
}


/***************************************************
*函数名称：Num_Judge
*输入变量：int Num
*返回数值：0:不是   Num:是
*功能简介：判断输入的Num是否为忧伤数
***************************************************/
int Num_Judge(int Num)
{
    vector<int> digit_Num;
    string  strNum      = to_string(Num);
    int     length      = strNum.length();
    int     single_Num  = 0;
    int     sum         = 0;
    int     back        = 0;
    
    for (int i = 0; i < length; i++)
    {
        single_Num = strNum[i] - 48;
        sum += single_Num * single_Num;
    }

    if(to_string(sum).length() == 1)
    {
        //cout << sum << endl;
        if(sum == 1)
        {
            back = Num;
        }
        else
        {
            back = 0;
        }  
    }
    
    else
    {
        int a = Num_Judge(sum);
        if(a != 0)
        {
            back = Num;
        }
        else
        {
            back = 0;
        }
    }

    return back;
}
