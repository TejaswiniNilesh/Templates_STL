#include<iostream>
#include<string>
#include<deque>

using namespace std;


template<typename T>
void reportd(T &d)
{
	size_t sz = d.size();
	cout << "size : " << sz << endl;
	if (sz) cout << "front : " << d.front() << "back : " << d.back();
	cout << endl;
}


template<typename T>
void printd(T &d)
{
	if (d.empty()) return;
	else
	{
		for (auto &i : d)
			cout << i << " ";
	}
}
int main()
{
	deque<string> d1 = { "One","two","three" };

	printd(d1);
	d1.push_back("four");
	d1.push_front("zero");
	printd(d1);

	d1.pop_back();
	d1.pop_front();

	printd(d1);
	reportd(d1);
	getchar();
}