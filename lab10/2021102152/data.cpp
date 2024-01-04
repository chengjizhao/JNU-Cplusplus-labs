#include <iostream>

using namespace std;
//һ������� 
class C1
{
public:
    int getC1() { return C1data1; } 
    int C1data1;  //4
    int C1data2;  //4
private:
    
    int C1data3;  //4
}; 
//�̳������ 
class C2 : public C1
{
    public:
        int getC2() { return C2data1; } 
        int C2data1; 
    private:
        int C2data2;
        int C2data3; 
}; 
//���麯���������
class C3
{
    public:
    virtual void func(){}
    virtual void getC3(){}
    int C3data1;
    private:
    int C3data2;
};
//�������麯�����������
class C4 : public C3
{
    public:
    virtual void func1(){}
    int C4data1;
    private:
    int C4data2;
};
//�������麯�����������Լ��ĸ�����麯���������
class C5 : public C3
{
    public:
    virtual void func(){}//��д�����麯��func()
    virtual void func1(){}
    virtual void func2(){}
    int C5data1;
    private:
    int C5data2;
};
//��̳е������
class C6 : public C1 , public C3
{
    public:
    int C6data1;
    private:
    int C6data2;
};
//�����������
class C7 : virtual public C3
{   
    public:
    virtual void func1(){}
    int C7data1;
    private:
    int C7data2;
};
int main()
{
    C1 c1;
    C2 c2;
    C3 c3;
    C4 c4;//������麯�����У��ȴ�Ż�����麯�����ڴ�������Լ����麯����
    C5 c5;//�����������˸�����麯������������Ὣ�����麯�����ж�Ӧ�ĸ�����麯���滻������ĺ�����
    C6 c6;
    C7 c7;
    //һ������󣺶����ַ���ױ�����ַһ��
    cout <<"size c1 ="<< sizeof(c1) << endl;//һ��int����ռ�ĸ��ֽڣ�����������һ��������int���͵ĳ�Ա������4*3=12
    cout <<"address c1 ="<< &c1 << endl;
    cout <<"address C1data1 ="<< &c1.C1data1 << endl;
    cout <<"address C1data2 ="<< &c1.C1data2 << endl; 
    //�̳�����󣺶����ַ�ͻ����ױ�����ַһ�£����������ַλ�ڻ��������ַ����
    cout <<"size c2 ="<< sizeof(c2) << endl;//�������������int���͵ĳ�Ա����������������������int���ͺ��Լ�������int���ͣ�4*3+12=24
    cout <<"address c2 ="<< &c2 <<endl;
    cout <<"address C1data1 ="<< &c2.C1data1 <<endl;
    cout <<"address C2data1 ="<< &c2.C2data1 <<endl;
    //���麯����������׵�ַ�Ƕ���ָ��ָ���麯����ָ��vptr
    cout <<"size c3 ="<< sizeof(c3) << endl;
    cout <<"address c3 ="<< &c3 <<endl;
    //�������ÿ�����󣬱���������Ϊ������һ���麯����ָ�룬λ�ڸö����ڴ��еĿ�ͷ����ָ�����麯�����λ�á�
	//&c3�õ�����c3���׵�ַ��ǿ��ת��Ϊ(int *)����Ϊ����&c3��ʼ��4���ֽڿ���һ�����壬��&c3�������4�ֽ�������׵�ַ��Ҳ�������ָ�롣
    cout <<"address vTable ="<< (int *)(&c3) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c3) << endl;
    //�������麯�����������:���������麯�������������麯����Ȼ����������麯��
    cout <<"size c4 ="<< sizeof(c4) << endl;
    cout <<"address c4 =" << &c4 <<endl;
    cout <<"address vTable ="<< (int *)(&c4) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c4) << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c4)+1 << endl;
    //�������麯�����������Լ��ĸ�����麯������������������麯���������д������麯����Ȼ����������麯��
    cout <<"size c5 ="<< sizeof(c5) << endl;
    cout <<"address c5 ="<< &c5 << endl;
    cout <<"address vTable ="<< (int *)(&c5) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c5) << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c5)+1 << endl;
    //��̳е������
    cout <<"size c6 ="<< sizeof(c6) << endl;
    cout <<"address c6 ="<< &c6 << endl;
    cout <<"address vTable ="<< (int *)(&c6) << endl;
    cout <<"address C1data1 ="<< &c6.C1data1 << endl;
    cout <<"address C3data1 ="<< &c6.C3data1 << endl;
    cout <<"address C6data1 ="<< &c6.C6data1 << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c6) << endl;
    //�����������:����̳е�������ڴ�ṹ������ͨ�̳���ȫ��ͬ��
    //����̳е����࣬�е������麯���� ����Ҳ��������һ�ݸ�����麯����������֮����һ���ĸ��ֽڵ�0x00000000����Ϊ�ֽ硣
    //������ڴ��У��������Լ����麯����Ȼ������������ݳ�Ա��Ȼ����0x0��֮����Ǹ�����麯����֮���Ǹ�������ݳ�Ա��
    //�������û���Լ����麯������ô����Ͳ������麯���������������ݺ͸�������֮�䣬������Ҫ0x0�������
    //��ˣ�������̳��У�����͸�������ݣ�����ȫ����ģ��ȴ�������Լ����麯��������ݣ��м���0x�ֽ磬��󱣴游����麯�������ݡ�
    //������������˸�����麯������ô�������ڴ��и����麯�������Ӧ�����滻��
    cout <<"size c7 ="<< sizeof(c7) << endl;
    cout <<"address c7 ="<< &c7 << endl;
    cout <<"address vTable ="<< (int *)(&c7) << endl; 
    cout <<"address C3data1 ="<< &c7.C3data1 << endl;
    cout <<"address C7data1 ="<< &c7.C7data1 << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c7) << endl;
    
}
/*C++���Ա�еĳ�Ա�����ͳ�Ա�����Ƿֿ��洢��
ͬһ���еĴ洢λ��Ҳ�в��
��ͨ��Ա������
�洢����Ķ����У���ṹ��struct��������ͬ���ڴ�ֲ����ֽڶ��뷽ʽ
��̬��Ա������
�洢��ȫ������������
��Ա������
�洢�ڴ���ε���
*/