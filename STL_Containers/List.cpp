#include <iostream>
#include<string>
#include <list>
using namespace std;


template <typename T>
void printl(list<T> & l)
{
	if (l.empty())return;
	else
		for (T &i : l)
			cout << i << " ";
	cout << endl;
}

void message(const char* s) { cout << s << endl; }
void message(const char*s, const int n) { cout << s << n << endl; }
int main()
{
	list<int> l = { 1,2,3,4,5,6,7,8,9,10 };
	printl(l);
	message("size : ",l.size());
	message("front", l.front());
	message("back : ", l.back());

	l.push_back(100);
	printl(l);

	l.pop_back();
	printl(l);
	// As random delete and insert is not allowed, need an ierator to insert and delete

	message("insert : ");
	list<int>::iterator itr = l.begin();
	while (*itr++ != 5 && itr != l.end());
	if (itr != l.end())
	{
		message("Insert element 100 at position  : ", 5);
		l.insert(itr, 100);
		
	}
	printl(l);
	
	while (*++itr != 7 && itr != l.end());
	if (itr != l.end())
		l.erase(itr);
	printl(l);

	l.remove(10);
	printl(l);

	auto itr2 = itr = l.begin();
	while (*++itr != 100 && itr != l.end());
	while (*++itr2 != 9 && itr2 != l.end());
	if (itr != l.end() && itr2 != l.end())
		l.erase(itr, itr2);
	printl(l);
	getchar();
}