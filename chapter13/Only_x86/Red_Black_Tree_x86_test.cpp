#include "Red_Black_Tree_x86.h"

using namespace std;

int main() {
	RBT<int> RBTree;
	for (auto i = 0; i <= 100; ++i) {
		RBTree.Insert(i);
	}
	for (auto i = 0; i <= 50; ++i) {
		RBTree.Delete(i);
	}
	RBTree.Preorder_Tree_Walk();

	cout << RBTree.Tree_Hight() << endl;

	return 0;
}
