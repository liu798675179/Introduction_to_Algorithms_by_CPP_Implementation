#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e(time(nullptr));
	static uniform_int_distribution<long long> u(0, 99999);
	vector<long long>                          v1;

	for (auto i = 0; i != 100000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

void Counting_sort(vector<long long> &v1) {
	auto temp_v1 = v1;
	vector<long long> temp_count(v1.size(), 0);

	for (auto &j : v1) {
		++temp_count[j];
	}

	for (auto i = 1; i != temp_count.size(); ++i) {
		temp_count[i] += temp_count[i - 1];
	}

	for (auto j = v1.size() - 1; j != -1; --j) {
		temp_v1[temp_count[v1[j]] - 1] = v1[j];
		--temp_count[v1[j]];
	}

	v1 = temp_v1;
}

int main() {
	auto v1 = Random();
	Counting_sort(v1);

	for (auto &i : v1) {
		cout << i << " ";
	}

	return 0;
}
