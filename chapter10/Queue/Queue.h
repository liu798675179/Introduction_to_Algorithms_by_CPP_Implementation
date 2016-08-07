#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <algorithm>

using std::deque;
using std::move;

template<typename T, typename Container = deque<T>>
class Queue {
public:
	typedef typename Container::value_type      value_type;
	typedef typename Container::reference       reference;
	typedef typename Container::const_reference const_reference;
	typedef typename Container::size_type       size_type;

protected:
	Container c;

public:
	Queue() = default;
	Queue(const Queue &s) : c(s.c){}
	Queue(Queue &&s) : c(move(s.c)){}
	Queue& operator=(const Queue &s) {
		c = s.c;
		return *this;
	}
	~Queue() = default;

	bool empty() const             { return c.empty(); }
	size_type size() const         { return c.size(); }
	void push(const value_type &x) { c.push_back(x); }
	void push(value_type &&x)      { c.push_back(move(x)); }
	void pop()                     { c.pop_front();; }
	reference front()              { return (c.front()); }
	const_reference front() const  { return (c.front()); }
	reference back()               { return (c.back()); }
	const_reference back() const   { return (c.back()); }
	void swap(Queue &s)            { swap(c, s.c); }
	template <typename... Args>
	void emplace(Args&& ... args) {
		c.emplace_back(forward<Args>(args)...);
	}
};

#endif // !QUEUE_H

