#include<iostream>
#include<vector>
#include<list>
#include<chrono>  
#include<algorithm>
using namespace std;
vector<int> demo1(10000);
list<int> demo2;
int main() 
{
  int N ; // 插入元素的数量 
  cout<<"输入插入元素的数量"<<endl;
  cin>>N;
// 使用vector进行随机插入操作
       chrono::time_point< chrono::system_clock> start1, end1; // 定义时间点
       start1 =  chrono::system_clock::now(); // 获取当前时间点
    
    for(int i=0;i<N;i++)
    {
        int a=rand()%N;
        int b=rand()%N;
        demo1.insert(demo1.begin()+a,b);
    }

       end1 =  chrono::system_clock::now();
    
       chrono::duration<double,  milli> elapsed_time1 = end1 - start1;// 计算程序执行时间
       cout << "使用vector容器随机插入 " << N << "个元素所需时间：" << elapsed_time1.count() << " 毫秒" <<  endl;
       
// 使用list进行随机插入操作
       chrono::time_point< chrono::system_clock> start2, end2; // 定义时间点
       start2 =  chrono::system_clock::now(); // 获取当前时间点
       int a=rand()%N;
       list<int>::iterator b[N];
       for(int i=0;i<N;i++)
       {
        b[i] = find(demo2.begin(),demo2.end(),a);
    }
       
       for (int i =0; i < N; i++) 
 {
        int c=rand()%N;
        demo2.insert(b[i],c);
 }
        end2 =  chrono::system_clock::now();
    
        chrono::duration<double,  milli> elapsed_time2 = end2 - start2;// 计算程序执行时间
        cout << "使用list容器随机插入" << N << "个元素所需时间：" << elapsed_time2.count() << " 毫秒" <<  endl;
        return 0;
}
