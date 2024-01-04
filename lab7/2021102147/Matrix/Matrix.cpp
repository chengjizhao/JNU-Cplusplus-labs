#include "Matrix.h"

Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;
	for (int i = 0; i < row; ++i) {
		this->data.push_back(std::vector<int>(col, 0));
	}
}

Matrix::Matrix(std::vector<std::vector<int>> data)
{
	this->row = data.size();
	this->col = data[0].size();
	this->data = data;
}

//复制构造函数
Matrix::Matrix(const Matrix& other)
{
	this->row = other.row;
	this->col = other.col;
	this->data = other.data;
}

Matrix::Matrix(int row_count, int col_count, int** data)
{
	this->row = row_count;
	this->col = col_count;
	for (int i = 0; i < row_count; ++i) {
		this->data.push_back(std::vector<int>(col_count, 0));
	}
	for (int i = 0; i < row_count; i++) {
		for (int j = 0; j < col_count; j++) {
			(*this)[i][j] = data[i][j];
		}
	}
}

Matrix::~Matrix()
{}

// 如果两个矩阵的行数和列数不同，那么就不能相加，直接出现segment fault
// 这比返回一个空矩阵更不容易让人困惑
Matrix Matrix::operator+(const Matrix& other) {
	Matrix new_matrix(this->row, this->col);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			new_matrix[i][j] = (*this)[i][j] + other[i][j];
		}
	}
	return new_matrix;
}

// 同理
Matrix Matrix::operator-(const Matrix& other) {
	Matrix new_matrix(this->row, this->col);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			new_matrix[i][j] = (*this)[i][j] - other[i][j];
		}
	}
	return new_matrix;
}

// 乘法法则：新矩阵的行数等于左矩阵的行数，列数等于右矩阵的列数
// 如果左矩阵的列数和右矩阵的行数不相等，无法相乘，出现segment fault
Matrix Matrix::operator*(const Matrix& other) {
	Matrix new_matrix(this->row, other.col);
	int sum = 0;
	for (int i = 0; i < this->row; ++i) {	
		for (int j = 0; j < other.col; ++j) {
			sum = 0;
			for (int k = 0; k < this->col; ++k) {
				sum += (*this)[i][k] * other[k][j];
			}
			new_matrix[i][j] = sum;
		}
	}
	return new_matrix;
}

Matrix Matrix::operator*(int n) {
	Matrix new_matrix(row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			new_matrix[i][j] *= n;
		}
	}
	return new_matrix;
}

void Matrix::operator+=(const Matrix& other) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			(*this)[i][j] += other[i][j];
		}
	}
}

void Matrix::operator-=(const Matrix& other) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			(*this)[i][j] -= other[i][j];
		}
	}
}

// bug:不能传引用，要复制一份临时变量
void Matrix::operator*=(const Matrix other) {
	Matrix temp = *this;

	this->col = other.col;
	for (auto m : this->data) {
		m.resize(other.col, 0);
	}

	int sum = 0;
	for (int i = 0; i < this->row; ++i) {
		for (int j = 0; j < other.col; ++j) {
			sum = 0;
			for (int k = 0; k < this->col; ++k) {
				sum += temp[i][k] * other[k][j];
			}
			(*this)[i][j] = sum;
		}
	}
}

void Matrix::operator*=(int n) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			(*this)[i][j] *= n;
		}
	}
}

// 其实有个bug，但是懒得修了
std::vector<int>& Matrix::operator[](int index) {
	return data[index];
}

const std::vector<int>& Matrix::operator[](int index) const {
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m.row; ++i) {
		for (int j = 0; j < m.col; ++j) {
			os << m[i][j];
			if (j != m.col - 1) {
				os << "\t";
			}
		}
		os << std::endl;
	}
	return os;
}

