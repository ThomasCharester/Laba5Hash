#include "HashTable.h"
#include "Product.h"

int main() {
	Product* products = new Product[5]{ {11,"name",1},{21,"name",1},{32,"name",1},{56,"name",1},{9,"name",1} };

	HashTable<Product> HT(products,5,10);
	HT.print();
	return 0;
}