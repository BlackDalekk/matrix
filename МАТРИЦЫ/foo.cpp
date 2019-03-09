#include "pch.h"
#include "foo.h"
#include <iostream>
#include <string>
using namespace std;

bool is_Index(string str)
{
	int l = str.size();
	if (l < 1 || l > 2)
		return false;
	for (int i = 0; i < l; ++i) {
		if (static_cast<int>(str[i]) < 48 || static_cast<int>(str[i]) > 57)
			return false;
	}
	int n = atoi(str.c_str());
	if (n < 1 || n > 99)
		return false;
	return true;
}

bool is_Number(string str)
{
	int l = str.size();
	if (l < 1 || l > 10) return false;
	for (int i = 0; i < l; ++i) {
		if (static_cast<int>(str[i]) < 45 || (static_cast<int>(str[i]) > 46 && static_cast<int>(str[i]) < 48)  || static_cast<int>(str[i]) > 57)
			return false;
	}
	int n = atof(str.c_str());
	if(n < -99999999 || n > 99999999) return false;
	return true;
}

bool is_Number_Of_Menu(string str)
{
	int l = str.size();
	if (l != 1) return false;
	for (int i = 0; i < l; ++i) {
		if (static_cast<int>(str[i]) < 48 || static_cast<int>(str[i]) > 57)
			return false;
	}
	return true;
}

bool is_Multiplier(string str)
{
	int l = str.size();
	if (l < 1 || l > 2) return false;
	for (int i = 0; i < l; ++i) {
		if (static_cast<int>(str[i]) < 48 || static_cast<int>(str[i]) > 57)
			return false;
	}
	int n = atof(str.c_str());
	if (n < -99 || n > 99) return false;
	return true;
}
