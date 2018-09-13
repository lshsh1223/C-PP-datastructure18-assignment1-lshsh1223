#include <iostream>
#include "Matrix.h"

using namespace std;


int main()
{
	Matrix a(2, 3);

	Matrix b(3, 4);

	Matrix c(2, 4);

	cout << "Enter first matrix: " << endl;

	a.GetData();

	cout << "Enter second matrix: " << endl;

	b.GetData();



	cout << "Display first matrix: " << endl;

	a.Display();

	cout << "Display second matrix: " << endl;

	b.Display();



	Matrix d(4, 3);

	//d = b.Transpose();

	cout << "Transpose() of Matrix b" << endl;

	d.Display();

	/* If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again. */

	if (a.CompareRowCol(b))
	{
		cout << "Error! column of first matrix not equal to row of second.";

		cout << "Enter rows and columns for first matrix: ";

	}

	//c = a.Multiply(b);

	cout << "Multiply of Matrix a,b" << endl;

	c.Display();

	system("pause");

	return 0;

}