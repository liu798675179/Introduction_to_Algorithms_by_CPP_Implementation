#include <iostream>
#include <vector>
#include <random>

using namespace std;

void Bubble_Sort(vector<long long> &v1) {
	for (size_t i = 1; i != v1.size(); ++i) {
		for (size_t j = v1.size() - 1; j != i - 1; --j) {
			if (v1[j] < v1[j - 1]) {
				swap(v1[j], v1[j - 1]);
			}
		}
	}
}

vector<long long> Random() {
	static default_random_engine        e;               // Random-number engines.
	static uniform_int_distribution<unsigned long long>
		                                u(0, 10000000);  // Random-number distribution.
	vector<long long>                   v1;              // Data structure.

	for (size_t i = 0; i != 10000; ++i) {                // Write to the need to sort the data.
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
