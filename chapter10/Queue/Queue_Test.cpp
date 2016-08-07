#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	Queue<int> a;
	a.push(5);

	a.push(6);
	cout << a.back() << endl;
	a.pop();
	cout << a.front() << endl;
	a.push(3);
	a.push(5);
	cout << a.size() << endl;

	while (!a.empty()) {
		cout << a.back() << " ";
		a.pop();
	}

	return 0;
}

