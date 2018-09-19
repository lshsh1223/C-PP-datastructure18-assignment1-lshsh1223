#pragma once
#include <iostream>
#include <chrono>
using namespace std;

class Matrix {
public:
	Matrix(int n);
	Matrix TransposeMultiply(Matrix b);
	Matrix Multiply(Matrix b);
private:
	int n;
	int *Term;
};

Matrix::Matrix(int n) : n(n)
{
	this->Term = new int[n * n];
	for (int i = 0; i < n * n; i++)
		this->Term[i] = 0;
}

// Transpose 후 Multiply 연산
Matrix Matrix::TransposeMultiply(Matrix b) {
	Matrix c(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b.Term[j*n + i] = Term[i*n + j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum = sum + Term[i*n + k] * b.Term[j*n + k];
				c.Term[i*n + j] = sum;
			}
		}
	}
	return c;
}

// Transpose하지 않고 Multiply 연산
Matrix Matrix::Multiply(Matrix b) {
	Matrix c(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum = sum + Term[i*n + k] * b.Term[k*n + j];
				c.Term[i*n + j] = sum;
			}
		}
	}
	return c;
}

int main(void)
{
	for (int n = 1; n <= 10000; n++) {
		Matrix a(n);
		Matrix b(n);
		Matrix c(n);
		Matrix d(n);
		cout << "n = " << n << endl << "Transpose and Multyply Time: ";
		auto start_a = chrono::high_resolution_clock::now();
		c = a.TransposeMultiply(b);		// Transpose 후 Multiply 연산
		auto finish_a = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed_a = finish_a - start_a;
		cout << elapsed_a.count() << ", Multiply Time : ";
		auto start_b = chrono::high_resolution_clock::now();
		d = a.Multiply(b);				// Transpose하지 않고 Multiply 연산
		auto finish_b = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed_b = finish_b - start_b;
		cout << elapsed_b.count() << endl << endl;
	}
	system("pause");
	return 0;
}