#include "HashTable.h"
#include "Product.h"

int main() {
	Ticket* products = new Ticket[8];//{ {12, "dsa", 1}, { 1,"dsa",1 }, { 1,"dsa",1 }, { 43,"dsa",1 }, { 87,"dsa",1 }, { 9,"dsa",1 }, { 10,"dsa",1 }, { 78,"dsa",1 } };
	for (int i = 0; i < 8; i++) products[i].enterInfo();
	std::cout << "Source array:";
	for (int i = 0; i < 8; i++) std::cout<<'\n' << products[i];
	std::cout << '\n';
	HashTable<Ticket> HT(products,8,10);
	HT.print();
	int choice;
	std::cout << "\nEnter value to search:";
	std::cin >> choice;
	if (HT.find(choice) < 0) std::cout << "\nNot found\n";
	return 0;
}