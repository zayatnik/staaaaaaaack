#include <iostream>
#pragma once 

using namespace std;
//////////////////////////////////////////////////стэк
template<class t>
class stack {
	int r, rr;
	t*cont;
public:
	stack();
	stack(const stack& s);
	~stack();
	void push(const t& el);
	int size();
	bool empty();
	void pop();
	const t& onthetop();
	bool operator==(stack s);
	stack& operator=(const stack& s);
};

template <class t>
stack<t>::stack() {
	r = 0;
	rr = 8;
	cont = new t[rr];
	for (int i = 0; i < rr; i++)
		cont[i] = 0;
}

template<class t>
stack<t>::stack(const stack<t>& s) {
	int i;
	r = s.r;
	rr = s.rr;
	cont = new t[rr];
	for (i = 0; i < r; i++)
		cont[i] = s.cont[i];
	for (i = r; i < rr; i++)
		cont[i] = 0;
}

template<class t>
stack<t>::~stack() {
	delete[] cont;
}

template<class t>
void stack<t>::push(const t& el) {
	if (r == rr) {
		int i;
		rr = r + r / 3;
		t* b = new t[r];
		for (i = 0; i < r; i++)
			b[i] = cont[i];
		delete[] cont;
		cont = new t[rr];
		for (i = 0; i < r; i++)
			cont[i] = b[i];
		delete[] b;
		for (i = r; i < rr; i++)
			cont[i] = 0;
		cont[r] = el;
		r++;
	}
	else {
		cont[r] = el;
		r++;
	}
}

template<class t>
int stack<t>::size() {
	return r;
}

template<class t>
bool stack<t>::empty() {
	if (r == 0)
		return true;
	else return false;
}

template<class t>
void stack<t>::pop() {
	if (!(this->empty())) {
		if ((r = rr / 3) && (r > 8)) {
			int i;
			rr = r * 2;
			t* b = new t[r];
			for (i = 0; i < r; i++)
				b[i] = cont[i];
			delete[] cont;
			cont = new t[rr];
			for (i = 0; i < r; i++)
				cont[i] = b[i];
			for (i = r; i < rr; i++)
				cont[i] = 0;
			delete[] b;
			cont[r - 1] = 0;
			r--;
		}
		else {
			cont[r - 1] = 0;
			r--;

		}
	}
	else
		throw "not correct";
}

template<class t>
const t& stack<t>::onthetop() {
	if (this->empty())
		throw "not correct";
	else
		return cont[r - 1];
}

template<class t>
bool stack<t>::operator==(stack<t> s) {
	if (this != &s) {
		bool a = false;
		if (r == s.r) {
			int summa = 0;
			for (int i = 0; i < r; i++)
				if (cont[i] == s.cont[i])
					summa++;
			if (summa == r)
				a = true;
		}
		return a;
	}
	else
		return true;
}

template<class t>
stack<t>& stack<t>::operator=(const stack<t>& s) {
	if (this != &s) {
		int i;
		delete[] cont;
		r = s.r;
		rr = s.rr;
		cont = new t[rr];
		for (i = 0; i < r; i++)
			cont[i] = s.cont[i];
		for (i = r; i < rr; i++)
			cont[i] = 0;
	}
	return *this;
}

/////////////////////////////очередь

class queue {
private:
	int a;
	stack<int> s1, s2;
public:
	queue();
	queue(const queue&);
	void push(int el);
	void pop();
	int front();
	int back();
	bool pust();
	queue& operator=(const queue&);
	int size();
};

queue::queue() : s1(), s2() {
	a = 0;
}

queue::queue(const queue& q) {
	a = q.a;
	s1 = q.s1;
	s2 = q.s2;
}

void queue::push(int el) {
	if (s1.pust() && s2.pust()) {
		s1.push(el);
		a = 0;
	}
	else {
		if (a == 0) {
			int i;
			int s = s1.size();
			for (i = 0; i < s; i++) {
				s2.push(s1.onthetop());
				s1.pop();
			}
			s2.push(el);
			a = 1;
		}
		else
			s2.push(el);
	}
}

void queue::pop() {
	if (s1.pust() && s2.pust()) {
		throw "not correct";
	}
	else {
		if (a == 0)
			s1.pop();
		else {
			int i;
			int s = s2.size();
			for (i = 0; i < s; i++) {
				s1.push(s2.onthetop());
				s2.pop();
			}
			s1.pop();
			a = 0;
		}
	}
}

int queue::front() {
	if (s1.pust() && s2.pust()) {
		throw "not correct";
	}
	else {
		if (a == 0)
			return(s1.onthetop());
		else {
			int i;
			int s = s2.size();
			for (i = 0; i < s; i++) {
				s1.push(s2.onthetop());
				s2.pop();
			}
			a = 0;
			return(s1.onthetop());
		}
	}
}

int queue::back() {
	if (s1.pust() && s2.pust()) {
		throw "not correct";
	}
	else {
		if (a == 1)
			s1.onthetop();
		else {
			int i;
			int s = s1.size();
			for (i = 0; i < s; i++) {
				s2.push(s1.onthetop());
				s1.pop();
			}
			s2.onthetop();
			a = 1;
		}
	}
}

bool queue::pust() {
	return (s1.pust() && s2.pust());
}

queue& queue::operator=(const queue& q) {
	a = q.a;
	s1 = q.s1;
	s2 = q.s2;
	return *this;
}

int queue::size() {
	if (a == 0)
		return s1.size();
	else
		return s2.size();
}