#include <iostream>
#include "List.h"
#include <initializer_list>

using namespace std;

int main() {
	List<int> a;
	for (int c = 0; c < 100; ++c) {
		a.push_back(c);
		a.push_front(6);
	}
	a.pop_back();
	a.erase(a.begin());
	int f = 5;
	a.erase(a.begin() + f, --a.end() - 1);
	a.resize(7);
	a.sort();
	a.print();
	cout << endl;
	cout << a.size() << endl;
	cout << a.front() << endl;
	cout << a.back() << endl;
	List<int> b = a;
	initializer_list<int> il{ 5, 3, 9 };
	List<int> c;
	for (auto &i : il) {
		c.push_back(i);
	}
	cout << *(a.search(6));
	return 0;
}
