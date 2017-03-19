#include <iostream>
#include <vector>
#include <random>
#include <ctime>

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

void Merge(vector<long long> &v1, vector<long long> &temp_v, size_t p, size_t q, size_t r) {
	auto leftEnd = q - 1;
	auto tempPos = p;
	auto length = r - p + 1;

	while (p <= leftEnd && q <= r) {
		if (v1[p] <= v1[q])
			temp_v[tempPos++] = v1[p++];
		else
			temp_v[tempPos++] = v1[q++];
	}

	while (p <= leftEnd) {
		temp_v[tempPos++] = v1[p++];
	}

	while (q <= r) {
		temp_v[tempPos++] = v1[q++];
	}

	for (auto i = 0; i != length; ++i, --r) {
		v1[r] = temp_v[r];
	}
}

void Merge_Sort(vector<long long> &v1, vector<long long> &temp_v, size_t p, size_t r) {
	if (p < r) {
		auto q = (p + r) / 2;
		Merge_Sort(v1, temp_v, p, q);
		Merge_Sort(v1, temp_v, (q + 1), r);
		Merge(v1, temp_v, p, (q + 1), r);
	}
}

void Merge_Sort(vector<long long> &v1) {
	vector<long long> temp_v(v1.size());
	Merge_Sort(v1, temp_v, 0, (v1.size() - 1));
}

int main() {
	auto v1 = Random();
	Merge_Sort(v1);

	for (auto &temp : v1)
		cout << temp << " ";

	return 0;
}
