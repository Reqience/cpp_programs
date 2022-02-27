// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker* www[SIZE];
	Stack<Worker*> q;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':   www[ct] = new Waiter;
			q.push(www[ct]);
			break;
		case 's':  www[ct] = new Singer;
			q.push(www[ct]);
			break;
		case 't':   www[ct] = new SingingWaiter;
			q.push(www[ct]);
			break;
		}
		cin.get();
		q.getElem(ct)->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		q.getElem(ct)->Show();
	}
	for (i = 0; i < ct; i++)
		delete q.getElem(i);
	cout << "Bye.\n";
	// cin.get();
	// cin.get();
	return 0;
}
