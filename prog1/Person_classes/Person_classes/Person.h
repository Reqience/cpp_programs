#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person
{
private:
	std::string firstname;
	std::string lastname;
public:
	virtual ~Person() {}
	Person(const char * fn = "None", const char * ln = "None") : firstname(fn), lastname(ln) {}
	Person(const Person & p) { firstname = p.firstname; lastname = p.lastname; }
	virtual void Show() const;
};

class Gunslinger : virtual public Person
{
private:
	double time;
	int notch;
public:
	virtual double Draw() const { return time; }
	virtual void Show() const;
	Gunslinger(const char * fn = "None", const char * ln = "None", double t = 0.0, int n = 0) 
		: Person(fn, ln), time(t), notch(n) {}
	Gunslinger(const Gunslinger & g) : Person(g), time(g.time), notch(g.notch) {}
	virtual ~Gunslinger() {}
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(const char * fn = "None", const char * ln = "None")
		: Person(fn, ln) {}
	PokerPlayer(const PokerPlayer & pp) : Person(pp) {}
	virtual ~PokerPlayer() {}
	virtual double Draw() const;
	virtual void Show() const;
};

class BadDude : public PokerPlayer, public Gunslinger
{
public:
	BadDude(const char * fn = "None", const char * ln = "None", int n = 0, double time = 0.0)
		: Gunslinger(fn, ln, time, n) {}
	BadDude(const BadDude & bd) : Gunslinger(bd) {}
	virtual ~BadDude() {}
	double Cdraw() const { return PokerPlayer::Draw(); }
	double Gdraw() const { return Gunslinger::Draw(); }
	virtual void Show() const;
};
#endif // !PERSON_H
