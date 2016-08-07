#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack<int> a;
	a.push(5);

	a.push(6);
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.push(3);
	a.push(5);
	cout << a.size() << endl;

	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}

	return 0;
}
