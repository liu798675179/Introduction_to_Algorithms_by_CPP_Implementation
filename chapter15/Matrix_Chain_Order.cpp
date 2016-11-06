#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> temp_Vec{ 30,35,15,5,10,20,25 }; //A1(30X35), A2(35X15.).....A6(20X25)

pair<vector<vector<int>>, vector<vector<int>>> Matrix_Chain_Order(const vector<int> &temp_Vec) {
	auto temp_n = temp_Vec.size() - 1;
	vector<vector<int>> temp_VecM, temp_VecS;

	temp_VecM.resize(temp_n + 1);
	temp_VecS.resize(temp_n + 1);

	for(auto &i : temp_VecM) {
		i.resize(temp_n + 1);
	}
	for (auto &i : temp_VecS) {
		i.resize(temp_n + 1);
	}

	for(auto i = 1; i <= temp_n; ++i) {
		temp_VecM[i][i] = 0;
	}

	for(auto l = 2; l <= temp_n; ++l) {
		for (auto i = 1; i <= temp_n - l + 1; ++i) {
			auto j = i + l - 1;
			temp_VecM[i][j] = INT_MAX;

			for(auto k = i; k <= j - 1; ++k) {
				auto temp_q = temp_VecM[i][k] + temp_VecM[k + 1][j] + temp_Vec[i - 1] * temp_Vec[k] * temp_Vec[j];

				if(temp_q < temp_VecM[i][j]) {
					temp_VecM[i][j] = temp_q;
					temp_VecS[i][j] = k;
				}
			}
		}
	}

	return make_pair(temp_VecM, temp_VecS);
}

void Print_Optimal_Parens(const vector<vector<int>> &temp_VecS, const int &i, const int &j) {
	if(i == j) {
		cout << "A" << i << " ";
	}
	else {
		cout << "(" << " ";
		Print_Optimal_Parens(temp_VecS, i, temp_VecS[i][j]);
		Print_Optimal_Parens(temp_VecS, temp_VecS[i][j] + 1, j);
		cout << ")" << " ";
	}
}

int main() {
	pair<vector<vector<int>>, vector<vector<int>>> temp_Pair = Matrix_Chain_Order(temp_Vec);
	vector<vector<int>> temp_VecM = temp_Pair.first, temp_VecS = temp_Pair.second;

	cout << temp_VecM[2][5] << endl;

	Print_Optimal_Parens(temp_VecS, 2, 5);

	cout << endl << endl;
	for(auto &i : temp_VecM) {
		for(auto &j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
