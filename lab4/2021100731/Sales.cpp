#include "header.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    SALES::Sales Sale_Person_1;
    SALES::Sales Sale_Person_2;
    SALES::Sales* pPerson;
    int nKPInum;

    while(1)
    {
        int nPersonNo = 1;
        int nOperate  = 1;

        cout << "请输入要处理的员工编号(1或2)" << endl;
        cin >> nPersonNo;
        if(nPersonNo == 1)
        {
            pPerson = &Sale_Person_1;
        }
        else if(nPersonNo == 2)
        {
            pPerson = &Sale_Person_2;
        }

        cout << "请输入要执行的操作(1:写入数据(方法一)  2:写入数据(方法二))" << endl;
        cin >> nOperate;

        if(nOperate == 1)
        {
            cout << "请输入业绩个数(不少于4个)" << endl;
            cin >> nKPInum;

            if(nKPInum >= 4 )
            {
                double KPI[nKPInum];

                cout << "请输入业绩(不少于4个,空格隔开)" << endl;
                for(int i=0; i<nKPInum; i++)
                {
                    cin >> KPI[i];
                }

                setSales(pPerson, KPI, nKPInum);
                showSales(pPerson); 
            }
            else
            {
                cout << "非法的业绩数量！" << endl;
            }    
        }

        else if(nOperate == 2)
        {
            cout << "请输入四个业绩" << endl;
            setSales(pPerson);
            showSales(pPerson); 
        }
        
    }

    return 0;
}
