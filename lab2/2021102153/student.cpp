#include "student.h"
int main()
{
int c=0;
cout<<"选择功能"<< endl <<"1.根据学号查询所有内容"<< endl << "2.输入实验课成绩" << endl << "3.计算期末总成绩" << endl <<"0.结束" << endl;
scanf("%d",&c);
if(c==1)
{
    query();
    return main();
}
if(c==0)
{
    return 0;
}
if(c==2)
{
    enter();
    return main();
}
if(c==3)
{
  nalgrad();
  return main();
}
}


void query()//查询函数
{   
    char a[1000];
    cout<<"输入学号查询所有内容";
    scanf("%s",&a);
    ifstream ifs;
    ifs.open("text.csv", ios::in);
    string line;
    vector<string> words; //声明一个字符串向量
    string word;
    getline(ifs, line);
    istringstream sin;
if(!ifs.is_open())
{
    cout <<"文件打开失败";
    return ;
}
for(int i=0;i<100;i++)
{
char t[1000];
ifs.getline(t,1000);
ifs.getline(t,11,',');
if(strcmp(a, t) == 0)
{
cout << t;
ifs.getline(t,1000);
cout << t;
}
}
ifs.close();
}

void enter()
{
    char a[100];
    cout << "输入学号查找该同学";
    scanf("%s",&a);
   fstream fs;
   ifstream ifs;
   fs.open("text.csv",ios::out|ios::in|ios::binary);
   ifs.open("text.csv",ios::out|ios::in|ios::binary);
   if(!fs.is_open())
{
    cout <<"文件打开失败";
    return ;
}
char c[100];
for(int i=0;i<1000;i++)
{
   char t[10000];
   fs.getline(t,10000);
   fs.getline(t,100,',');
   if (strcmp(a, t) == 0)
{
cout << "输入这次实验课录入的成绩" ;
scanf("%s",&c);
fs.getline(t,10000);
fs.seekp(fs.tellg());
ifs.seekg(fs.tellg());
ifs.getline(t,1000000,'?');
fs.seekp(-2,ios::cur);
fs << c <<",,\n"<< t;
cout << "已经找到该同学并录入成绩" << endl;
fs.seekg(0,ios::beg);
fs.seekp(0,ios::beg);
ifs.seekg(0,ios::beg);
break;
}
else if(fs.eof())
{
    cout << "未找到该同学" << endl;
    return enter();
}
}
}

void nalgrad()
{
        fstream tfs;
        ifstream ifs;
        ofstream ofs;
        char l[100];
        cout << "输入学号计算总成绩(有十次成绩)" ;
        scanf("%s",&l);
    char t[10000]={0};
   tfs.open("text.csv",ios::out|ios::in|ios::binary);
   ifs.open("text.csv",ios::in|ios::binary);
   ofs.open("text.csv",ios::out|ios::in|ios::binary);
   tfs.seekg(0,ios::beg);
      tfs.getline(t,999);
    for(int p=0;p<1000;p++)
      {
        tfs.getline(t,999);
        tfs.getline(t,11,',');
      if(strcmp(l, t) == 0)
      {
      tfs.getline(t,999);
    char a[40][40]={0};
    int c=0;
    int u=0;
    int t1=0;
    int t2=0;
    int t3=0;
    for(int o=0;o<300;o++)
    {
      if(t[o]==',')
        {
          t1++;
     if(t1==9)
        {
          t2=o;
        }
     if(t1==20)
     {
      t3=o;
     }
    }
    }
      for(int i=t2;i<t3;i++)
      {

        if(t[i]>='0'&&'9'>=t[i]||t[i]==',')
        {

            if(t[i]==',')
            {
                u++;
                c=0;
            }
            else
            {
            a[u][c]=t[i];
            c++;
            }
        }
      }
      int w=0;
      for(int i=0;i<40;i++)
      {
        w=w+atoi(a[i]);
      }
ifs.seekg(tfs.tellg());
ofs.seekp(tfs.tellg());
ifs.getline(t,9999,'?');
tfs.seekp(-2,ios::cur);
if(w!=0||w>1000)
{
tfs << w <<",,\n"<< t;
cout << "成绩为" << w;
}
else{
  cout << "成绩未输入完全";
}
tfs.seekp(ofs.tellp());
      }
      if(tfs.eof())
      {
      tfs.close();
      ifs.close();
      }
      }
}