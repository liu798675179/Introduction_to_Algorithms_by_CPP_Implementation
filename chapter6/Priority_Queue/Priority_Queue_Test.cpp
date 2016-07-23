#include <iostream>
#include <random>
#include <vector>
#include "Priority_Queue.h"

using namespace std;

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (size_t i = 0; i != 100; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}


int main() {
	vector<long long> v1 = Random();
	Priority_Queue<long long> a(v1);

	a.pop();
	cout << a.size() << endl;
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}

	return 0;
}
