#include "sales.h" //�����Զ���ͷ�ļ����ڴ��ļ����Ѿ�����iostream�����Դ˴����õ���

using namespace SALES;

int main()
{
    Sales sale1, sale2; //�������ݵĽṹ��
    double saleData1[4] = {44, 24, 16, 7}; //��ʼ��һ�����ֵ
    double saleData2[QUARTERS];
    setSales(sale1, saleData1, QUARTERS);
    showSales(sale1);
    setSales(sale2);
    showSales(sale2);
    return 0;
}
