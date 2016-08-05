#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

long long Minimum(vector<long long> &v1) {
	auto min = v1[0];
	for (auto &i : v1) {
		if (min >= i) {
			min = i;
		}
	}

	return min;
}

long long Maximun(vector<long long> &v1) {
	auto max = v1[0];
	for (auto &i : v1) {
		if (max <= i) {
			max = i;
		}
	}

	return max;
}


int main() {
	vector<long long> v1 = Random();

	cout << Minimum(v1) << " " << Maximun(v1) << endl;

	return 0;
}
