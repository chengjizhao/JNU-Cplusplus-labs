#include <iostream>
using namespace std;

int SadNumJudge(int n)
{
	while(n>9)//循环至n为个位数，即可退出循环，因为已经无法拆分 
	{ 
	int a = n%10;//取个位数 
	int b = n/10%10;//取十位数 
	int c = n/100%10;//取百位数 
	int d = n/1000%10;//取千位数 
    	n = a*a+b*b+c*c+d*d;
	}
	return n; 
}

int main()
{
	cout << "幸福的数：" << endl;
	for (int i = 1; i <= 1000; i++) {
        if (SadNumJudge(i)!=1)cout << i << " ";
    	}

    	cout << "\n忧伤的数：" << endl;
    	for (int i = 1; i <= 1000; i++) {
        if (SadNumJudge(i)==1)cout << i << " ";
    	}
    	cout << endl;
    	return 0;
} 
