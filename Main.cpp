#include <locale>
#include "monom.h"
#include "polinom.h"

#define PATH_FOR_FILE "C:\\out.txt"

void Menu(Polinom& p1, Polinom& p2, Polinom& res)
{
	std::cout << "p1 = " << p1.to_str() << std::endl;
	std::cout << "p2 = " << p2.to_str() << std::endl;
	std::cout << "res = " << res.to_str() << std::endl << std::endl;
	std::cout << "1) Сложить полиномы" << std::endl << std::endl;
	std::cout << "2) Вычесть полиномы" << std::endl << std::endl;
	std::cout << "3) Перемножить полиномы" << std::endl << std::endl;
	std::cout << "4) Посчитать результат" << std::endl << std::endl;
	std::cout << "5) Ввести новые значения" << std::endl << std::endl;
	std::cout << "6) Вывести в файл" << std::endl << std::endl;
	std::cout << "0) Выход" << std::endl << std::endl;
	std::cout << "> ";
}
void calculate_polinom(Polinom& res)
{
	if (res.to_str() == "0") { std::cout << "Выполните 1,2 или 3 пункт меню!\n"; return; }
	int x, y, z;
	std::cout << "Введите a: ";
	std::cin >> x;
	std::cout << "Введите b: ";
	std::cin >> y;
	std::cout << "Введите c: ";
	std::cin >> z;
	std::cout << res.to_str() << " = " << res.Resault(x, y, z) << std::endl;
}
void input_monom(Monom& m)
{
	int A, B, C, coef;
	std::cout << "Коэфицент: ";
	std::cin >> coef;
	std::cout << "Введите A: ";
	std::cin >> A;
	std::cout << "Введите B: ";
	std::cin >> B;
	std::cout << "Введите C: ";
	std::cin >> C;
	Monom monom(coef, A, B, C);
	m = monom;
}

void input_polinom(Polinom& p)
{
	Monom m;

	int num_of_monoms;
	std::cout << "Количество мономов: ";
	std::cin >> num_of_monoms;
	for (int i = 0; i < num_of_monoms; i++)
	{
		std::cout << "Введите моном " << i + 1 << std::endl;
		input_monom(m);
		p += m;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Polinom p1;
	Polinom p2;
	Polinom res;
	int menuSelection = 0;
	//std::cout << "Введите p1 и p2:\n";
	//input_polinom(p1);
	//input_polinom(p2);
	while (true)
	{
		system("cls");
		Menu(p1, p2, res);
		std::cin >> menuSelection;
		switch (menuSelection)
		{
		case 1:
			res = p1 + p2;
			std::cout << p1.to_str() << "  +  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 2:
			res = p1 - p2;
			std::cout << p1.to_str() << "  -  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 3:
			res = p1 * p2;
			std::cout << p1.to_str() << "  *  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 4:
			calculate_polinom(res);
			system("pause");
			break;
		case 5:
			system("cls");
			std::cout << "Введите p1 и p2:\n";
			p1.DeletPolinom();
			p2.DeletPolinom();
			res.DeletPolinom();
			input_polinom(p1);
			input_polinom(p2);
			break;
		case 6:
			if (res.to_str() == "0") 
			{ 
				std::cout << "Выполните 1,2 или 3 пункт меню!\n";
				system("pause");
				break; 
			}

			std::cout << "Вывести в файл результат: ";
			res.OutputFile(PATH_FOR_FILE);
			system("pause");
			break;
		case 0:
			return 0;
		}

	}
	return 0;
}