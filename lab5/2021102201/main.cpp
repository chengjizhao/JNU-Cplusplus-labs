#include <iostream>
#include "person.h"

int main() {
    //Ĭ�Ϲ��캯���� person ����
    Person person1;
    std::cout << "person1 ռ�õĴ洢�ռ��ǣ�" << sizeof(person1) << " �ֽ�" << std::endl;

    //�������Ĺ��캯���� person ����
    Person person2("����", "123456789012345678", "2000-01-01", "��", 180.0, 70.0);
    std::cout << "person2 ռ�õĴ洢�ռ��ǣ�" << sizeof(person2) << " �ֽ�" << std::endl;

    //�������캯���� person ����
    Person person3 = person2;
    std::cout << "person3 ռ�õĴ洢�ռ��ǣ�" << sizeof(person3) << " �ֽ�" << std::endl;

    return 0;
}
/*
ÿ��Person����ռ�õĴ洢�ռ���128�ֽڡ�
����double����ռ��8���ֽڣ�std::string����ռ��28���ֽڣ�ָ��ռ�� 8 ���ֽڡ�
������ռ�õ��ֽ�������128��
*/