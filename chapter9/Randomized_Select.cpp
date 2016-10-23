#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

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

size_t Random_Partition(vector<long long> &v1, size_t p, size_t r) {

	auto ri = p + rand() % (r - p + 1);
	swap(v1[ri], v1[r]);

	auto i = p - 1;
	for (auto j = p; j != r; j++) {
		if (v1[j] <= v1[r]) {
			++i;
			swap(v1[i], v1[j]);
		}
	}
	swap(v1[i + 1], v1[r]);

	return i + 1;
}

long long Randomized_Select(vector<long long> &v1, size_t p, size_t r, size_t i) {
	if (p == r) {
		return v1[p];
	}

	auto q = Random_Partition(v1, p, r);
	auto k = q - p + 1;

	if (i == k) {
		return v1[q];
	}
	else if (i < k) {
		return Randomized_Select(v1, p, q - 1, i);
	}
	else {
		return Randomized_Select(v1, q + 1, r, i - k);
	}

}

long long Randomized_Select(vector<long long> &v1, long long i) {
	return Randomized_Select(v1, 0, v1.size() - 1, i);
}

int main() {
	vector<long long> v1 = Random();

	cout << Randomized_Select(v1, 1) << endl;

	/*sort(v1.begin(), v1.end());
	for (auto &i : v1) {
	cout << i << " ";
	}*/

	return 0;
}
