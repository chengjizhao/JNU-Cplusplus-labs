#ifndef HEAD_H_
#define HEAD_H_

namespace SALES 
{ 
    const int QUARTERS =4;
    struct Sales 
    {
    double sales[QUARTERS];
    double max;
    double min;
    double average;
    }; 
} 

#endif
