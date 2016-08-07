#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>
#include <functional>

using std::make_heap;
using std::pop_heap;
using std::push_heap;

template <
	typename T,
	typename Container = std::vector<T>,
	typename Compare = std::less<typename Container::value_type>>
	class Priority_Queue {
	public:
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::const_reference const_reference;

	public:
		Priority_Queue() = default;
		Priority_Queue(const Priority_Queue &s) : c(s.c), comp(s.comp){}
		Priority_Queue& operator=(const Priority_Queue &s) {
			c = s.c;
			comp = s.comp;
			return *this;
		}
		template<class T>
		    Priority_Queue(T First, T Last) : c(First, Last), comp() {
			make_heap(c.begin(), c.end(), comp);
		}

		Priority_Queue(const Container& cont) : c(cont) {
			make_heap(c.begin(), c.end(), comp);
		}

		Priority_Queue(const Compare& cmp, const Container& cont) : comp(cmp), c(cont) {
			make_heap(c.begin(), c.end(), comp);
		}

		~Priority_Queue() = default;

		void push(value_type&& x) {
			c.push_back(move(x));
			push_heap(c.begin(), c.end(), comp);
		}

		void push(const value_type& x) {
			c.push_back(x);
			push_heap(c.begin(), c.end(), comp);
		}

		const_reference& top() const {
			return c.front();
		}
		void pop() {
			pop_heap(c.begin(), c.end(), comp);
			c.pop_back();
		}

		bool empty() const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}

	private:
		Container c;
		Compare comp;
};

#endif // !PRIORITY_QUEUE_H
