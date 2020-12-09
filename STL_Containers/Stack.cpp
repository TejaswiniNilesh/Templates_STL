#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<string>

using namespace std;

template<typename T>
void prints(const T& s)
{
	size_t sz = s.size();
	cout << "size = " << sz << endl;
	if (sz) cout << "top= " << s.top() << endl;
}


int main()
{
	vector<int> v1 = { 1,2,3,4,5 };
	stack<int, vector<int>> s1(v1);
	prints(s1);

	stack<string> s2;

	for (string s : {"vector", "string", "list", "deque", "set", "map"})
		s2.push(s);

	prints(s2);

	

	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	//cout << "top = " << s2.top() << endl;
	cout << endl;
	getchar();
}