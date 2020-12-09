#include <iostream>
#include"Stack.h"
#include <string>
using namespace std;

constexpr int num[] = { 1,2,3,4,5};
constexpr const char* strs[] = {"one","two","three","four","five"};

template<typename lt, typename rt>
auto tf(const lt &lhs, const rt &rhs) { return lhs + rhs; }
int main()
{
	try {
		stack<int> st(5);
		cout << "Stack size " << st._size() << endl;
		cout << "Stack top " << st._top() << endl;

		for (int i : num)
			st.push(i);

		cout << "Stack top" << st._top() << endl;
		cout << "stack is " << (st.isFull() ? "full." : "not full.") << endl;

		while (!st.isEmpty())
			cout << "popped : " << st.pop() << endl;
	}
	catch (stackexception &e)
	{
		cout << "Stack error : " << e.what() << endl;
	}




	cout << "auto keyword in C++11.............." << endl;
		auto x = "This is a string";
		decltype(x) y;

	cout << "Type of x : " << typeid(x).name() << endl;
	cout << "Type of y : " << typeid(y).name() << endl;
	const string str = "This is a string class";
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		cout << *it << "="; 
	}
	cout << endl;
	
	for (auto it : str)
	{
		cout << it << "=";
	}

	const char* schar = "This is a char pointer";
	auto z = tf<string, const char*>(str, schar);
	cout << "z is" << z << endl;
	cout << "Type is : " <<typeid(z).name() << endl;
	getchar();
}