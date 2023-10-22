#pragma once
#include <vector>
#include <iostream>

class Matrix
{
public:
	Matrix(int row, int col);
	Matrix(int row_count, int col_count, int** data);
	Matrix(std::vector<std::vector<int>> data);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(const int n);
	void operator+=(const Matrix& other);
	void operator-=(const Matrix& other);
	void operator*=(const Matrix other);
	void operator*=(const int n);

	std::vector<int>& operator[](int index);
	const std::vector<int>& operator[](int index)const;

	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
private:
	int row;
	int col;
	std::vector<std::vector<int>> data;
	
};

