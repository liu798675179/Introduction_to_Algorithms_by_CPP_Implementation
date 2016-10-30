#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Price{ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

//Recursion.
int Cut_Rod_Recursion(const vector<int> &temp_Vec, const size_t &temp_n) {
	if (temp_n == 0) {
		return 0;
	}

	auto temp_q = INT_MIN;

	for (auto i = 1; i <= temp_n; ++i) {
		temp_q = max(temp_q, temp_Vec[i] + Cut_Rod_Recursion(temp_Vec, temp_n - i));
	}

	return temp_q;
}

//Top-down with memoization of part 1.
int Memoized_Cut_Rod_Aux(const vector<int> &temp_Vec, const size_t &temp_n, vector<int> &temp_VecR) {
	auto temp_q = INT_MIN;

	if (temp_VecR[temp_n] >= 0) {
		return temp_VecR[temp_n];
	}

	if (temp_n != 0) {
		for (auto i = 1; i <= temp_n; ++i) {
			temp_q = max(temp_q, temp_Vec[i] + Memoized_Cut_Rod_Aux(temp_Vec, temp_n - i, temp_VecR));
		}
	}
	else {
		temp_q = 0;
	}

	temp_VecR[temp_n] = temp_q;

	return temp_q;
}

//Top-down with memoization of part 2.
int Memoized_Cut_Rod(const vector<int> &temp_Vec, const size_t &temp_n) {
	vector<int> temp_VecR;
	temp_VecR.resize(temp_n + 1);

	for (auto &i : temp_VecR) {
		i = INT_MIN;
	}

	return Memoized_Cut_Rod_Aux(temp_Vec, temp_n, temp_VecR); 
	 
}

//Bottom-up method.
int Boyyom_Up_Cut_Rod(const vector<int> &temp_Vec, const size_t &temp_n) {
	vector<int> temp_VecR;
	temp_VecR.resize(temp_n + 1);
	temp_VecR[0] = 0;

	for (auto j = 1; j <= temp_n; ++j) {
		auto temp_q = INT_MIN;

		for (auto i = 1; i <= j; ++i) {
			temp_q = max(temp_q, temp_Vec[i] + temp_VecR[j - i]);
		}

		temp_VecR[j] = temp_q;
	}
	
	return temp_VecR[temp_n];
}

//Extended version of bottom-up method.
void Extended_Bottom_Up_Cut_Rod(const vector<int> &temp_Vec, const size_t &temp_n) {
	vector<int> temp_VecR, temp_VecS;
	temp_VecR.resize(temp_n + 1);
	temp_VecS.resize(temp_n + 1);
	temp_VecR[0] = 0;

	for (auto j = 1; j <= temp_n; ++j) {
		auto temp_q = INT_MIN;

		for (auto i = 1; i <= j; ++i) {
			if (temp_q < temp_Vec[i] + temp_VecR[j - i]) {
				temp_q = temp_Vec[i] + temp_VecR[j - i];
				temp_VecS[j] = i;
			}
		}

		temp_VecR[j] = temp_q;
	}

	cout << temp_VecR[temp_n] << " ";

	auto n = temp_n;
	while (n > 0) {
		cout << temp_VecS[n];
		n -= temp_VecS[n];
	}
}

int main() {
	auto temp_n = 6;

	cout << Cut_Rod_Recursion(Price, temp_n) << endl;
	cout << Memoized_Cut_Rod(Price, temp_n) << endl;
	cout << Boyyom_Up_Cut_Rod(Price, temp_n) << endl;
	Extended_Bottom_Up_Cut_Rod(Price, temp_n);

	return 0;
}
