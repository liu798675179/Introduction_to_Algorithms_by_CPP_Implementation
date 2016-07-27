#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (size_t i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

size_t Partition(vector<long long> &v1, size_t p, size_t r) {
	auto i = p - 1;
	for (auto j = p; j != r; ++j) {
		if (v1[j] <= v1[r]) {
			++i;
			swap(v1[i], v1[j]);
		}
	}
	swap(v1[i + 1], v1[r]);

	return i + 1;
}

void Quick_Sort(vector<long long> &v1, long long p, long long r) {
	if (p < r) {
		size_t q = Partition(v1, p, r);
		Quick_Sort(v1, p, q - 1);
		Quick_Sort(v1, q + 1, r);
	}
}

void Quick_Sort(vector<long long> &v1) {
	size_t b = 0, e = v1.size() - 1;
	Quick_Sort(v1, b, e);
}

int  main() {
	vector<long long> v1 = Random();
	Quick_Sort(v1);

	for (auto &i : v1) {
		cout << i << " ";
	}

	return 0;
}
