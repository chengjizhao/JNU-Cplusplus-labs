#include <iostream>
using namespace std;
 
int main(void)
{
    // allocating memory to p
    int* p = (int*)malloc(sizeof(int));
 
    *p = 100;
 
    // deallocated the space allocated to p
    free(p);
 
    //  segmentation fault
    //  as now this statement is illegal
    *p = 110;
 
    return 0;
}