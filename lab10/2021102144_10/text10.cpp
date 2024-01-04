#include<iostream>
using namespace std;
typedef void(*FUNC)();
class normalClass
{
    public:
    int normal;
    int n1;
};
class VBClass:virtual public normalClass
{
    public:
    int vb;
};
class VFClass
{
    public:
    virtual void func1(){cout<<"VFClass fun1"<<endl;}
    int VF;
    int VF1;
};
class VFClass1
{
    public:
    virtual void func2(){cout<<"VFClass1 fun2"<<endl;}
    int VFa;
    int VFa1;
};
class MClass:public VFClass,public VFClass1
{
    public:
    int mc;
    virtual void func3(){cout<<"MClass fun3"<<endl;}
};
class VFSClass:public VFClass
{
    public:
    int VFS;
};
class VFSHClass:public VFClass
{
    public:
    virtual void func1(){cout<<"VFSHClass fun1"<<endl;}
    virtual void func2(){cout<<"VFSHClass fun2"<<endl;}
    virtual void func3(){cout<<"VFSHClass fun3"<<endl;}
    int VFSH;
};
class sonClass:public normalClass
{
    public:
    int son;
    int son1;
};
int main()
{
    normalClass nC;
    cout<<"一般类对象："<<endl;
    cout<<"成员地址"<<endl;
    cout<<&nC.normal<<endl;
    cout<<&nC.n1<<endl;
    //顺序排列
    sonClass sC;
    cout<<endl<<endl;
    cout<<"继承类对象："<<endl;
    cout<<"成员地址"<<endl;
    cout<<&sC.normal<<endl;
    cout<<&sC.n1<<endl;
    cout<<&sC.son<<endl;
    cout<<&sC.son1<<endl;
    //先排列父类
    VFClass vfC;
    VFClass *v=new VFClass();
    auto*tmp =(long long *)v;
    auto*vptr = (long long*)(*tmp);
    cout<<endl<<endl;
    cout<<"有虚函数的类对象："<<endl;
    cout<<"虚函数表地址"<<endl;
    cout<<vptr<< endl;
    cout<<"成员地址"<<endl;
    cout<<&vfC.VF<<endl;
    cout<<&vfC.VF1<<endl;    
    delete v;
    VFSClass vfsC;
    cout<<endl<<endl;
    cout<<"父类有虚函数的子类对象："<<endl;
    VFClass *v1=new VFSClass();
    auto*tmp1 =(long long *)v1;
    auto*vptr1 = (long long*)(*tmp1);
    cout<<"虚函数表地址"<<endl;
    cout<<vptr1<< endl;
    //FUNC func1=(FUNC)*vptr;
    //func1();
    cout<<"成员地址"<<endl;
    cout<<&vfsC.VF<<endl;
    cout<<&vfsC.VF1<<endl;
    cout<<&vfsC.VFS<<endl;
    VFSHClass vfshC;
    cout<<endl<<endl;
    cout<<"父类有虚函数且子类拥有更多的虚函数类对象："<<endl;
    VFClass *v2=new VFSHClass();
    auto*tmp2=(long long *)v2;
    auto*vptr2= (long long*)(*tmp2);
    cout<<"虚函数表地址"<<endl;
    cout<<vptr2<< endl;
    cout<<"验证虚函数表如何排列："<<endl;
    FUNC func1=(FUNC)*vptr2;
    func1();
    FUNC func2=(FUNC)*(vptr2+1);
    func2();
    FUNC func3=(FUNC)*(vptr2+2);
    func3();
    cout<<"成员地址"<<endl;
    cout<<&vfshC.VF<<endl;
    cout<<&vfshC.VF1<<endl;
    cout<<&vfshC.VFSH<<endl;
    MClass mC;
    cout<<endl<<endl;
    cout<<"多继承的类对象："<<endl;
    VFClass *v3=new MClass();
    auto*tmp3=(long long *)v3;
    auto*vptr3= (long long*)(*tmp3);
    cout<<"第一个虚函数表地址"<<endl;
    cout<<vptr3<< endl;
    VFClass1 *v4=new MClass();
    auto*tmp4=(long long *)v4;
    auto*vptr4= (long long*)(*tmp4);
    cout<<"第二个虚函数表地址"<<endl;
    cout<<vptr4<< endl;
    cout<<"验证虚函数表如何排列："<<endl;
    FUNC funcm1=(FUNC)*vptr3;
    funcm1();
    FUNC funcm2=(FUNC)*vptr4;
    funcm2();
    FUNC funcm3=(FUNC)*(vptr3+1);
    funcm3();
    cout<<"成员地址"<<endl;
    cout<<&mC.VF<<endl;
    cout<<&mC.VF1<<endl;
    cout<<&mC.mc<<endl;
    cout<<endl<<endl;
    cout<<"虚基类的类对象："<<endl;
    VBClass VbC;
    cout<<"成员地址"<<endl;
    cout<<&VbC.normal<<endl;
    cout<<&VbC.n1<<endl;
    cout<<&VbC.vb<<endl;
    return 0;
}