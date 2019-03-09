#include "pch.h"
#include <iostream>
#include <string>
#include "foo.h"
#include "matrix.h"
#include <iomanip>
using namespace std;

matrix::matrix()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			element[i][j] = 0;
	}
}

matrix::matrix(int n)
{
	element[0][0] = n;
}

matrix::matrix(int i_, int j_)
{
	_i = i_;
	_j = j_;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			element[i][j] = 0;
	}
}


//matrix::~matrix()
//{  }

void matrix::operator=(matrix _m)
{
	_i = _m._i;
	_j = _m._j;
	for (int i = 0; i < _i; i++) {
		for (int j = 0; j < _j; j++)
			element[i][j] = _m.element[i][j];
	}

}

void matrix::determining_the_size_of_the_matrix()
{
	string str;
	cin.clear();
	while (true){
		cout << "Введите кол-во строк: ";
		cin.unsetf(ios::skipws);
		cin >> str;
		if (is_Index(str)) {
			cin.ignore(10, '\n');
			_i = atoi(str.c_str());
			break;
		}
		cin.ignore(10, '\n');
		cerr << "Ошибка ввода!\n";
	}
	while (true) {
		cout << "Введите кол-во столбцов: ";
		cin.unsetf(ios::skipws);
		cin >> str;
		if (is_Index(str)) {
			cin.ignore(10, '\n');
			_j = atoi(str.c_str());
			break;
		}
		cin.ignore(10, '\n');
		cerr << "Ошибка ввода!\n";
	}
}

void matrix::the_filling_of_the_matrix()
{
	string str;
	for (int i = 0; i < _i; i++) {
		for (int j = 0; j < _j; j++) {
			cin.clear();
			while (true) {
				cout << "Введите элемент " << i + 1 << " " << j + 1 << endl;
				cin.unsetf(ios::skipws);
				cin >> str;
				if (is_Number(str)) {
					cin.ignore(10, '\n');
					element[i][j] = atof(str.c_str());
					break;
				}
				cin.ignore(10, '\n');
				cout << "Ошибка ввода!\n";
			}
		}
	}
}

void matrix::dispaly_of_the_matrix()
{
	cout << endl;
	for (int i = 0; i < _i; i++) {
		if (_i == 1) cout << " ( ";
		else if (i == 0 ) cout << " /";
		else if(i == _i - 1) cout << " \\";
		else cout << "| ";
		

		for (int j = 0; j < _j; j++)
			cout << setw(4) << element[i][j] << " ";

		if (_i == 1) cout << " ) ";
		else if (i == 0) cout << " \\ ";
		else if (i == _i - 1) cout << " / ";
		else cout << "  |";
		
		cout << endl;
	}
}

matrix matrix::operator + (matrix _m)
{
	if (_i != _m._i || _j != _m._j)
		return matrix(0);
	matrix m(_i, _j);
	for (int i = 0; i < _i; i++) {
		for (int j = 0; j < _j; j++)
			m.element[i][j] = _m.element[i][j] + element[i][j];
	}
	return m;
}

bool matrix::operator== (int n)
{
	if (element[0][0] == n)
		return true;
	return false;
}

matrix matrix::operator*(float k)
{
	for (int i = 0; i < _i; i++) {
		for (int j = 0; j < _j; j++) {
			element[i][j] *= k;
		}
	}
	return *this;
}

matrix matrix::operator*(matrix _m)
{
	matrix M(_i, _m._j);
	for (int i_1 = 0; i_1 < _i; i_1++) {
		for (int j_2 = 0; j_2 < _m._j; j_2++) {
			for (int i_2 = 0, j_1 = 0; i_2 < _m._i, j_1 < _j; i_2++, j_1++)
				M.element[i_1][j_2] += element[i_1][j_1] * _m.element[i_2][j_2];
		}
	}
	return M;
}

void matrix::add_of_matrix()
{
	matrix A, B, C;
	A.determining_the_size_of_the_matrix();
	A.the_filling_of_the_matrix();
	B.determining_the_size_of_the_matrix();
	B.the_filling_of_the_matrix();
	C = A + B;
	C.dispaly_of_the_matrix();
}

void matrix::multiplication_of_matrix_by_a_number()
{
	matrix A;
	string str;
	float k;
	A.determining_the_size_of_the_matrix();
	A.the_filling_of_the_matrix();
	while (true) {
		cout << "Введите множитель: ";
		cin.unsetf(ios::skipws);
		cin >> str;
		if (is_Multiplier(str)) {
			cin.ignore(10, '\n');
			k = atof(str.c_str());
			break;
		}
		cin.ignore(10, '\n');
		cout << "Ошибка!\n";
	}
	A = A * k;
	A.dispaly_of_the_matrix();
}

void matrix::matrix_product()
{
	matrix A, B;
	A.determining_the_size_of_the_matrix();
	A.the_filling_of_the_matrix();
	B.determining_the_size_of_the_matrix();
	B.the_filling_of_the_matrix();
	if (A._j != B._i) {
		cerr << "Ошибка!\nКол-во столбцов первой матрицы не совпадает с кол-вом строк второй матрицы!\n";
		return;
	}
	matrix C(A._i, B._j);
	C = A * B;
	C.dispaly_of_the_matrix();
}
