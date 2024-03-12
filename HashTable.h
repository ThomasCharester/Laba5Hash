#pragma once
#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <math.h>

template<typename T>
class HashTable {
public:
	HashTable(T* array, int nArraySize, int mTableSize) {
		this->array = array;
		this->mTableSize = mTableSize;
		this->nArraySize = nArraySize;
		table = new T[mTableSize];
		for (int i = 0; i < mTableSize; i++) table[i] = -1;
		for (int i = 0; i < nArraySize; i++) hashify(array[i]);
	}
	void hashify(T data) {
		if (find(data) > 0) return;
		int i = std::abs(data % mTableSize);
		if (table[i] != -1)
			while (table[i] != -1)
			{
				/*i++;
				if (i == mTableSize) i = 0;*/
				int c = 1 + (data % (mTableSize - 2));
				i = i - c;
				if (i < 0) i = i + mTableSize;
			}
		table[i] = data;
	}
	int find(T data) {
		int i = std::abs(data % mTableSize);
		while (table[i] != -1)
		{
			if (table[i] == data) { 
				std::cout << "\nFound it is " << table[i]<< " at "<<i<<" in hash table";
				return i;
			}
			/*i++;
			if (i >= mTableSize) i = 0;*/

			int c = 1 + (data % (mTableSize - 2));
			i = i - c;
			if (i < 0) i = i + mTableSize;
		}
		
		return -1;
	}
	void print() {
		std::cout << "\nHash table:";
		for (int i = 0; i < mTableSize; i++) {
			std::cout << '\n' << table[i];
		}
	}
private:
	T* table;
	T* array;
	int mTableSize;
	int nArraySize;
};
#endif // !HASHTABLE
