#include "Matrix.h"

#include <iostream>
#include <vector>
using std::cout;
using std::endl;


int main()
{
	Matrix m1({
		{1, 2},
		{3, 4},
		{5, 6}
	});

	Matrix m2({
		{1, 2, 3},
		{4, 5, 6}
	});

	Matrix m3(3, 3);

	Matrix m4({
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	});

	Matrix m5(3, 3);

	// *
	m3 = m1 * m2;
	cout << m3 << endl;

	m3 *= m3;
	cout << m3 << endl;

	// +
	m5 = m3 + m4;
	cout << m5 << endl;

	m3 += m4;
	cout << m3 << endl;

	// -
	m5 = m4 - m4;
	cout << m5 << endl;

	m3 -= m3;
	cout << m3 << endl;

	
	return 0;
}

