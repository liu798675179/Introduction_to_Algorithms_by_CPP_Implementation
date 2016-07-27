#include <iostream>
#include <random>
#include <vector>

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

void Max_Heapify(vector<long long> &v1, size_t i, size_t length) {
	size_t l = 2 * i + 1;
	size_t r = 2 * i + 2;
	size_t largest = i;

	if (l < length && v1[l] > v1[i]) {
		largest = l;
	}
	if (r < length && v1[r] > v1[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(v1[i], v1[largest]);
		Max_Heapify(v1, largest, length);
	}
}

void Build_Max_Heap(vector<long long> &v1) {
	for (auto i = v1.size() / 2 - 1; i != -1; --i) {
		Max_Heapify(v1, i, v1.size() - 1);
	}
}

void Heap_Sort(vector<long long> &v1) {
	Build_Max_Heap(v1);
	for (auto i = v1.size() - 1; i != 0; --i) {
		swap(v1[0], v1[i]);
		Max_Heapify(v1, 0, i);
	}
}

int main() {
	vector<long long> v1 = Random();
	Heap_Sort(v1);

	for (auto &i : v1) {
		cout << i << " ";
	}

	return 0;
}
