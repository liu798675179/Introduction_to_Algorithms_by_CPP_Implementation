#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<double> temp_dblP = { 0.0,0.15,0.10,0.05,0.10,0.20 }, temp_dblQ = { 0.05,0.10,0.05,0.05,0.05,0.10 };

//Just Memoized of Optimal_BST
pair<vector<vector<double>>, vector<vector<int>>> 
Optimal_BST(const vector<double> &temp_dblP, const vector<double> &temp_dblQ, const int &temp_n) {
	vector<vector<double>> temp_VecE, temp_VecW;
	vector<vector<int>> temp_VecRoot;

	temp_VecE.resize(temp_n + 2);
	temp_VecW.resize(temp_n + 2);
	temp_VecRoot.resize(temp_n + 1);

	for(auto &i : temp_VecE) {
		i.resize(temp_n + 1);
	}
	for(auto &i : temp_VecW) {
		i.resize(temp_n + 1);
	}
	for(auto &i : temp_VecRoot) {
		i.resize(temp_n + 1);
	}

	for(auto i = 1; i <= temp_n + 1; ++i) {
		temp_VecE[i][i - 1] = temp_dblQ[i - 1];
		temp_VecW[i][i - 1] = temp_dblQ[i - 1];
	}

	for(auto l = 1; l <= temp_n; ++l) {
		for (auto i = 1; i <= temp_n - l + 1; ++i) {
			auto j = i + l - 1;
			temp_VecE[i][j] = DBL_MAX;
			temp_VecW[i][j] = temp_VecW[i][j - 1] + temp_dblP[j] + temp_dblQ[j];

			for (auto r = i; r <= j; ++r) {
				auto temp_t = temp_VecE[i][r - 1] + temp_VecE[r + 1][j] + temp_VecW[i][j];
				if(temp_t < temp_VecE[i][j]) {
					temp_VecE[i][j] = temp_t;
					temp_VecRoot[i][j] = r;
				}
			}
		}
	}

	return make_pair(temp_VecE, temp_VecRoot);
}

int main() {
	auto temp_pair = Optimal_BST(temp_dblP, temp_dblQ, 5);

	for(auto &i : temp_pair.first) {
		for(auto &j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto &i : temp_pair.second) {
		for (auto &j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
