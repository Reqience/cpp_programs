#include "Person.h"
#include <ctime>
#include <iostream>

void Person::Show() const
{
	std::cout << firstname << ' ' << lastname << '\n';
}

void Gunslinger::Show() const
{
	std::cout << "Gunslinger ";
	Person::Show();
	std::cout << "Draw time: " << time << '\n';
	std::cout << "Count of notches on the gun: " << notch << '\n';
}

void PokerPlayer::Show() const
{
	std::cout << "Poker player ";
	Person::Show();
}

void BadDude::Show() const
{
	std::cout << "Bad dude ";
	Person::Show();
	std::cout << "Draw time: " << Gdraw() << '\n';
}

double PokerPlayer::Draw() const
{
	srand(0);
	return 1 + rand() % 52;
}
