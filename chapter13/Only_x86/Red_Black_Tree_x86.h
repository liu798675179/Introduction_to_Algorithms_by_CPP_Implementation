#ifndef RED_BLACK_TREE_X86_H
#define RED_BLACK_TREE_X86_H

#include <iostream>
#include <memory>
#include <utility>
#include <stdexcept>
#include <functional>

using std::shared_ptr;
using std::pair;
using std::cout;
using std::endl;

template<typename T>
class RBT {
private:
	enum Color { Red, Black };

	struct Node {
		Node() = default;
		Node(const Color &c) : color(c) {}
		Node(const pair<size_t, T> &d, const Color &c, const shared_ptr<Node> &p, const shared_ptr<Node> &l, const shared_ptr<Node> &r) :
			data(d), color(c), parent(p), left(l), right(r) {}

		pair<size_t, T> data;
		Color color;
		shared_ptr<Node> parent = nullptr;
		shared_ptr<Node> left = nullptr;
		shared_ptr<Node> right = nullptr;
	};

	shared_ptr<Node> NIL = std::make_shared<Node>(Black);
	shared_ptr<Node> Root = NIL;

public:
	RBT() = default;
	~RBT() = default;

	size_t Hash_Val(const T &x) {
		return std::hash<T>()(x);
	}

	void Inorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != NIL) {
			Inorder_Tree_Walk(p->left);
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
			Inorder_Tree_Walk(p->right);
		}
	}
	void Inorder_Tree_Walk() {
		auto p = Root;
		if (p != NIL) {
			Inorder_Tree_Walk(p->left);
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
			Inorder_Tree_Walk(p->right);
		}
	}
	void Preorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != NIL) {
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
			Preorder_Tree_Walk(p->left);
			Preorder_Tree_Walk(p->right);
		}
	}
	void Preorder_Tree_Walk() {
		auto p = Root;
		if (p != NIL) {
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
			Preorder_Tree_Walk(p->left);
			Preorder_Tree_Walk(p->right);
		}
	}
	void Postorder_Tree_Walk(const shared_ptr<Node> &p) {
		if (p != NIL) {
			Postorder_Tree_Walk(p->left);
			Postorder_Tree_Walk(p->right);
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
		}
	}
	void Postorder_Tree_Walk() {
		auto p = Root;
		if (p != NIL) {
			Postorder_Tree_Walk(p->left);
			Postorder_Tree_Walk(p->right);
			cout << p->data.second << " ";
			if (p->color == Black)
				cout << "Black " << endl;
			else
				cout << "Red " << endl;
		}
	}

	shared_ptr<Node> Tree_Successor(const T &x) {
		auto p = Search(x);
		if (p->right != NIL) {
			return Tree_Successor(p->right->data.second);
		}

		auto y = p->parent;
		while (y != NIL && p == y->right) {
			p = y;
			y = y->parent;
		}

		return y;
	}

	shared_ptr<Node> Tree_Predecessor(const T &x) {
		auto p = Search(x);
		if (p->left != NIL) {
			return Tree_Predecessor(p->left->data.second);
		}

		auto y = p->parent;
		while (y != NIL && p == y->left) {
			p = y;
			y = y->parent;
		}

		return y;
	}

	shared_ptr<Node> Tree_Maximum(const shared_ptr<Node> &Root) {
		auto p = Root;
		while (p->right != NIL) {
			p = p->right;
		}

		return p;
	}

	shared_ptr<Node> Tree_Minimum(const shared_ptr<Node> &Root) {
		auto p = Root;
		while (p->left != NIL) {
			p = p->left;
		}

		return p;
	}

	void Left_Rotate(shared_ptr<Node> Px) {
		auto Py = Px->right;
		Px->right = Py->left;

		if (Py->left != NIL) {
			Py->left->parent = Px;
		}
		Py->parent = Px->parent;
		if (Px->parent == NIL) {
			Root = Py;
		}
		else if (Px == Px->parent->left) {
			Px->parent->left = Py;
		}
		else {
			Px->parent->right = Py;
		}
		Py->left = Px;
		Px->parent = Py;
	}

	void Right_Rotate(shared_ptr<Node> Py) {
		auto Px = Py->left;
		Py->left = Px->right;

		if (Px->right != NIL) {
			Px->right->parent = Py;
		}
		Px->parent = Py->parent;
		if (Py->parent == NIL) {
			Root = Px;
		}
		else if (Py == Py->parent->left) {
			Py->parent->left = Px;
		}
		else {
			Py->parent->right = Px;
		}
		Px->right = Py;
		Py->parent = Px;
	}

	void Transplant(const shared_ptr<Node> &p1, const shared_ptr<Node> &P2) {
		if (p1->parent == NIL) {
			Root = P2;
		}
		else if (p1 == p1->parent->left) {
			p1->parent->left = P2;
		}
		else {
			p1->parent->right = P2;
		}
		P2->parent = p1->parent;
	}

	shared_ptr<Node> Search(const T &x) {
		auto temp = Hash_Val(x);
		auto p = Root;
		while (p != NIL && temp != p->data.first) {
			if (temp < p->data.first) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		try {
			if (p == NIL) {
				throw std::runtime_error("The element was not found.");
			}
		}
		catch (std::runtime_error err) {
			cout << err.what() << endl;
		}
		return p;
	}

	void Insert(const T &x) {
		auto temp = Hash_Val(x);
		shared_ptr<Node> New = std::make_shared<Node>(std::make_pair(temp, x), Red, NIL, NIL, NIL);
		auto Px = Root, Py = NIL;

		while (Px != NIL) {
			Py = Px;
			if (temp < Px->data.first) {
				Px = Px->left;
			}
			else {
				Px = Px->right;
			}
		}

		New->parent = Py;
		if (Py == NIL) {
			Root = New;
		}
		else if (temp < Py->data.first) {
			Py->left = New;
		}
		else {
			Py->right = New;
		}
		Rb_Insert_Fixup(New);
	}

	void Rb_Insert_Fixup(shared_ptr<Node> &p) {
		while (p->parent->color == Red) {
			if (p->parent == p->parent->parent->left) {
				auto Py = p->parent->parent->right;
				if (Py->color == Red) {
					p->parent->color = Black;
					Py->color = Black;
					p->parent->parent->color = Red;
					p = p->parent->parent;
				}
				else {
					if (p == p->parent->right) {
						p = p->parent;
						Left_Rotate(p);
					}
					p->parent->color = Black;
					p->parent->parent->color = Red;
					Right_Rotate(p->parent->parent);
				}
			}
			else {
				auto Py = p->parent->parent->left;
				if (Py->color == Red) {
					p->parent->color = Black;
					Py->color = Black;
					p->parent->parent->color = Red;
					p = p->parent->parent;
				}
				else {
					if (p == p->parent->left) {
						p = p->parent;
						Right_Rotate(p);
					}
					p->parent->color = Black;
					p->parent->parent->color = Red;
					Left_Rotate(p->parent->parent);
				}
			}
		}
		Root->color = Black;
	}

	void Delete(const T &x) {
		auto p = Search(x);
		auto Py = p;
		shared_ptr<Node> Px;
		Color y_original_color = Py->color;

		if (p != NIL) {
			if (p->left == NIL) {
				Px = p->right;
				Transplant(p, p->right);
			}

			else if (p->right == NIL) {
				Px = p->left;
				Transplant(p, p->left);
			}
			else {
				Py = Tree_Minimum(p->right);
				y_original_color = Py->color;
				Px = Py->right;
				if (Py->parent == p) {
					Px->parent = Py;
				}
				else {
					Transplant(Py, Py->right);
					Py->right = p->right;
					Py->right->parent = Py;
				}
				Transplant(p, Py);
				Py->left = p->left;
				Py->left->parent = Py;
				Py->color = p->color;
			}
			if (y_original_color == Black) {
				Rb_Delete_Fixup(Px);
			}
		}
	}

	void Rb_Delete_Fixup(shared_ptr<Node> &p) {
		while (p != Root && p->color == Black) {
			if (p == p->parent->left) {
				auto w = p->parent->right;
				if (w->color == Red) {
					w->color = Black;
					p->parent->color = Red;
					Left_Rotate(p->parent);
					w = p->parent->right;
				}
				if (w->left->color == Black && w->right->color == Black) {
					w->color = Red;
					p = p->parent;
				}
				else {
					if (w->right->color == Black) {
						w->left->color = Black;
						w->color = Red;
						Right_Rotate(w);
						w = p->parent->right;
					}
					w->color = p->parent->color;
					p->parent->color = Black;
					w->right->color = Black;
					Left_Rotate(p->parent);
					p = Root;
				}
			}
			else {
				auto w = p->parent->left;
				if (w->color == Red) {
					w->color = Black;
					p->parent->color = Red;
					Right_Rotate(p->parent);
					w = p->parent->left;
				}
				if (w->right->color == Black && w->left->color == Black) {
					w->color = Red;
					p = p->parent;
				}
				else {
					if (w->left->color == Black) {
						w->right->color = Black;
						w->color = Red;
						Left_Rotate(w);
						w = p->parent->right;
					}
					w->color = p->parent->color;
					p->parent->color = Black;
					w->left->color = Black;
					Right_Rotate(p->parent);
					p = Root;
				}
			}
		}
		p->color = Black;
	}

	size_t Tree_Hight(const shared_ptr<Node> &p) {
		if (p != NIL) {
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

#endif // !RED_BLACK_TREE_X86_H
