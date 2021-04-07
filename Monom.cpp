#include "Monom.h"

void Monom::Set_power(int A, int B, int C)
{
	power = A * POWER_MAX * POWER_MAX + B * POWER_MAX + C;
}

Monom::Monom()
{
	coef = 1;
	Set_power(1, 1, 1);
}

Monom::Monom(int coef, int A, int B, int C)
{
	if (A >= POWER_MAX || B >= POWER_MAX || C >= POWER_MAX)
	{
		throw std::exception("Too many numbers!");
	}
	this->coef = coef;
	Set_power(A, B, C);
}

int Monom::Get_A()const
{
	return power / POWER_MAX / POWER_MAX;
}

int Monom::Get_B()const
{
	return (power - Get_A() * POWER_MAX * POWER_MAX) / POWER_MAX;
}
int Monom::Get_C()const
{
	return power % POWER_MAX;
}

Monom::Monom(const Monom& m)
{
	coef = m.coef;
	power = m.power;
}

int Monom::Get_coef() const { return coef; }

bool Monom::operator==(const Monom& m) const { return power == m.power; }

bool Monom::operator!=(const Monom& m) const { return power != m.power; }

bool Monom::operator<=(const Monom& m) const { return power <= m.power; }

bool Monom::operator>=(const Monom& m) const { return power >= m.power; }

bool Monom::operator>(const Monom& m) const { return power > m.power; }

bool Monom::operator<(const Monom& m) const { return power < m.power; }

Monom Monom::operator+(const Monom& m) const
{
	if (*this != m)
	{
		throw std::logic_error("Monoms are different!");
	}
	Monom res(*this);
	res.coef += m.coef;
	return res;
}

Monom& Monom::operator+=(const Monom& m)
{
	if (*this != m)
	{
		throw std::exception("Monoms are different!");
	}
	coef += m.coef;
	return *this;
}

Monom Monom::operator-(const Monom& m) const
{
	if (*this != m)
	{
		throw std::exception("Monoms are different!");
	}
	Monom res(*this);
	res.coef += m.coef;
	return res;
}

Monom Monom::operator-() const
{
	Monom res(*this);
	res.coef *= -1;
	return res;
}

Monom& Monom::operator-=(const Monom& m)
{
	if (*this != m)
	{
		throw std::exception("Monoms are different!");
	}
	coef -= m.coef;
	return *this;
}

Monom Monom::operator*(const Monom& m) const
{
	return Monom(coef * m.coef, Get_A() + m.Get_A(), Get_B() + m.Get_B(), Get_C() + m.Get_C());
}

Monom& Monom::operator*=(const Monom& m)
{
	coef *= m.coef;
	Set_power(Get_A() + m.Get_A(), Get_B() + m.Get_B(), Get_C() + m.Get_C());
	return *this;
}

Monom Monom::operator*(const int& num) const
{
	Monom res(*this);
	res.coef *= num;
	return res;
}

Monom& Monom::operator*=(const int& num)
{
	coef *= num;
	return *this;
}

int Monom::Resault(int x, int y, int z)
{
	return coef * pow(x, Get_A()) * pow(y, Get_B()) * pow(z, Get_C());
}

std::string Monom::ConvertString()const
{
	std::string res;
	const int A = Get_A();
	const int B = Get_B();
	const int C = Get_C();

	switch (coef)
	{
	case -1:
		res += "-";
		break;
	case 0:
		res += std::to_string(coef);
		break;
	case 1:
		// +
		break;
	default:
		res += std::to_string(coef) + " * ";
		break;
	}

	if (A)
	{
		if (A == 1)
		{
			res += "a * ";
		}
		else
		{
			res += "a^" + std::to_string(A) + " * ";
		}
	}
	if (B)
	{
		if (B == 1)
		{
			res += "b * ";
		}
		else
		{
			res += "b^" + std::to_string(B) + " * ";
		}
	}
	if (C)
	{
		if (C == 1)
		{
			res += "c ";
		}
		else
		{
			res += "c^" + std::to_string(C) + " ";
		}
	}
	return res;
}