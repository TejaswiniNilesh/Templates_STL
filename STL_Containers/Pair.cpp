#include <iostream>
#include < utility>
#include <string>

using namespace std;

template <typename T1, typename T2>
void printp(pair<T1, T2> p)
{
	cout << p.first << ":" << p.second << endl;
}

void message(const char* s) { cout << s << endl; }
void message(const char*s, const int n) { cout << s << n << endl; }

int main()
{
	message("Initializer list");
	pair<int, string> p = { 10,"ten" };
	printp(p);

	message("default constructor : p1");
	pair<string,int>p1("seven", 7);
	printp(p1);

	message("make pair : p3" );
	pair<int,string>p3;
	p3 = std::make_pair(5, "five");
	printp(p3);

	
	message("p1 > p3", p >  p3);
	message("p == p1", p == p3);

	getchar();

}