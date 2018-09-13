#pragma once
#include <iostream>

using namespace std;

#include <stdlib.h>

// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩

class Matrix {

public:

	Matrix(int row, int col);

	int GetData();

	Matrix Transpose();

	int Display();

	//Matrix Add(Matrix b);

	Matrix Multiply(Matrix b);

	int CompareRowCol(Matrix b);

private:

	int rows, cols;

	//int Term[rows][cols];

	int *Term;//the add 2.6ress of a[i][j] = 0 + i * cols + j => Fig2.6

};



Matrix::Matrix(int row, int col) : rows(row), cols(col)

{

	Term = new int[rows * cols];

}



int Matrix::GetData() {

	int input_value;

	cout << "rows = " << rows << "  cols = " << cols << endl;

	for (int j = 0; j < rows * cols; j++)

	{

		cout << "term value = ";

		cin >> input_value;

		cout << " " << endl;

		Term[j] = input_value;

	}

	return 0;

}



Matrix Matrix::Transpose() {

	Matrix b(cols, rows);

	//...

	// 학생들이 code 작성

	return b;

}



Matrix Matrix::Multiply(Matrix b) {

	if (cols != b.rows) cout << "Incompatible matrices" << endl;

	Matrix bXpose = b.Transpose();

	Matrix d(rows, b.cols);

	// 학생들이 code 작성

	return d;

}

int Matrix::CompareRowCol(Matrix b) {

	if (cols != b.rows) return 1;

	else return 0;

}

int Matrix::Display() {

	int n;

	n = rows * cols;

	for (int i = 0; i < rows; i++)

	{

		cout << endl;

		for (int j = 0; j < cols; j++)

			cout << Term[i*cols + j] << " ";

	}

	cout << endl;

	return 0;

}