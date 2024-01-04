#include "Sales.h"
#include <iostream>

using namespace SALES; 
using namespace std; 

int main() 
{ 
	Sales s1; 
	Sales s2; 
	s1.setSales({5000.0, 6000.0, 7000.0, 8000.0}); 
	s2.setSales(); 
	s1.showSales(); 
	s2.showSales(); 
	
	return 0; 
}