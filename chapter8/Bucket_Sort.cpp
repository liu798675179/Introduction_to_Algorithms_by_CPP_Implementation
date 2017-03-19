#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

vector<double> Random() {
	static default_random_engine             e(time(nullptr));
	static uniform_real_distribution<double> u(0, 1);
	vector<double>                           v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

void Bucket_Sort(vector<double> &v1) {
	vector<vector<double>> bucket(10);

	for (auto &i : v1) {
		bucket[10 * i].push_back(i);
	}

	for (auto &i : bucket) {
		stable_sort(i.begin(), i.end());
	}

	v1.clear();

	for (auto &i : bucket) {
		v1.insert(v1.end(), i.begin(), i.end());
	}
}

int main() {
	auto v1 = Random();
	Bucket_Sort(v1);

	for (auto &i : v1) {
		cout << i << " ";
	}

	return 0;
}
