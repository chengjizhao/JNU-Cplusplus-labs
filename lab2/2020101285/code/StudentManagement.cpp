
#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<windows.h>

#include "FileOperation.h"

using namespace std;

int main()
{
    linkstudent H = new student;
    readFile(H);//把文件数据载入内存，方便后续读取

    cout<<"|************************************************************************|"<<endl;
    cout<<"|************           请输入序号选择功能           ********************|"<<endl;

    while (true)
    {
        cout<<"|************************************************************************|"<<endl;
        cout<<"|************          1.按学号查询学生成绩          ********************|"<<endl;
        cout<<"|************      2.按学号录入/更新某次实验课成绩   ********************|"<<endl;
        cout<<"|************            3.计算更新最终成绩          ********************|"<<endl;
        cout<<"|************         4.打印输出所有学生的信息       ********************|"<<endl;
        cout<<"|************               5.退出                   ********************|"<<endl;
        cout<<"|************************************************************************|"<<endl;        
        id_t number=0;
        cout << "input >";
        cin>>number;
        switch (number){
            case 1:
            {
                id_t id;
                score_t temp[LABNUM+1];
                cout << "您选择了按学号查询学生成绩，请输入你想查询学生的学号"<<endl<<"input >";
                cin >> id;
                if(!viewScore(H,id,temp)){
                    int i = 0;
                    for (; i < LABNUM; i++)
                    {
                        cout<<"实验课"<<i+1<<"成绩："<<temp[i]<<endl;
                    }
                    cout<<"最终成绩："<<temp[i]<<endl;
                    cout << "查询成功,请重新选择功能"<<endl; 
                }else{
                    cout<<"查询失败！请重新选择功能"<<endl;
                }       
                break;
            }

            case 2:
            {
                id_t id;
                int courseNum;
                score_t score;
                cout << "您选择了按学号录入/更新某次实验课成绩，请输入学生的学号"<<endl<<"input >";
                cin >> id;
                cout << "请输入您想录入第几次实验课(1~18)"<<endl<<"input >";
                cin >> courseNum;
                cout << "请输入分数"<<endl<<"input >";
                cin >> score;
                if(!writelabScore(id,courseNum,score)){
                    readFile(H);//写入文件后需要重新读入内存
                    cout << "录入成功,请重新选择功能"<<endl;
                }else{
                    cout << "操作失败,请重新选择功能"<<endl;
                }
                break;
            }

            case 3:
            {
                calculateScore(H);
                cout << "更新成功,请重新选择功能"<<endl;
                break;
            }

            case 4:
            {
                if (!viewAll())
                {                
                    cout << "打印成功,请重新选择功能"<<endl;
                }else{
                    cout << "打印失败,请重新选择功能"<<endl;
                }
                break;
            }

            case 5:
            {
                linkstudent p=H->Next;
                delete H;
                while (p!=NULL)
                {
                    linkstudent q = p;
                    p=p->Next;
                    delete []q->labScore;
                    delete q;
                }             
                exit(0);
                break;
            }    
            default:
                cout<<"请输入正确的序号！"<<endl;
                break;            
        }    
    }
    return 0;
}