#include <iostream>
#include<vector>
using namespace std;

int SadNumJudge(int n)
{
	while(n>9)//ѭ����nΪ��λ���������˳�ѭ������Ϊ�Ѿ��޷���� 
	{ 
	int a = n%10;//ȡ��λ�� 
    int b = n/10%10;//ȡʮλ�� 
    int c = n/100%10;//ȡ��λ�� 
    n = a*a+b*b+c*c;
    }
	return n; 
}

int main()
{
	cout << "�Ҹ�������" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (SadNumJudge(i)!=1)
            cout << i << " ";
    }
    cout << endl;

    cout << "���˵�����" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (SadNumJudge(i)==1)
            cout << i << " ";
    }
    cout << endl;

    return 0;
} 
