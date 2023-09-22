#include <iostream>
#include <vector> 
#include<algorithm>
#include<ostream>
#include <iterator>

using namespace std;

vector<int>sadnum;
vector<int>hapnum;
int judge(int x1)
{	
		int a,b,c,m,x;
		x = x1;
		for(int i=1;i<1000;++i)
		{
		a = x/100;
		b = (x - a*100)/10;
		c = (x-a*100-b*10);
		m=a*a+b*b+c*c;
		
		if(m==1)
			{
				sadnum.push_back(x1);
				return 0;
			}
		x = m;
		}
		hapnum.push_back(x1);
		return 0;
}
 int main()
 {
 	int i;
 	for(int y = 1;y<1000;++y)
 	{	
	 judge(y); 		
	}
	for(int i = 0; i < sadnum.size(); ++i) 
    {
       cout << sadnum[i]<<" ";
    }
 	return 0;
 }
