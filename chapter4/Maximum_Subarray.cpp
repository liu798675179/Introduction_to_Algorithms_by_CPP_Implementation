#include <iostream>
#include <vector>
#include <tuple>
#include <random>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (auto i = 0; i != 1000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

tuple<size_t, size_t, long long> Find_Max_crossing_Subarray(vector<long long> &v1, size_t &low, size_t &mid, size_t &high) {
	long long left_sum = LONG_MIN, right_sum = LONG_MIN, sum = 0;
	size_t max_left = 0, max_right = 0;
	for (long long i = mid; i >= 0; --i) {
		sum += v1[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for (auto j = mid + 1; j != high + 1; ++j) {
		sum += v1[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	return{ max_left, max_right, left_sum + right_sum };
}

tuple<size_t, size_t, long long> Find_Maximum_Subarray(vector<long long> &v1, size_t &low, size_t &high) {
	if (high != low) {
		auto mid = (low + high) / 2;
		auto left_max = Find_Maximum_Subarray(v1, low, mid);
		mid += 1;
		auto right_max = Find_Maximum_Subarray(v1, mid, high);
		mid -= 1;
		auto cross_max = Find_Max_crossing_Subarray(v1, low, mid, high);

		if (get<2>(left_max) >= get<2>(right_max) && get<2>(left_max) >= get<2>(cross_max)) {
			return left_max;
		}
		if (get<2>(right_max) >= get<2>(left_max) && get<2>(right_max) >= get<2>(cross_max)) {
			return right_max;
		}
		return cross_max;
	}
	return{ low, high, v1[low] };
}

int main() {
	auto v1 = Random();
	size_t low = 0;
	auto high = v1.size() - 1;
	auto a = Find_Maximum_Subarray(v1, low, high);

	for (auto &temp : v1) {
		cout << temp << " ";
	}
	cout << endl << endl << " begin: " << get<0>(a) << " " << " end: " << get<1>(a) << " " << " sum: " << get<2>(a) << endl << endl;

	return 0;
}
