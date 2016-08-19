#include "Red_Black_Tree.h"

using namespace std;

int main()
{
	RBT<int> RBTree;
	for (auto i = 1; i <= 100; ++i) {
		RBTree.Insert(i);
	}
	for (auto i = 1; i <= 50; ++i) {
		RBTree.Delete(i);
	}

	RBTree.Preorder_Tree_Walk();

	cout << RBTree.Tree_Hight() << endl;

	return 0;
}
