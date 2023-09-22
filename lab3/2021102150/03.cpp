#include<iostream>
using namespace std;
int sad[10000];

int judge(int x){
    if(x==1)return 1;//如果x=1则返回1，表示该数为忧伤的数
    if(sad[x]==-2)return 0;//若x已在先前遍历过，说明陷入循环，此时返回0，表示该数及其前置数都为幸福的数
    sad[x]=-2;//打上标记，表示x已搜索过

    int b[10],i=0,xx=x,add=0;//将数拆分成单个数字
    while(x){
        b[i++]=(x%10);
        x/=10;
    }
    for(int j=0;j<i;j++){//计算m
        add+=b[j]*b[j];
    }

    sad[xx]=judge(add);//深度优先搜索，判断m是否为忧伤的数
    return sad[xx];//返回
}

int main(){
    for(int i=0;i<1000;i++)sad[i]=-1;
    sad[1]=1;
    for(int i=1;i<=1000;i++){
        if(sad[i]==-1)judge(i);
    }
    cout<<"忧伤的数："<<" ";
    for(int i=1;i<=1000;i++){
        if(sad[i])cout<<i<<" ";
    }
    cout<<endl<<endl;
    cout<<"幸福的数: ";
    for(int i=1;i<=1000;i++){
        if(!sad[i])cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}