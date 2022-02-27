
#include <iostream>
#include "workermi.h"

using std::cout;
using std::cin;
using std::endl;
// Worker methods
Worker::~Worker() { }

// protected methods
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

// Waiter methods
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

// protected methods
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

// Singer methods
char* Singer::pv[7] = {};

void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

// protected methods
void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value >= 0 and < " << Vtypes << endl;
	while (cin.get() != '\n')
		continue;
}

// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}

template <typename T, int qsize>
QueueTp<T, qsize>::QueueTp(T it[]) : items(it)
{
	top = 0;
}

template <typename T, int qsize>
bool QueueTp<T, qsize>::pop(T& item)
{
	if (!isempty())
	{
		item = items[top--];
		return true;
	}
	else
		return false;
}

template <typename T, int qsize>
bool QueueTp<T, qsize>::add(T&  item)
{
	if (!isfull())
	{
		items[++top] = item;
		return true;
	}
	else
		return false;
}

template <typename T, int qsize>
bool QueueTp<T, qsize>::isfull()
{
	if (top == qsize)
		return true;
	else
		return false;
}

template <typename T, int qsize>
bool QueueTp<T, qsize>::isempty()
{
	if (top == 0)
		return true;
	else
		return false;
}