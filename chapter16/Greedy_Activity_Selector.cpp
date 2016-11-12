#include <iostream>
#include <vector>

using namespace std;

//Data.
vector<int> temp_VecS = { 0,1,3,0,5,3,5,6,8,8,2,12 }, temp_VecF = { 0,4,5,6,7,9,9,10,11,12,14,16 };

//Greedy.
vector<int> Greedy_Activity_Selector(vector<int> const &temp_VecS, vector<int> const &temp_VecF) {
	auto temp_n = temp_VecS.size() - 1;
	vector<int> temp_VecA = { 1 };
	auto temp_k = 1;

	for(auto temp_m = 1; temp_m <= temp_n; ++temp_m) {
		if(temp_VecS[temp_m] >= temp_VecF[temp_k]) {
			temp_VecA.push_back(temp_m);
			temp_k = temp_m;
		}
	}

	return temp_VecA;
}

int main() {
	auto temp_Vec = Greedy_Activity_Selector(temp_VecS, temp_VecF);

	for(auto &i : temp_Vec) {
		cout << "a" << i << " ";
	}

	return 0;
}
