#include <iostream>
#include "List.h"

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
	a.print();
	cout << endl;
	cout << a.size() << endl;
	cout << a.front() << endl;
	cout << a.back() << endl;
	return 0;
}
