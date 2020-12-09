#ifndef STACK_H
#define STACK_H

#include<exception>
class stackexception : public std::exception
{
	const char* msg;
	stackexception(); //default constructor

public : 
	explicit stackexception(const char* s) throw() : msg(s) {}
	const char* what() throw() {return msg; }
};

template <typename T>
class stack
{
private : 
	static const int defaultsize = 10;
	static const int maxsize = 1000;
	int size;
	int top;
	T * stackptr;
public : 
	explicit stack(int s = defaultsize);
	~stack() { delete stackptr; }
	T & push(const T&);
		T& pop();
		bool isEmpty() { return top < 0; }
		bool isFull() { return top >= size - 1; }
		int _top() { return top; }
		int _size() { return size; }
};

template<typename T>
stack<T>::stack(int s)
{
	if (s > maxsize || s < 1) throw stackexception("invalid Stack size");
	else
		size = s;
	stackptr = new T[size];
	top = -1;
}


template <typename T>
T& stack<T>::push(const T& i)
{
	if (isFull()) throw stackexception("Stack is full");
	return stackptr[++top] = i;
}

template <typename T>
T & stack<T>::pop()
{
	if (isEmpty()) throw stackexception("Stack is empty");
	return stackptr[top--];
}


#endif
