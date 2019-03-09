#pragma once
using namespace std;
const int i = 100, j = 100;

class matrix
{
	int _i, _j; //i - строка, j - столбец
	float element[i][j];
public:
	matrix();
	matrix(int n);
	matrix(int i_ , int j_);
	//~matrix();
	void operator = (matrix _m);
	void determining_the_size_of_the_matrix();
	void the_filling_of_the_matrix();
	void dispaly_of_the_matrix();
	matrix operator +(matrix _m);
	bool operator== (int n);
	matrix operator* (float k);
	matrix operator* (matrix _m);
	void add_of_matrix();
	void multiplication_of_matrix_by_a_number();
	void matrix_product();
};

