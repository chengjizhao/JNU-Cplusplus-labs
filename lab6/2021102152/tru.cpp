
#include<iostream>
using namespace std;
class Tru;//������Tru
typedef void (Tru::*Refer)();//����һ��ָ��Tru���ຯ��Refer()��ָ�� 
Refer fun1;//fun1ָ��
class Tru
{
    public:
    Tru() //����һ�����캯��
    {
        fun1=&Tru::out_pr1;////ʹ��fun1ָ��������private��Ա
    }
    void fun2()
    {
        out_pr1();//ͨ�����public��Ա��������private��Ա����
    }
    
    private:
    void out_pr1()
    {
        cout<<"private.out_pr1"<<endl;
    }
    static void out_pr2()
    {
        cout<<"private.out_pr2"<<endl;
    }
    friend void fun3(); //fun3()��Ϊ��Tru����Ԫ����
   
};
void fun3()
{
    Tru::out_pr2();//ͨ�������Ԫ�������ø����private��Ա����,�ó�Ա����������Ϊstatic
}


int main()
{
    Tru func;
    (func.*fun1)();
    func.fun2();
    fun3();
    return 0;

}