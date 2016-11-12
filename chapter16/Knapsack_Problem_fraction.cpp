#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//Data.
vector<int> temp_VecP = { 0,60,100,120 }, temp_VecW = { 0,10,20,30 };

//Knapsack_Problem_fraction by Greedy.
pair<vector<pair<int, int>>, int> Knapsack_Problem_fraction(vector<int> const &temp_VecP, vector<int> const &temp_VecW, int const &temp_w) {
	vector<pair<int, int>> temp_VecPair;
	auto temp_v = 0, temp_c = 0;

	for(auto i = 1; i != temp_VecP.size(); ++i) {
		if(temp_VecW[i] + temp_c >= temp_w) {
			temp_VecPair.push_back(make_pair(temp_VecP[i], temp_w - temp_c));
			temp_v += (temp_w - temp_c) * (temp_VecP[i] / temp_VecW[i]);
			return make_pair(temp_VecPair, temp_v);
		}
		temp_VecPair.push_back(make_pair(temp_VecP[i], temp_VecW[i]));
		temp_v += temp_VecP[i];
		temp_c += temp_VecW[i];
	}

	return make_pair(temp_VecPair, temp_v);
}

int main() {
	auto temp_VecPair = Knapsack_Problem_fraction(temp_VecP, temp_VecW, 50);
	cout << temp_VecPair.second << endl;

	for(auto &i : temp_VecPair.first) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}
