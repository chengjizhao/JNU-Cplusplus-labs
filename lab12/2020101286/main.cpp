#include <iostream>
#include "math/operations.h"

int main() 
{
    Operations op;
    int a = 10, b = 5;
    std::cout << "Addition: " << op.add(a, b) << std::endl;
    std::cout << "Subtraction: " << op.subtract(a, b) << std::endl;
    return 0;
}