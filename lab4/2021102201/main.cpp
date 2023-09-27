#include "sales.h" //调用自定义头文件，在此文件中已经调用iostream了所以此处不用调用

using namespace SALES;

int main()
{
    Sales sale1, sale2; //两组数据的结构体
    double saleData1[4] = {44, 24, 16, 7}; //初始化一组的数值
    double saleData2[QUARTERS];
    setSales(sale1, saleData1, QUARTERS);
    showSales(sale1);
    setSales(sale2);
    showSales(sale2);
    return 0;
}
