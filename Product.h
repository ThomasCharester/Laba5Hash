#pragma once
#ifndef PRODUCT
#define PRODUCT

#include <string>
#include <iostream>

#define nullProduct Ticket()

struct Ticket {
	std::string destination;
	int flightNum;
	int time;
	void enterInfo() {
		std::cout << "\nEnter destination : ";
		std::cin.ignore();
		std::cin >> destination;
		std::cout << "\nEnter flight number : ";
		std::cin.ignore();
		std::cin >> flightNum;
		std::cout << "\nEnter start time : ";
		std::cin.ignore();
		std::cin >> time;
		std::cout << '\n';
	}
	Ticket(int flightNum = -1, std::string destination = "", int time = -1) {
		this->flightNum = flightNum;
		this->destination = destination;
		this->time = time;
	}
	Ticket& operator = (const Ticket& product)
	{
		flightNum = product.flightNum;
		destination = product.destination;
		time = product.time;
		return *this;   // возвращаем ссылку на текущий объект
	}
	bool operator == (const Ticket& product) const
	{
		return flightNum == product.flightNum;
	}
	bool operator != (const Ticket& product) const
	{
		return flightNum != product.flightNum;
	}
	bool operator > (const Ticket& product) const
	{
		return flightNum > product.flightNum;
	}
	bool operator < (const Ticket& product) const
	{
		return flightNum < product.flightNum;
	}
	Ticket& operator = (const int& number)
	{
		flightNum = number;
		destination = "";
		time = number;
		return *this;   // возвращаем ссылку на текущий объект
	}
	bool operator == (const int& number) const
	{
		return flightNum == number;
	}
	bool operator != (const int& number) const
	{
		return flightNum != number;
	}
	bool operator > (const int& number) const
	{
		return flightNum > number;
	}
	bool operator < (const int& number) const
	{
		return flightNum < number;
	}
	int operator %(const int& number) {
		return flightNum % number;
	}
	friend std::ostream& operator << (std::ostream& os, const Ticket& person);
	operator int() const { return flightNum; }
};

std::ostream& operator << (std::ostream& os, const Ticket& person)
{
	return os << person.flightNum << ' ' << person.destination << ' ' << person.time;
}
#endif // !PRODUCT
