#include <iostream>
#include "Bianry_Search_Tree.h"

using namespace std;

int main() {
	BST<int> a;
	for (auto i = 0; i <= 100; ++i) {
		a.Insert(i);
	}
	a.Delete(101);
	a.Inorder_Tree_Walk();
	//a.Preorder_Tree_Walk();
	//a.Postorder_Tree_Walk();
	cout << endl << a.Tree_Maximum()->data.second << endl;
	cout << a.Tree_Hight() << endl;

	return 0;
}
