#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

//Data.
vector<int> temp_VecP = { 0,17,2,3,4,5,6 }, temp_VecW = { 0,6,5,4,3,2,1 };

//Knapsack_Problem_01 by DP.
pair<vector<int>, vector<vector<int>>> Knapsack_Problem_01(vector<int> const &temp_VecP, vector<int> const &temp_VecW, int const &temp_w) {
	vector<int> temp_VecS;
	vector<vector<int>> temp_VecR;
	temp_VecS.resize(temp_VecP.size());
	temp_VecR.resize(temp_VecP.size());

	for(auto &i : temp_VecR) {
		i.resize(temp_w + 1);
	}

	//Solving the max price.
	for(auto i = 1; i != temp_VecP.size(); ++i) {
		for(auto j = 1; j <= temp_w; ++ j) {
			if(j < temp_VecW[i]) {
				temp_VecR[i][j] = temp_VecR[i - 1][j];
			}
			else {
				temp_VecR[i][j] = max(temp_VecR[i - 1][j - temp_VecW[i]] + temp_VecP[i], temp_VecR[i - 1][j]);
			}
		}
	}

	//Saving the result of each one.
	auto w = temp_w;
	for(auto i = temp_VecP.size() - 1; i >= 1; --i) {
		if(temp_VecR[i][w] > temp_VecR[i - 1][w]) {
			temp_VecS[i] = 1;
			w -= temp_VecW[i];
		}
		else {
			temp_VecS[i] = 0;
		}
	}

	return make_pair(temp_VecS, temp_VecR);
}

int main() {
	auto temp_Pair =  Knapsack_Problem_01(temp_VecP, temp_VecW, 10);

	for (auto &i : temp_Pair.first) {
		cout << i << " ";
	}
	cout << endl << endl;

	for(auto &i : temp_Pair.second) {
		for(auto &j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
