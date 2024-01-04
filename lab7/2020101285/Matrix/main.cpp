#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
    std::vector<std::vector<int>> matrixAData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrixBData = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix matrixA(matrixAData);
    Matrix matrixB(matrixBData);

    Matrix matrixC = matrixA + matrixB;
    Matrix matrixD = matrixA - matrixB;
    Matrix matrixE = matrixA * matrixB;

    std::cout << "Matrix A:" << std::endl;
    std::cout << matrixA << std::endl;

    std::cout << "Matrix B:" << std::endl;
    std::cout << matrixB << std::endl;

    std::cout << "Matrix C (A + B):" << std::endl;
    std::cout << matrixC << std::endl;

    std::cout << "Matrix D (A - B):" << std::endl;
    std::cout << matrixD << std::endl;

    std::cout << "Matrix E (A * B):" << std::endl;
    std::cout << matrixE << std::endl;

    return 0;
}