#include <iostream>
#include <vector>

class Matrix {
private:
 std::vector<std::vector<int>> data;
 int rows;
 int cols;

public:
 Matrix(int rows, int cols) : rows(rows), cols(cols) {
 data.resize(rows, std::vector<int>(cols,0));
 }

 Matrix operator+(const Matrix& other) const {
 if (rows != other.rows || cols != other.cols) {
 throw std::invalid_argument("Matrix dimensions do not match");
 }

 Matrix result(rows, cols);

 for (int i =0; i < rows; i++) {
 for (int j =0; j < cols; j++) {
 result.data[i][j] = data[i][j] + other.data[i][j];
 }
 }

 return result;
 }

 Matrix operator-(const Matrix& other) const {
 if (rows != other.rows || cols != other.cols) {
 throw std::invalid_argument("Matrix dimensions do not match");
 }

 Matrix result(rows, cols);

 for (int i =0; i < rows; i++) {
 for (int j =0; j < cols; j++) {
 result.data[i][j] = data[i][j] - other.data[i][j];
 }
 }

 return result;
 }

 Matrix operator*(const Matrix& other) const {
 if (cols != other.rows) {
 throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
 }

 Matrix result(rows, other.cols);

 for (int i =0; i < rows; i++) {
 for (int j =0; j < other.cols; j++) {
 for (int k =0; k < cols; k++) {
 result.data[i][j] += data[i][k] * other.data[k][j];
 }
 }
 }

 return result;
 }

 friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
 for (int i =0; i < matrix.rows; i++) {
 for (int j =0; j < matrix.cols; j++) {
 os << matrix.data[i][j] << " ";
 }
 os << std::endl;
 }

 return os;
 }
};

int main() {
 Matrix matrix1(2,2);
 matrix1 = { {1,2}, {3,4} };

 Matrix matrix2(2,2);
 matrix2 = { {5,6}, {7,8} };

 Matrix sum = matrix1 + matrix2;
 Matrix difference = matrix1 - matrix2;
 Matrix product = matrix1 * matrix2;

 std::cout << "Matrix1:" << std::endl;
 std::cout << matrix1 << std::endl;

 std::cout << "Matrix2:" << std::endl;
 std::cout << matrix2 << std::endl;

 std::cout << "Sum:" << std::endl;
 std::cout << sum << std::endl;

 std::cout << "Difference:" << std::endl;
 std::cout << difference << std::endl;

 std::cout << "Product:" << std::endl;
 std::cout << product << std::endl;

 return 0;
}
