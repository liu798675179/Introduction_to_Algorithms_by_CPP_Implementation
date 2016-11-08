#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace  std;

string temp_strX = { "#AGCTCCACG" }, temp_strY = { "#AGCAAAGCGT" }; //AGCTCCACG & AGCAAAGCGT

//Memoized of Lcs
pair<vector<vector<int>>,vector<vector<int>>> Lcs_Length(const string &temp_strX, const string &strY) {
	auto temp_m = temp_strX.size() - 1, temp_n = temp_strY.size() - 1;
	vector<vector<int>> temp_VecB, temp_VecC;

	temp_VecB.resize(temp_m + 1);
	temp_VecC.resize(temp_m + 1);

	for(auto &i : temp_VecB) {
		i.resize(temp_n + 1);
	}
	for(auto &i : temp_VecC) {
		i.resize(temp_n + 1);
	}

	for(auto i = 1; i <= temp_m; ++i) {
		temp_VecC[i][0] = 0;
	}
	for(auto j = 0; j <= temp_n; ++j) {
		temp_VecC[0][j] = 0;
	}

	for(auto i = 1; i <= temp_m; ++i) {
		for(auto j = 1; j <= temp_n; ++j) {
			if(temp_strX[i] == temp_strY[j]) {
				temp_VecC[i][j] = temp_VecC[i - 1][j - 1] + 1;
				temp_VecB[i][j] = -1;
			}
			else if(temp_VecC[i - 1][j] >= temp_VecC[i][j - 1]) {
				temp_VecC[i][j] = temp_VecC[i - 1][j];
				temp_VecB[i][j] = -2;
			}
			else {
				temp_VecC[i][j] = temp_VecC[i][j - 1];
				temp_VecB[i][j] = -3;
			}
		}
	}

	return make_pair(temp_VecC, temp_VecB);
}

//Print
void Print_Lcs(const vector<vector<int>> & temp_VecB, const string &temp_strX, const size_t &i, const size_t &j) {
	if(i == 0 || j == 0) {
		return;
	}

	if(temp_VecB[i][j] == -1) {
		Print_Lcs(temp_VecB, temp_strX, i - 1, j - 1);
		cout << temp_strX[i];
	}
	else if(temp_VecB[i][j] == -2) {
		Print_Lcs(temp_VecB, temp_strX, i - 1, j);
	}
	else {
		Print_Lcs(temp_VecB, temp_strX, i, j - 1);
	}
}

int main() {
	auto temp_pair = Lcs_Length(temp_strX, temp_strY);
	Print_Lcs(temp_pair.second, temp_strX, temp_strX.size() - 1, temp_strY.size() - 1);

	return 0;
}
