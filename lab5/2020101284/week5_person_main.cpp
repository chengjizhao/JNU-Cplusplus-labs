#include <iostream>
#include "person.h"

int main() {
    Person person1;  // ʹ��Ĭ�Ϲ��캯��
    person1.name = "John Doe";

    Person person2("Alice Smith");  // ʹ�ô������ֲ����Ĺ��캯��

    Person person3("Bob Johnson", "1234567890", "2001-01-01", "Male", 180.0, 75.5);

    std::cout << "Size of person1 object: " << sizeof(person1) << " bytes" << std::endl;
    std::cout << "Size of person2 object: " << sizeof(person2) << " bytes" << std::endl;
    std::cout << "Size of person3 object: " << sizeof(person3) << " bytes" << std::endl;

    return 0;
}
/*����ĳߴ�Ϊ176�ֽڡ�������Ϊ�ڴ�����������У���Ĵ�Сͨ���ܶ��������Ӱ�졣����������У����ܻᷢ�����¶������䣺

std::string ���͵ĳ�Ա������ռ��һ���Ĵ洢�ռ䣬����ָ��ָ��̬������ַ������ݡ�����ܻᵼ�¶������䣬ʹ��ÿ�� std::string ��Ա����ռ�õĴ洢�ռ䳬����ʵ�ʴ洢���ַ������ȡ�
double ���͵ĳ�Ա����ͨ����Ҫ���뵽 8 �ֽڱ߽磬���������˶���Ŀռ����ܴ洢��
����Ĵ�Сͨ���ᱻ���뵽ĳ���ϴ�ı߽磬�Ա��ڷ��ʺʹ���
��ˣ����� Person ��ĳ�Ա������ʵ�ʴ�С����С�� 40 �ֽڣ������ڶ��������ԭ�򣬶���ĳߴ��Ϊ 176 �ֽڡ�*/