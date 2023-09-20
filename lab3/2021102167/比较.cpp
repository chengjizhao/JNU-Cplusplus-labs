#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>  
#include <iterator>
#include<algorithm>
using  namespace std;


int getRand(int min, int max) 
{
    return ( rand() % (max - min + 1) ) + min ;
}


int main() 
{
 	std::vector<int> vctr(10000);
	std::list<int> lst;
 	
    srand(time(0));
 	
 	double dur1,dur2; 
    	clock_t start,end;
    	start = clock();
    	
    	for (int i=0; i<10000; i++)
    {
    	 
        int ple = getRand(1,10000)%10000;
		int crz = getRand(1,10000)%10000;
    	vctr.insert(vctr.begin()+ple,crz);
    
    
    }
 		end = clock();
		dur1 = (double)(end - start);
    	printf("use time:%f\n",(dur1/CLOCKS_PER_SEC));
    
	
	
		
		list<int>::iterator s[10000];	
    	
    	for (int i=0;i<10000;i++)
    {		
    	int ple1 = getRand(1,10000)%10000;
    	s[i] = find(lst.begin(),lst.end(),ple1);
	}	
    	start = clock();
		for (int i=0; i<10000; i++)
    {
		int crz1 = getRand(1,10000);
		int ple2 = getRand(1,10000);
		lst.insert(s[i],crz1); 
    }
		end = clock();
		dur2 = (double)(end - start);
    	printf("ues time:%f\n",(dur2/CLOCKS_PER_SEC));
	return 0;
}
 


