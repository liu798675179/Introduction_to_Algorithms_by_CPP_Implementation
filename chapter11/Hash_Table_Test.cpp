#include <iostream>
#include "Hash_Table.h"

using namespace std;

int main() {
	Dbl_HashTable<int, int> a;
	Sgl_HashTable<int> b;
	b.insert(78);
	b.insert(96);
	b.insert(96);
	b.erase(55);
	a.insert(56, 7);
	a.insert(78, 6);
	a.insert(96, 9);
	a.erase(75);

	return 0;
}
