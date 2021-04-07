#pragma once

#include "Polinom.h"

class PolinomIterator {
private:
	std::list<Monom>* MonomList;
	std::_List_node<Monom, void*>* currentNode;
public:
	PolinomIterator();
	PolinomIterator(std::list<Monom>& l);

	void Set_list(std::list<Monom>& l);
	void init();
	bool check_next();
	void go_next();
	Monom& get_value();
	void del_cur();
	void insert_before(const Monom& m);

};
