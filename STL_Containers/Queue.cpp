#include <iostream>
#include<deque>
#include <list>
#include<queue>
#include<string>

using namespace std;

template<typename T>
void printq(T & q)
{
	size_t sz = q.size();
	cout << "Size = " << sz << endl;
	if (sz) cout << "front = " << q.front() << "\tback = " << q.back() << endl;

}
int main()
{
	cout << "Queue from List" << endl;
	list<int> l1 = { 1, 2, 3, 4, 5 };
	queue<int, list<int>> q1(l1);
	printq(q1);

	//default container is deque
	queue<string> q2;
	for (string s : { "one", "two", "three", "four", "five" })
	{
		q2.push(s);
	}

	printq(q2);


	getchar();

}