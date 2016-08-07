#ifndef STACK_H
#define STACK_H

#include <deque>

using std::deque;
using std::move;
using std::forward;

template <typename T, typename Container = deque<T>>
class Stack {
public:
	typedef typename Container::value_type      value_type;
	typedef typename Container::reference       reference;
	typedef typename Container::const_reference const_reference;
	typedef typename Container::size_type       size_type;

protected:
	Container c;

public:
	Stack() = default;
	Stack(const Stack &s) : c(s.c){}
	Stack(Stack &&s) : c(move(s.c)){}
	Stack& operator=(const Stack &s) {
		c = s.c;
		return *this;
	}
	~Stack() = default;

	bool empty() const             { return c.empty(); }
	size_type size() const         { return c.size(); }
	void push(const value_type &x) { c.push_back(x); }
	void push(value_type &&x)      { c.push_back(move(x)); }
	void pop()                     { c.pop_back(); }
	reference top()                { return c.back(); }
	const_reference top() const    { return c.back(); }
	void swap(Stack &s)            { swap(c, s.c); }
	template <typename... Args>
	void emplace(Args&& ... args) {
		c.emplace_back(forward<Args>(args)...);
	}
};

#endif // !STACK_H

