#pragma once

#include <iostream>
#include <string>

#define POWER_MAX 20

class Monom
{
private:
	short int coef;
	int power;

	void Set_power(int A, int B, int C);
public:
	Monom();
	Monom(int coef, int A, int B, int C);
	Monom(const Monom& m);

	int Get_A()const;
	int Get_B()const;
	int Get_C()const;
	int Get_coef()const;

	bool operator==(const Monom& m)const;
	bool operator!=(const Monom& m)const;

	bool operator>(const Monom& m)const;
	bool operator<(const Monom& m)const;

	bool operator<=(const Monom& m)const;
	bool operator>=(const Monom& m)const;

	Monom operator+(const Monom& m)const;
	Monom& operator+=(const Monom& m);

	Monom operator-(const Monom& m)const;
	Monom operator-()const;
	Monom& operator-=(const Monom& m);

	Monom operator*(const Monom& m)const;
	Monom& operator*=(const Monom& m);

	Monom operator*(const int& num)const;
	Monom& operator*=(const int& num);

	int Resault(int a, int b, int c);
	std::string ConvertString()const;
};