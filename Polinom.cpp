#include "Polinom.h"

bool Polinom::operator==(const Polinom& p)const
{
	return polinom == p.polinom;
}

Polinom& Polinom::operator=(const Polinom& p)
{
	polinom = p.polinom;
	it.init();
	return *this;
}

int Polinom::Resault(int x, int y, int z)
{
	int res = 0;
	it.init();
	while (it.check_next())
	{
		res += it.get_value().Resault(x, y, z);
		it.go_next();
	}
	return res;
}

void Polinom::OutputFile(std::string path)
{
	std::fstream fs;
	fs.open(path, std::ios::out | std::ios::app);
	if (!fs.is_open())
	{
		std::cout << "Error open file!" << std::endl;
	}
	else
	{
		fs << to_str();
		std::cout << "File opened and rewritten!" << std::endl;
	}
	fs.close();
}

std::string Polinom::to_str()
{
	std::string res;
	it.init();
	bool add_first_flag = false;
	Monom tmp = it.get_value();
	while (it.check_next())
	{
		if (tmp.Get_coef() > 0 && add_first_flag)
		{
			res += "+" + tmp.ConvertString();
		}
		else
		{
			res += tmp.ConvertString();
		}
		it.go_next();
		tmp = it.get_value();
		add_first_flag = true;
	}

	return res;
}

void Polinom::del_nulls()
{
	it.init();
	while (it.check_next())
	{
		if (it.get_value().Get_coef() == 0)
		{
			it.del_cur();
			it.init();
		}
		if (!it.check_next())
		{
			break;
		}
		it.go_next();
	}
	if (polinom.size() == 0)
	{
		set_null();
	}
}

void Polinom::set_null()
{
	Monom null_monom(0, 0, 0, 0);
	if (polinom.size() == 0)
	{
		polinom.push_back(null_monom);
	}
}

void Polinom::DeletPolinom()
{
	polinom.clear();
	Monom m(0, 0, 0, 0);
	polinom.push_back(m);
}

Polinom::Polinom()
{
	Monom m(0, 0, 0, 0);
	polinom.push_back(m);
	it.Set_list(polinom);
}

Polinom::Polinom(const std::vector<Monom>& m)
{
	if (m.size() == 0)
	{
		throw std::exception("Initial vector is empty!");
	}
	for (int i = 0; i < m.size(); i++)
	{
		it.Set_list(polinom);
		*this += m[i];
	}
	del_nulls();
}

Polinom::Polinom(const Polinom& p)
{
	polinom = p.polinom;
	it.Set_list(polinom);
	it.init();
}

Polinom Polinom::operator+(const Monom& m) const
{
	Polinom res(*this);
	res += m;
	return res;
}

Polinom Polinom::operator-(const Monom& m) const
{
	Polinom res(*this);
	res -= m;
	return res;
}

Polinom& Polinom::operator-=(const Monom& m)
{
	if (polinom.size() == 0)
	{
		polinom.push_back(-m);
		del_nulls();
		return *this;
	}
	it.init();
	while (it.check_next())
	{
		if (it.get_value() == m)
		{
			it.get_value() -= m;
			del_nulls();
			return *this;
		}
		else if (it.get_value() < m)
		{
			it.insert_before(-m);
			del_nulls();
			return *this;
		}
		it.go_next();
	}
	polinom.push_back(m);
	del_nulls();
	return *this;
}

Polinom Polinom::operator*(const Monom& m)
{
	Polinom p;
	it.init();
	while (it.check_next())
	{
		p += it.get_value() * m;
		it.go_next();
	}
	return p;
}

Polinom& Polinom::operator*=(const Monom& m)
{
	Polinom p;
	it.init();
	while (it.check_next())
	{
		p += it.get_value() * m;
		it.go_next();
	}
	*this = p;
	return *this;
}

Polinom Polinom::operator+(Polinom& p)
{
	Polinom res(*this);
	p.it.init();
	while (p.it.check_next())
	{
		res += p.it.get_value();
		p.it.go_next();
	}
	return res;
}

Polinom& Polinom::operator+=(Polinom& p)
{
	p.it.init();
	while (p.it.check_next())
	{
		*this += p.it.get_value();
		p.it.go_next();
	}
	return *this;
}

Polinom Polinom::operator-(Polinom& p)
{
	Polinom res(*this);
	p.it.init();
	while (p.it.check_next())
	{
		res -= p.it.get_value();
		p.it.go_next();
	}
	return res;
}

Polinom& Polinom::operator-=(Polinom& p)
{
	p.it.init();
	while (p.it.check_next())
	{
		*this -= p.it.get_value();
		p.it.go_next();
	}
	return *this;
}

Polinom Polinom::operator*(Polinom& p)
{
	Polinom res;
	p.it.init();
	it.init();
	while (it.check_next())
	{
		while (p.it.check_next())
		{
			res += it.get_value() * p.it.get_value();
			p.it.go_next();
		}
		p.it.init();
		it.go_next();
	}

	return res;
}

Polinom& Polinom::operator*=(Polinom& p)
{
	Polinom res;
	p.it.init();
	it.init();
	while (it.check_next())
	{
		while (p.it.check_next())
		{
			res += it.get_value() * p.it.get_value();
			p.it.go_next();
		}
		p.it.init();
		it.go_next();
	}
	*this = res;
	return *this;
}

Polinom Polinom::operator*(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res *= m;
	return res;
}

Polinom& Polinom::operator*=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this *= m;
	return *this;
}

Polinom Polinom::operator-(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res -= m;
	return res;
}

Polinom& Polinom::operator-=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this -= m;
	return *this;
}

Polinom Polinom::operator+(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res += m;
	return res;
}

Polinom& Polinom::operator+=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this += m;
	return *this;
}

Polinom& Polinom::operator+=(const Monom& m)
{
	if (polinom.size() == 0)
	{
		polinom.push_back(m);
		del_nulls();
		return *this;
	}
	it.init();
	while (it.check_next())
	{
		if (it.get_value() == m)
		{
			it.get_value() += m;
			del_nulls();
			return *this;
		}
		else if (it.get_value() < m)
		{
			it.insert_before(m);
			del_nulls();
			return *this;
		}
		it.go_next();
	}
	polinom.push_back(m);
	del_nulls();
	return *this;
}