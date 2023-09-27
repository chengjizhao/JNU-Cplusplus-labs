#include "sales.h"  
#include <iostream>  
#include <cstdlib>  
#include <ctime>  
  
using namespace SALES;  
  
int main() {  
    srand(time(nullptr)); // 用于生成随机数的种子，以当前时间作为参数。  
    double ar[QUARTERS]; // 用于存储随机生成的销售业绩数据。  
    for (int i = 0; i < QUARTERS; ++i) {  
        ar[i] = static_cast<double>(rand()) / RAND_MAX; // 生成0到1之间的随机数。  
    }  
    Sales s1, s2; // 创建两个Sales对象。  
    setSales(s1, ar, QUARTERS); // 使用数组ar中的销售业绩数据设置s1。  
    setSales(s2); // 交互式输入销售业绩数据设置s2。  
    showSales(s1); // 显示s1的销售业绩数据。  
    showSales(s2); // 显示s2的销售业绩数据。  
    return 0;  
}