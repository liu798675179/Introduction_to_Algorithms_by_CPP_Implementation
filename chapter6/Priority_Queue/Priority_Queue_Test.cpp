
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include "Priority_Queue.h"

using namespace std;

vector<long long> Random() {
	default_random_engine               e(time(nullptr));
	uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                   v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}


int main() {
	vector<long long> v1 = Random();
	Priority_Queue<long long> a(v1.begin(), v1.begin() + 10000);

	a.pop();
	cout << a.size() << endl;
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}

	return 0;
}
