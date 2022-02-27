#include "Stack.h"
#include <iostream>

Stack::Stack(int n)
{
	size = n;
	pitems = new Item[size];
	top = 0;
}

Stack::Stack(const Stack& st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
	delete []pitems;
}

bool Stack::isempty() const
{
	if (top > 0)
		return false;
	else
		return true;
}

bool Stack::isfull() const
{
	if (top == max)
		return true;
	else
		return false;
}

bool Stack::push(const Item& item)
{
	if (isfull())
		return false;
	else
	{
		pitems[top++] = item;
		return true;
	}
}

bool Stack::pop(Item& item)
{
	if (isempty())
		return false;
	else
	{
		item = pitems[top--];
		return true;
	}
}

Stack& Stack::operator=(const Stack& st)
{
	size = st.size;
	top = st.top;
	delete[] pitems;
	pitems = new Item[size];
	for (int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];
	return *this;
}

void Stack::show()
{
	std::cout << "Stack:\n";
	std::cout << "Count of elems: " << top << '\n';
	for (int i = 0; i < top; i++)
		std::cout << pitems[i] << " ";
	std::cout << std::endl;
}