#include "Polinom.h"

PolinomIterator::PolinomIterator()
{
	MonomList = nullptr;
	currentNode = nullptr;
}
PolinomIterator::PolinomIterator(std::list<Monom>& l)
{
	MonomList = &l;
	init();
}

void PolinomIterator::Set_list(std::list<Monom>& l)
{
	MonomList = &l;
	currentNode = MonomList->begin()._Ptr;
}

void PolinomIterator::init()
{
	currentNode = MonomList->begin()._Ptr;
}

bool PolinomIterator::check_next()
{
	if (currentNode != MonomList->end()._Ptr)
		return true;
	else return false;
}

void PolinomIterator::go_next()
{
	if (!check_next()) throw std::exception("End of list!");
	currentNode = currentNode->_Next;
}

Monom& PolinomIterator::get_value()
{
	return currentNode->_Myval;
}

void PolinomIterator::del_cur()
{
	auto it = MonomList->begin();
	while (it._Ptr != currentNode) it++;
	MonomList->erase(it);
}

void PolinomIterator::insert_before(const Monom& m)
{
	auto it = MonomList->begin();
	while (it._Ptr != currentNode) it++;
	MonomList->insert(it, m);
}