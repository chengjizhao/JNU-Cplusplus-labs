#include <iostream>

using namespace std;

class Base 
{
public:
	virtual void a() { cout << "a()" << endl; }
	virtual void b() { cout << "b()" << endl; }
  void(*fp)=nullptr;
};
class Devired :public Base
{
public:
  
  virtual void b() { cout << "Derive::b()" << endl;//��д�麯��
  }
};
class Devired2 : public Base
{

};
int main() 
{
	
 //ͬһ�಻ͬ����ָ��ͬһ�����
 
  Base x1;
  Base x2;
  void(Base::*fp1)()=&Base::a;
  void(Base::*fp2)()=&Base::b;
  
  //û�и��Ǻ�����������麯����ַ
  Devired s1;
  void(Devired::*fp3)()=&Devired::a;
  //�����˵ڶ���������������麯����ַ
  void(Devired::*fp4)()=&Devired::b;
  cout << "x1�麯�����ַ��" << (void*)(&x1) << endl;//�������1�麯�����ַ
  cout << "x2�麯�����ַ��" << (void*)(&x2) << endl;//�������1�麯�����ַ
  cout << "x1�麯�����һ���麯��ָ���ַ��" <<reinterpret_cast<void*>(x1.*fp1) << endl;
  cout << "x2�麯����ڶ����麯��ָ���ַ��" <<reinterpret_cast<void*>(x1.*fp2) << endl;
  cout << "x1�麯�����һ���麯��ָ���ַ��" <<reinterpret_cast<void*>(x2.*fp1) << endl;
  cout << "x2�麯����ڶ����麯��ָ���ַ��" <<reinterpret_cast<void*>(x2.*fp2) << endl;
  cout << "��������麯��1��ַ" <<reinterpret_cast<void*>(s1.*fp3) << endl;
  cout << "��������麯��2��ַ" <<reinterpret_cast<void*>(s1.*fp4) << endl;
	return 0;
}
/*ÿһ���඼��һ���麯�����洢������������麯������ڵ�ַ��ͬһ�������������������麯����
��һ�����󱻴���ʱ���������ڴ��з���һ��ռ����ڴ洢�������ݺ�ָ���麯�����ָ�롣���ָ��ʼ��ָ�������麯����������Ϊ����Ĳ�ͬ���ı䡣
�����������д�˻�����麯������ô������������Լ����麯�����д洢��д��ĺ�����ַ�����������û����д������麯������ô����̳л�����麯����ַ�������临�Ƶ��Լ����麯�����С�
*/

