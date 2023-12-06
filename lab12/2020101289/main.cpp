#include <iostream>
#include "mathplus.h"

int main() 
{
    Mathplus op;
    
    int a = 10, b = 5;

    std::cout << "Addition: " << op.add(a, b) << std::endl;
    std::cout << "Subtraction: " << op.subtract(a, b) << std::endl;
    std::cout << "Multiply: " << op.multiply(a,b) << std::endl;
    std::cout << "Devide: " << op.devide(a,b) << std::endl;

    return 0;
}