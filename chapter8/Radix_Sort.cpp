//Tan Chuanqi's thought.   chuanqi.tan@gmail.com

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(0, 99999);
	vector<long long>                          v1;

	for (auto i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

auto max_dim = 5;

void Radix_Sort(vector<long long> &v1, long long dim) { 
	stable_sort(v1.begin(), v1.end(), [&dim](long long temp_1, long long temp_2) {
		auto Dim_Num = [](long long &temp_num, long long &d) -> long long {
			for (auto i = 1; i <= max_dim - d; ++i) {
				temp_num /= 10;
			}
			return temp_num % 10;
		};
		return Dim_Num(temp_1, dim) < Dim_Num(temp_2, dim);
	});

	if (dim != 1) {
		Radix_Sort(v1, dim - 1);
	}
}

int main() {
	auto v1 = Random();
	Radix_Sort(v1, max_dim);

	for (auto &i : v1) {
		cout << i << " ";
	}

	return 0;
}
