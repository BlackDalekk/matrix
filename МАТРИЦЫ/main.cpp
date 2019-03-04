#include "pch.h"
#include "matrix.h"
#include "foo.h"
#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	setlocale(LC_ALL, "Rissian");
	system("chcp 1251 >> null");
	string str;
	matrix A;
	char ch;
	while (true) {
		cout << "Выберете действие\nСложение(1)\nУмножение на число(2)\nУмножение матрицы на матрицу(3): ";
		cin.unsetf(ios::skipws);
		cin >> str;
		if (is_Number_Of_Menu(str)) {
			cin.ignore(10, '\n');
			ch = *str.c_str();
			break;
		}
		cin.ignore(10, '\n');
		cout << "Ошибка!\n";
	}
	switch (ch)
	{
	case('1'): A.add_of_matrix(); break;
	case('2'): A.multiplication_of_matrix_by_a_number(); break;
	case('3'): A.matrix_product(); break;
	default:
		break;
	}
	cout << "Нажмите любую клавишу для выхода . . .\n";
	_getch();
	return 0;
}