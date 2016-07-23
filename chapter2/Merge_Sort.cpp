#include <iostream>
#include <vector>
#include <random>

using namespace std;

void Merge(vector<long long> &temp_v, vector<long long> &tempArray, size_t p, size_t q, size_t r) {
	size_t leftEnd = q - 1;
	size_t tempPos = p;
	size_t numElements = r - p + 1;

	while (p <= leftEnd && q <= r) {
		if (temp_v[p] <= temp_v[q])
			tempArray[tempPos++] = temp_v[p++];
		else
			tempArray[tempPos++] = temp_v[q++];
	}

	while (p <= leftEnd) {
		tempArray[tempPos++] = temp_v[p++];
	}

	while (q <= r) {
		tempArray[tempPos++] = temp_v[q++];
	}

	for (size_t i = 0; i != numElements; ++i, --r) {
		temp_v[r] = tempArray[r];
	}
}

void Merge_Sort(vector<long long> &temp_v, vector<long long> &tempArray, size_t p, size_t r) {
	if (p < r) {
		size_t q = (p + r) / 2;        
		Merge_Sort(temp_v, tempArray, p, q);
		Merge_Sort(temp_v, tempArray, (q + 1), r);
		Merge(temp_v, tempArray, p, (q + 1), r);
	}
}

void Merge_Sort(vector<long long> &temp_v) {
	vector<long long> tempArray(temp_v.size());
	Merge_Sort(temp_v, tempArray, 0, (temp_v.size() - 1));
}

vector<long long> Random() {
	static default_random_engine               e;
	static uniform_int_distribution<long long> u(-100000000, 100000000);
	vector<long long>                          v1;

	for (size_t i = 0; i != 10000; ++i) {
		v1.push_back(u(e));
	}

	return v1;
}

int main() {
	vector<long long> v1 = Random();
	Merge_Sort(v1);

	for (auto & i : v1)
		cout << i << " ";

	return 0;
}
