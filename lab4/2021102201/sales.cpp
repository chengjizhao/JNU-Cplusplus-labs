#include "sales.h"
#include <iostream>

namespace SALES
{
    using namespace std;

    void setSales(Sales& s, const double ar[], int n)
    {
        //�ֱ����ñ�����ֵ�������ĵط�
        s.max = ar[0];
        s.min = ar[0];
        double sum = 0;
        //�����Լ����������ҳ���ֵ��������ƽ����
        for (int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] > s.max) s.max = ar[i];
            if (ar[i] < s.min) s.min = ar[i];
        }
        s.average = sum / QUARTERS;
    }

    void setSales(Sales& s)
    {
        double ar[QUARTERS];
        cout << "������" << QUARTERS << "λ���۵�����: ";
        //�����������������
        for (int i = 0; i < QUARTERS; i++) cin >> ar[i];
        setSales(s, ar, QUARTERS);
    }

    void showSales(const Sales& s)
    {
        //����������ݵ���Ļ
        cout << QUARTERS << "λ���۵������ֱ�Ϊ��";
        for (int i = 0; i < QUARTERS; i++) cout << s.sales[i] << " ";
        cout << endl << "�������Ϊ��" << s.max;
        cout << endl << "��������Ϊ��" << s.min;
        cout << endl << "ƽ������Ϊ��" << s.average << endl;
    }
}