#include <iostream>
#include "Hash_Table.h"

using namespace std;

int main() {
	Dbl_HashTable<int, int> a;
	Sgl_HashTable<int> b;
	b.insert(78);
	b.insert(96);
	b.insert(96);
	b.insert(96);
	b.erase(96);
	b.insert(79);
	b.erase_one(55);
	a.insert(56, 7);
	a.insert(78, 6);
	a.insert(96, 9);
	a.insert(56, 9);
	a.erase(56);
	a.erase_one(99);

	return 0;
}
