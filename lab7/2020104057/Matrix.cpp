#include <iostream>
using namespace std;
class matrix {
public:
	int r, c;
	int** mem;
	matrix(int a, int b) {
		r = a;
		c = b;
		mem = new int* [a];
		for (int i = 0; i < a; i++) {
			mem[i] = new int[b];
		}
	};
	matrix(const matrix& p) {
		r = p.r;
		c = p.c;
		mem = new int* [r];
		for (int i = 0; i < r; i++) {
			mem[i] = new int[c];
		}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				mem[i][j] = p.mem[i][j];
			}
	}
	~matrix() {
		for (int i = 0; i < r; i++) {
			delete[]mem[i];
		}
		delete[]mem;
	};
	matrix operator+ (const matrix& m) {
		if (r != m.r || c != m.c) {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else {
			matrix tmp(r, c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					tmp.mem[i][j] = mem[i][j] + m.mem[i][j];
			return tmp;
		}
	}
	matrix operator- (const matrix& m) {
		if (r != m.r || c != m.c) {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else {
			matrix tmp(r, c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					tmp.mem[i][j] = mem[i][j] - m.mem[i][j];
			return tmp;
		}
	}
	matrix operator* (const matrix& m)
	{
		if (c != m.r) {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else {
			matrix tmp(r, m.c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < m.c; j++)
					tmp.mem[i][j] = 0;
			for (int i = 0; i < tmp.r; i++)
				for (int j = 0; j < tmp.c; j++)
					for (int k = 0; k < c; k++)
						tmp.mem[i][j] += (mem[i][k] * m.mem[k][j]);
			return tmp;
		}
	}
	matrix operator~ ()
	{
		matrix tmp(c, r);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				tmp.mem[j][i] = mem[i][j];
		return tmp;
	}
	matrix & operator=(const matrix& m)
	{
		if (c != m.r) {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					mem[i][j] = m.mem[i][j];
			return *this;
		}
	}
	friend void display(matrix m)
	{
		for (int i = 0; i < m.r; i++) {
			for (int j = 0; j < m.c; j++) {
				cout << m.mem[i][j] << ' ';
			}
			cout << endl;
		}
	}
};