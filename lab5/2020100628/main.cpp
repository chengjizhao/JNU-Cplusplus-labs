#include "person.h"
#include <iostream>
using namespace std;

int main()
{
    string name, id, bd, gender;
    double h, w;
    cout << "������";
    cin >> name;
    cout << "���֤�ţ�";
    cin >> id;
    cout << "���գ�";
    cin >> bd;
    cout << "�Ա�";
    cin >> gender;
    cout << "��ߣ�";
    cin >> h;
    cout << "���أ�";
    cin >> w;

    // ʹ��Ĭ�Ϲ��캯����������
    Person p1;
    cout << "p1 �Ĵ�С��" << sizeof(p1) << " �ֽ�" << endl;

    // ʹ�ô������Ĺ��캯����������
    Person p2(name);
    cout << "p2 �Ĵ�С��" << sizeof(p2) << " �ֽ�" << endl;

    // ʹ�����ú���������������
    p2.setID(id);
    p2.setBirthday(bd);
    p2.setGender(gender);
    p2.setHeight(h);
    p2.setWeight(w);

    // ��ӡ��������
    cout << "p2 ��������" << p2.name << endl;
    cout << "p2 �����֤�ţ�" << p2.getID() << endl;
    cout << "p2 �ĳ������ڣ�" << p2.getBirthday() << endl;
    cout << "p2 ���Ա�" << p2.getGender() << endl;
    cout << "p2 ����ߣ�" << p2.getHeight() << endl;
    cout << "p2 �����أ�" << p2.getWeight() << endl;

    return 0;
}

// ��Ĵ�С�ڱ���ʱȷ�����������Ա���������ͼ�����ȷ��
// name��pid��pbd��pgΪstring���ͣ�ÿ��ռ��32���ֽ�
// ph��pwΪdouble���ͣ�ÿ��ռ��8���ֽ�
// �ܹ�Ϊ144���ֽ�
// p1��p2�ڴ��������ʱ���Ա�����ᴴ����p1�г�Ա����û�и�ֵ�������ǻ�ռ�ÿռ�