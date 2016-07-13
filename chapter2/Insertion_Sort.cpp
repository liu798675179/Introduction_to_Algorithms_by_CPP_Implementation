#include <random>
#include <iostream>
#include <vector>

using namespace std;

void Insertion_Sort(vector<long long> &v1) {
	int k;
	long long temp_key;
	for (size_t j = 1; j != v1.size(); ++j) {            // Algorithm.
		temp_key = v1[j];
		k = j - 1;
		while (k >= 0 && v1[k] > temp_key) {
			v1[k + 1] = v1[k];
			--k;
		}
		v1[k + 1] = temp_key;
	}
}

vector<long long> Random() {
	static default_random_engine        e;               // Random-number engines.
	static uniform_int_distribution<unsigned long long>
	                                    u(0, 10000000);  // Random-number distribution.
	vector<long long>                   v1;              // Data structure.

	for (size_t i = 0; i != 10000; ++i) {                // Write to the need to sort the data.
		v1.push_back(u(e));
	}

	return v1;
}

int main(){
    vector<long long> v1 = Random();
	Insertion_Sort(v1);

	for (auto &temp : v1) {
	cout << temp << " ";
	}

	return 0;
}
