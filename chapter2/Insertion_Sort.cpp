#include <random>
#include <iostream>
#include <vector>

using namespace std;

void Insertion_Sort() {
	uniform_int_distribution<unsigned> u(0, 1000);  // Random-number distribution.
	default_random_engine              e;           // Random-number engines.
	vector<unsigned>                   v1;          // Data structure.
	unsigned                           temp_key;    // Temporary data variable
	int                                k;           // Temporary subscript variable.

	for (size_t i = 0; i != 10; ++i) {              // Write to the need to sort the data.
		v1.push_back(u(e));
	}

	for (size_t j = 1; j < v1.size(); ++j) {        // Algorithm.
		temp_key = v1[j];
		k = j - 1;
		while (k >= 0 && v1[k] > temp_key) {
			v1[k + 1] = v1[k];
			--k;
		}
		v1[k + 1] = temp_key;
	}

	for (auto &temp : v1) {                        // Output.
		cout << temp << " ";
	}
}
