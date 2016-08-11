#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>

using std::vector;
using std::list;
using std::hash;
using std::pair;

template<typename T>
class Sgl_HashTable {
	typedef typename list<T>::iterator iterator;
public:
	Sgl_HashTable() { resize(); }
	Sgl_HashTable(const size_t &temp_bucket) { 
		bucket = temp_bucket;
		elem.resize(bucket); 
	}
	~Sgl_HashTable() = default;

	size_t Hash_Val(const T &x) {
		return hash<T>()(x) % bucket;
	}

	void insert(const T &x) {
		auto Hval = Hash_Val(x);
		elem[Hval].push_back(x);
	}

	pair<size_t, iterator> search(const T &x) {
		auto Hval = Hash_Val(x);
		auto pos = find(elem[Hval].begin(), elem[Hval].end(), x);
		try {
			if (pos == elem[Hval].end()) {
				throw runtime_error("The element was not found.");
			}
		}
		catch (runtime_error &err) {
			cout << err.what() << endl;
		}

		return std::make_pair(Hval, pos);
	}

	void erase(const T &x) {
		auto p = search(x);
		if (p.second != elem[p.first].end()) {
			elem[p.first].erase(p.second);
		}
	}

private:
	vector<list<T>> elem;
	size_t bucket = 100;
	void resize() { elem.resize(bucket); }
};

template<typename key, typename T>
class Dbl_HashTable {
	typedef typename list<pair<key, T>>::iterator iterator;
public:
	Dbl_HashTable() { resize(); }
	Dbl_HashTable(const key &temp_bucket) {
		bucket = temp_bucket;
		elem.resize(bucket);
	}

	size_t Hash_Val(const key &x) {
		return hash<T>()(x) % bucket;
	}

	void insert(const key &x1, const T &x2) {
		auto Hval = Hash_Val(x1);
		elem[Hval].push_back(std::make_pair(x1, x2));
	}

	pair<size_t, iterator> search(const key &x) {
		auto Hval = Hash_Val(x);
		auto pos = find_if(elem[Hval].begin(), elem[Hval].end(), [&](pair<key, T> temp_p)->bool {
			return temp_p.first == x;
		});
		try {
			if (pos == elem[Hval].end()) {
				throw runtime_error("The element was not found.");
			}
		}
		catch (runtime_error &err) {
			cout << err.what() << endl;
		}

		return std::make_pair(Hval, pos);
	}

	void erase(const key &x) {
		auto p = search(x);
		if (p.second != elem[p.first].end()) {
			elem[p.first].erase(p.second);
		}
	}

private:
	vector<list<pair<key, T>>> elem;
	size_t bucket = 100;
	void resize() { elem.resize(bucket); }
};

#endif // !HASH_TABLE_H
