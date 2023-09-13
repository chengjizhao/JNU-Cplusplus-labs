#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <sstream>
using namespace std;

 
int main()  
{
    stringstream ss;
    ifstream ifs;
    string f[61];
    string g[61]={0};
    string c={0};
    string head ;
    char a1[61][50];
    int b[61]={0};
    int n[61]={0};
    int d=0;
    int k=0;
    int h=0;
    int l=0;
    int m=0;
    int x=0;
    ifs.open("student.csv", ios::in);
    if (ifs.is_open())//如果打开文件
	{
        getline(ifs,head);//下行一行
        for(int i=0;i<61;i++)// 给主值赋值
        {
        getline (ifs,f[i]);
        }
        int i=0;
        for(int i=0;i<61;i++)//给附加值赋值
    {
        ifs >> a1[i];
    }
        for(int i=0;i<61;i++)// 主值把学号给定int数组
        {
            b[i]=atoi(f[i].c_str());
            cout << b[i] << endl ;
        }
        for(int i=0;i<61;i++)// 调整附加值数据类型
    {
        for(int j=0,k=0;j<50;j++)
        {
            g[i]=g[i]+a1[i][j];
        }
        n[i]=atoi(g[i].c_str());
    }    
        cout << "请输入学号" ;
        cin >> d ;
        for(int i=0;i<61;i++)// 进行数据显示和编辑
        {
            if(d==b[i])//如果学号正确
            {
                cout << "该学生信息为" << f[i] << "," ;
                for(int j=0;j<61;j++)//如果附加值中含有该学生的学号，呈现附加值
                {
                    if(d==n[j])
                    {
                        cout << g[j] ;
                    }
                    if(j==60)
                    {
                        cout << endl ;
                    }
                }
                cout << "若输入成绩请按1 退出操作请按2 "<< endl ;//进行对成绩操作的选择
                cin >> h ;
                if(h==1)//进行成绩操作
                {
                    cout << "请输入成绩：" ;
                    cin >> c;
                    ofstream fout;
                    fout.open("student.csv",ios::out);
                    fout << head << endl ;
                    for(int j=0;j<61;j++)//输出现有数据
                    {
                        fout << f[j] << endl ;
                    }
                    for(int j=0;j<61;j++)
                    {
                        if(n[j]==d)
                        {
                            fout  << g[j] << "," << c << endl ;
                            x++;
                            for(int k=j;k<60;k++)
                            {
                                g[k]=g[j+1];
                            }
                        }
                    }
                    if(x==0)
                    {
                        fout << b[i] << "," << c << endl ;
                    }
                    for(int j=0;j<61;j++)
                    {
                        fout << g[j] ;
                        if(a1[j][0]!=0)
                        {
                                fout << endl ;
                        }
                    }
                }
                if(h==2) //进行成绩取消操作
                {
                    cout << "已退出" ;
                }
            }
            else//如果未能识别学号，k=k+1
            {
                 k++;
            }
            if(k>60)//如果k+1的次数达到数据总数，说明输入数据不在学号数组当中
            {
                cout << "该学生信息不存在" << endl ;
            }
        }
    }
    else//如果文件打不开显示打不开文件
    {
	cout << "failed to open the file" << endl;
    }
    ifs.close();
	return 0;
}