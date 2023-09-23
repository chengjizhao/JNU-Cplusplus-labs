     1.   C++ Primer Plus （5-9章）阅读并总结关键语法点
     2.   总结 external， static， 和namespace 的关系
     3.   创建一个由三个文件构成的程序，使用以下namespace
          namespace SALES 
          { 
            const int QUARTERS =4;
             struct Sales {
             doubles sales[QUARTERS];
             double max；
             double min;
             double average;
             };
             void setSales(Sales &s, const double ar[], int n);
             void setSales(Sales &s);
             void showSales(const Sales& s);
          } 
        要求实现头文件和实现文件的分离，在单独的文件创建2个Sales 对象，并用第一个setSales 设置他们的销售业绩。
        setSales  ar 这个数组中存有n个销售业绩数据，从其中选出不多于4个业绩放入 s 中，并计算其平均，最高，最低
        销售业绩数据，存入s 中，第二个setSales ,   交互式输入4个季度的销售业绩，存入数组，并计算其平均，最低，最高。
