#include"Person.h"
#include"Person.cpp"
#include<iostream>
using namespace std;
int main()
{
    string name, id, birthdate, gender;
    double height, weight;
    cout << "name:";
    cin >> name;
    cout << "id:";
    cin >> id;
    cout << "birthdate:";
    cin >> birthdate;
    cout << "gender:";
    cin >> gender;
    cout << "height:";
    cin >> height;
    cout << "weight:";
    cin >> weight;
    cout << endl;
    Person per0 ;//ʹ��Ĭ�Ϲ��캯����������
    Person per1(name) ;//ʹ�õ�һ�����Ĺ��캯����������
    per1.set_information( id, birthdate, gender, height, weight) ;//������������
    Person per2( name, id, birthdate, gender, height, weight) ;//ʹ�ö�����Ĺ��캯����������
    cout<<"per1"<<endl;
    per1.show() ;
    cout<<"per2"<<endl;
    per2.show() ;
    //��ӡÿ������ռ�õĴ洢�ռ�
    cout << "per0 ռ�ô洢�ռ�: " << sizeof(per0) << "�ֽ�" << endl;
    cout << "per1 ռ�ô洢�ռ�: " << sizeof(per1) << "�ֽ�" << endl;
    cout << "per2 ռ�ô洢�ռ�: " << sizeof(per2) << "�ֽ�" << endl;
    return 0;
}
// ��Ĵ�С�ڱ���ʱȷ�����������Ա���������ͼ�����ȷ��
// name��id��birthdate��genderΪstring���ͣ�ÿ��ռ��32���ֽڣ�height��weightΪdouble���ͣ�ÿ��ռ��8���ֽ�
// �ܹ�ռ��144���ֽ�