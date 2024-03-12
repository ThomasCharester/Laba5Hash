#pragma once
#ifndef PRODUCT
#define PRODUCT

#include <string>
#include <iostream>

struct Product {
	std::string name;
	int price;
	int dateOfProduction;

	Product(int price = -1, std::string name = "", int dateOfProduction = -1) {
		this->price = price;
		this->name = name;
		this->dateOfProduction = dateOfProduction;
	}
	Product& operator = (const Product& product)
	{
		price = product.price;
		name = product.name;
		dateOfProduction = product.dateOfProduction;
		return *this;   // возвращаем ссылку на текущий объект
	}
	bool operator == (const Product& product) const
	{
		return price == product.price;
	}
	bool operator != (const Product& product) const
	{
		return price != product.price;
	}
	bool operator > (const Product& product) const
	{
		return price > product.price;
	}
	bool operator < (const Product& product) const
	{
		return price < product.price;
	}
	Product& operator = (const int& number)
	{
		price = number;
		name = "";
		dateOfProduction = number;
		return *this;   // возвращаем ссылку на текущий объект
	}
	bool operator == (const int& number) const
	{
		return price == number;
	}
	bool operator != (const int& number) const
	{
		return price != number;
	}
	bool operator > (const int& number) const
	{
		return price > number;
	}
	bool operator < (const int& number) const
	{
		return price < number;
	}
	int operator %(const int& number) {
		return price % number;
	}
	friend std::ostream& operator << (std::ostream& os, const Product& person);
	operator int() const { return price; }
};

std::ostream& operator << (std::ostream& os, const Product& person)
{
	return os << person.price << ' ' << person.name << ' ' << person.dateOfProduction;
}
#endif // !PRODUCT
