#pragma once
#include <list>
#include <vector>
#include <fstream>
#include "Monom.h"
#include "PolinomIterator.h"

class Polinom
{
private:
	std::list<Monom> polinom;
	PolinomIterator it;

public:
	Polinom();
	Polinom(const std::vector<Monom>& m);
	Polinom(const Polinom& p);

	Polinom& operator+=(const Monom& m);
	Polinom operator+(const Monom& m)const;

	Polinom operator-(const Monom& m)const;
	Polinom& operator-=(const Monom& m);

	Polinom operator*(const Monom& m);
	Polinom& operator*=(const Monom& m);

	Polinom operator+(Polinom& p);
	Polinom& operator+=(Polinom& p);

	Polinom operator-(Polinom& p);
	Polinom& operator-=(Polinom& p);
	Polinom operator*(Polinom& p);
	Polinom& operator*=(Polinom& p);

	Polinom operator*(const int& num)const;
	Polinom& operator*=(const int& num);

	Polinom operator-(const int& num)const;
	Polinom& operator-=(const int& num);

	Polinom operator+(const int& num)const;
	Polinom& operator+=(const int& num);

	bool operator==(const Polinom& p)const;
	Polinom& operator=(const Polinom& p);
	int Resault(int x, int y, int z);

	void OutputFile(std::string path);

	std::string to_str();
	void del_nulls();
	void set_null();
	void DeletPolinom();

	friend PolinomIterator;
};
