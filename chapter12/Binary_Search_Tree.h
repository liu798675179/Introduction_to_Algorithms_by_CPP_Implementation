#ifndef BIANRY_SEARCH_TREE_H
#define BIANRY_SEARCH_TREE_H

#include <memory>
#include <utility>
#include <stdexcept>
#include <functional>

using std::shared_ptr;
using std::pair;

template<typename T>
class BST { 
public:
	struct Node{
		Node() = default;
		Node(const pair<size_t, T> &d, const shared_ptr<Node> &l, const shared_ptr<Node> &r, const shared_ptr<Node> &p) :
			data(d), left(l), right(r), parent(p) {}

		pair<size_t, T> data;
		shared_ptr<Node> left = nullptr;
		shared_ptr<Node> right = nullptr;
		shared_ptr<Node> parent = nullptr;
	};

	shared_ptr<Node> Root = nullptr;

public:
	BST() = default;
	~BST() = default;

	size_t Hash_Val(const T &x) {
		return std::hash<T>()(x);
	}

	void Inorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != nullptr) {
			Inorder_Tree_Walk(p->left);
			cout << p->data.second << " ";
			Inorder_Tree_Walk(p->right);
		}
	}
	void Inorder_Tree_Walk() {
		auto p = Root;
		if (p != nullptr) {
			Inorder_Tree_Walk(p->left);
			cout << p->data.second << " ";
			Inorder_Tree_Walk(p->right);
		}
	}
	void Preorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != nullptr) {
			cout << p->data.second << " ";
			Preorder_Tree_Walk(p->left);
			Preorder_Tree_Walk(p->right);
		}
	}
	void Preorder_Tree_Walk() {
		auto p = Root;
		if (p != nullptr) {
			cout << p->data.second << " ";
			Preorder_Tree_Walk(p->left);
			Preorder_Tree_Walk(p->right);
		}
	}
	void Postorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != nullptr) {
			Postorder_Tree_Walk(p->left);
			Postorder_Tree_Walk(p->right);
			cout << p->data.second << " ";
		}
	}
	void Postorder_Tree_Walk() {
		auto p = Root;
		if (p != nullptr) {
			Postorder_Tree_Walk(p->left);
			Postorder_Tree_Walk(p->right);
			cout << p->data.second << " ";
		}
	}

	shared_ptr<Node> Search(const T &x) {
		auto temp = Hash_Val(x);
		auto p = Root;
		while (p != nullptr && temp != p->data.first) {
			if (temp < p->data.first) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		try {
			if (p == nullptr) {
				throw std::runtime_error("The element was not found.");
			}
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
		}
		return p;
	}

	shared_ptr<Node> Tree_Maximum() {
		auto p = Root;
		while (p->right != nullptr) {
			p = p->right;
		}

		return p;
	}

	shared_ptr<Node> Tree_Minimum() {
		auto p = Root;
		while (p->left != nullptr) {
			p = p->left;
		}

		return p;
	}

	shared_ptr<Node> Tree_Successor(const T &x) {
		auto p = Search(x);
		if (p->right != nullptr) {
			return Tree_Successor(p->right->data.second);
		}

		auto y = p->parent;
		while (y != nullptr && p == y->right) {
			p = y;
			y = y->parent;
		}

		return y;
	}

	shared_ptr<Node> Tree_Predecessor(const T &x) {
		auto p = Search(x);
		if (p->left != nullptr) {
			return Tree_Predecessor(p->left->data.second);
		}

		auto y = p->parent;
		while (y != nullptr && p == y->left) {
			p = y;
			y = y->parent;
		}

		return y;
	}

	void Transplant(const shared_ptr<Node> &p1, const shared_ptr<Node> &P2) {
		if (p1->parent == nullptr) {
			Root = P2;
		}
		else if (p1 == p1->parent->left) {
			p1->parent->left = P2;
		}
		else {
			p1->parent->right = P2;
		}
		if (P2 != nullptr) {
			P2->parent == p1->parent;
		}
	}

	void Insert(const T &x) {
		auto temp = Hash_Val(x);
		shared_ptr<Node> New = std::make_shared<Node>(std::make_pair(temp, x), nullptr, nullptr, nullptr);
		shared_ptr<Node> Py = nullptr;
		auto Px = Root;

		while (Px != nullptr) {
			Py = Px;
			if (temp < Px->data.first) {
				Px = Px->left;
			}
			else {
				Px = Px->right;
			}
		}

		New->parent = Py;
		if (Py == nullptr) {
			Root = New;
		}
		else if (temp < Py->data.first) {
			Py->left = New;
		}
		else {
			Py->right = New;
		}
	}

	void Delete(const T &x) {
		auto p = Search(x);
		if (p != nullptr) {
			if (p->left == nullptr) {
				Transplant(p, p->right);
			}

			else if (p->right == nullptr) {
				Transplant(p, p->left);
			}
			else {
				auto Py = Tree_Successor(p->right->data.second);
				if (Py->parent != p) {
					Transplant(Py, Py->right);
					Py->right = p->right;
					Py->right->parent = Py;
				}
				Transplant(p, Py);
				Py->left = p->left;
				Py->left->parent = Py;
			}
		}
	}

	size_t Tree_Hight(const shared_ptr<Node> &p) {
		if (p != nullptr) {
			size_t left = Tree_Hight(p->left);
			size_t right = Tree_Hight(p->right);
			if (left > right) {
				return left + 1;
			}
			else {
				return right + 1;
			}
		}
		else {
			return 0;
		}
	}

	size_t Tree_Hight() {
		return Tree_Hight(Root);
	}

};

#endif // !BIANRY_SEARCH_TREE_H
