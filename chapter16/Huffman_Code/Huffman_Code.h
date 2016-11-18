#ifndef _HUFFMAN_CODE_H_
#define _HUFFMAN_CODE_H_

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;
using std::pair;
using std::map;
using std::cout;
using std::endl;

class H_BST {
	struct Node {
		pair<string, size_t> data;
		shared_ptr<Node> left = nullptr;
		shared_ptr<Node> right = nullptr;
		shared_ptr<Node> parent = nullptr;
	};

	shared_ptr<Node> Root = nullptr;
	//Binary_Search_Tree with Huffman-Code.
	vector<shared_ptr<Node>> Vec_Node;
	//Letters and codes.
	map<string, string> Map_Code;

public:
	H_BST() = default;
	~H_BST() = default;

	//Reading the data.
	void Huffman_Code(string const &temp_str) {
		string temp_i;
		map<string, size_t> temp_Map;

		for(auto &i : temp_str) {
			temp_i = i;
			++temp_Map[temp_i];
		}

		Huffman_Encoder(temp_Map);
	}

	//Reading the data from file.
	void Huffman_Code_File(string const &filename) {
		string temp_i, temp_str;
		std::ifstream file(filename);
		map<string, size_t> temp_Map;

		try {
			if (file) {
				while (!file.eof()) {
					string temp_s;
					getline(file, temp_s);
					temp_str += temp_s;
				}
			}
			else {
				throw std::runtime_error("Not find the file.");
			}
		}
		catch (std::runtime_error e) {
			cout << e.what() << endl;
		}

		for (auto &i : temp_str) {
			temp_i = i;
			++temp_Map[temp_i];
		}

		Huffman_Encoder(temp_Map);
	}

	//Encodering and saving the result.
	void Huffman_Encoder(map<string, size_t> &temp_Map) {
		auto temp_n = temp_Map.size();
		vector<shared_ptr<Node>> temp_VecNode;

		for(auto &i : temp_Map) {
			auto temp_ptr = make_shared<Node>();
			temp_ptr->data.first = i.first;
			temp_ptr->data.second = i.second;

			temp_VecNode.push_back(temp_ptr);
		}

		for(auto i = 1; i != temp_n; ++i) {
			std::sort(temp_VecNode.begin(), temp_VecNode.end(), [](shared_ptr<Node> N1, shared_ptr<Node> N2) {return N1->data.second < N2->data.second; });
			auto new_Node = make_shared<Node>();

			new_Node->left = temp_VecNode[0];
			new_Node->right = temp_VecNode[1];
			new_Node->data.second = temp_VecNode[0]->data.second + temp_VecNode[1]->data.second;

			temp_VecNode.erase(temp_VecNode.begin(), temp_VecNode.begin() + 2);
			temp_VecNode.push_back(new_Node);
		}

		Vec_Node = temp_VecNode;

		Save_Coder(Vec_Node[0], "");
	}

	//Saving the unique code of letters.
	void Save_Coder(shared_ptr<Node> Root, string const &code) {
		if (Root) {
			if (!Root->left && !Root->right) {
				Map_Code.insert(std::make_pair(Root->data.first, code));
				std::cout << Root->data.first << " -> " << code << std::endl;
			}
			else {
				Save_Coder(Root->left, code + "0");
				Save_Coder(Root->right, code + "1");
			}
		}
	}
};

#endif // !_HUFFMAN_CODE_H_
