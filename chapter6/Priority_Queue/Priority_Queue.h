#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

template <
	typename T,
	typename Container = std::vector<T>,
	typename Compare = std::less<typename Container::value_type>>
class Priority_Queue {
public:
	typedef typename Container::value_type value_type;
	typedef typename Container::const_reference const_reference;

public:
	Priority_Queue() = default;

	Priority_Queue(const Container& cont) : c(cont) {
		std::make_heap(c.begin(), c.end(), comp);
	}

	Priority_Queue(const Compare& cmp, const Container& cont) : comp(cmp), c(cont) {
		std::make_heap(c.begin(), c.end(), comp);
	}

	~Priority_Queue() {}

	void push(value_type&& x) {
		c.push_back(move(x));
		std::push_heap(c.begin(), c.end(), comp);
	}

	void push(const value_type& x) {
		c.push_back(x);
		std::push_heap(c.begin(), c.end(), comp);
	}

	const_reference& top() const {
		return c.front();
	}
	void pop() {
		std::pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}

	bool empty() const {
		return c.empty();
	}

	std::string::size_type size() const {
		return c.size();
	}

private:
	Compare comp;
	Container c;
};

#endif // !PRIORITY_QUEUE_H
