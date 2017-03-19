#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <ctime>
#include <algorithm>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e(time(nullptr));
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

pair<long long, long long> Maximun_Minimum(vector<long long> &v1) {
	auto max = v1[0], min = v1[0];
	for (auto &i : v1) {
		if (min >= i) {
			min = i;
		}
		if (max <= i) {
			max = i;
		}
	}

	return make_pair(max, min);
}


int main() {
	auto v1 = Random();
	auto i = Maximun_Minimum(v1);

	cout << i.first << " " << i.second << endl;

	/*sort(v1.begin(), v1.end());

	for (auto &i : v1) {
	cout << i << " ";
	}*/

	return 0;
}
