#include <iostream>
#include <vector>
#include <random>

using namespace std;

void Bubble_Sort(vector<long long> &v1) {
	for (auto i = 1; i != v1.size(); ++i) {
		for (auto j = v1.size() - 1; j != i - 1; --j) {
			if (v1[j] < v1[j - 1]) {
				swap(v1[j], v1[j - 1]);
			}
		}
	}
}

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

int main() {
	vector<long long> v1 = Random();
	Bubble_Sort(v1);

	for (auto & i : v1)
		cout << i << " ";

	return 0;
}
