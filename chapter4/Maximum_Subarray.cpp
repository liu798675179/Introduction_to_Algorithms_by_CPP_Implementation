#include <iostream>
#include <vector>
#include <tuple>
#include <random>

using namespace std;

vector<int> Random() {
	static default_random_engine        e;               // Random-number engines.
	static uniform_int_distribution<int>
		                            u(-10, 10);      // Random-number distribution.
	vector<int>                         v1;              // Data structure.

	for (size_t i = 0; i != 100; ++i) {                  // Write to the need to sort the data.
		v1.push_back(u(e));
	}

	return v1;
}

tuple<size_t, size_t, int> Find_Max_crossing_Subarray(vector<int> &v1, size_t &low, size_t &mid, size_t &high) {
	int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
	size_t max_left = 0, max_right = 0;
	for (int i = mid; i >= 0; --i) {
		sum += v1[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for (size_t j = mid + 1; j != high + 1; ++j) {
		sum += v1[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	return{ max_left, max_right, left_sum + right_sum };
}

tuple<size_t, size_t, int> Find_Maximum_Subarray(vector<int> &v1, size_t &low, size_t &high) {
	if (high != low) {
		size_t mid = (low + high) / 2;
		tuple<size_t, size_t, int> left_max = Find_Maximum_Subarray(v1, low, mid);
		mid += 1;
		tuple<size_t, size_t, int> right_max = Find_Maximum_Subarray(v1, mid, high);
		mid -= 1;
		tuple<size_t, size_t, int> cross_max = Find_Max_crossing_Subarray(v1, low, mid, high);
		if (get<2>(left_max) >= get<2>(right_max) && get<2>(left_max) >= get<2>(cross_max)) {
			return left_max;
		}
		else if (get<2>(right_max) >= get<2>(left_max) && get<2>(right_max) >= get<2>(cross_max)) {
			return right_max;
		}
		else {
			return cross_max;
		}
	}
	else {
		return{ low, high, v1[low] };
	}
}

int main() {
	vector<int> v1= Random();
	size_t low = 0;
	size_t high = v1.size() - 1;
	tuple<size_t, size_t, int> a = Find_Maximum_Subarray(v1, low, high);
	for (auto &A : v1) {
		cout << A << " ";
	}
	cout << endl << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;
	cout << endl << endl;
	return 0;
}
