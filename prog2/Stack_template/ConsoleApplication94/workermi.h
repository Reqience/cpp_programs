#pragma once
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

class Worker   // an abstract base class
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string & s, long n)
		: fullname(s), id(n) {}
	virtual ~Worker() = 0; // pure virtual function
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string & s, long n, int p = 0)
		: Worker(s, n), panache(p) {}
	Waiter(const Worker & wk, int p = 0)
		: Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum {
		other, alto, contralto, soprano,
		bass, baritone, tenor
	};
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char *pv[Vtypes];    // string equivs of voice types
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other)
		: Worker(s, n), voice(v) {}
	Singer(const Worker & wk, int v = other)
		: Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p = 0,
		int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker & wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter & wt, int v = other)
		: Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer & wt, int p = 0)
		: Worker(wt), Waiter(wt, p), Singer(wt) {}
	void Set();
	void Show() const;
};


template <typename T, int qsize>
class QueueTp
{
private:
	T items[qsize];
	int top;
public:
	QueueTp(T it[] = nullptr);
	bool isfull();
	bool isempty();
	bool pop(T& item);
	bool add(T& item);
	T & getElem(int i) { return items[i]; }
};
template <class Type>
class Stack
{
private:
	enum { SIZE = 10 };    // default size
	int stacksize;
	Type * items;       // holds stack items
	int top;            // index for top stack item
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack & st);
	~Stack() { delete[] items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const Type & item);   // add item to stack
	bool pop(Type & item);          // pop top into item
	Stack & operator=(const Stack & st);
	Type& getElem(int i) { return items[i]; }
};

template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
	items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
	if (this == &st)
		return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}
#endif
