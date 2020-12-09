#include <iostream>
#include<string>
//#include<utility>
#include <tuple>
using namespace std;

template<typename T>
void printt(T t)
{
	auto tsz = tuple_size<decltype(t)>::value;
	if (tsz != 3) return;
	cout << get<0>(t) << " : " << get<1>(t) << " : " << get<2>(t) << endl;
}


void message(const char* s) { cout << s << endl; }
void message(const char*s, const int n) { cout << s << n << endl; }


int main()
{

	message("Initializer list");
	tuple<int, int, int> t2 = { 1,2,3 };
	printt(t2);

	message("Default constructor");
	tuple<int, string, int> t1(1, "One", 10);
	printt(t1);
	
	message("make_tuple");
	tuple<int, int, int> t3;
	t3 = std::make_tuple(10, 20, 30);
	printt(t3);

	
	getchar();
}