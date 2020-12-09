#include <iostream>
#include <string>
using namespace std;
template <typename T>
T maxof(const T &a, const T &b)
{
	return (a > b ? a : b);

}

template <typename T>
constexpr T pi = 3.1415926535897932385L;

int main()
{
	int a = 10;
	int b = 7;
	cout << "Max of a and b = " << maxof <int>(a, b);

	const char* c = "seven";
	const char* d = "ten";
	cout << "Max of c and d = " << maxof <const char*>(c, d);


	string e = "teju";
	string f = "patil";

	cout << "Max of e and f = " << maxof <string>(e, f) << endl;


	cout.precision(20);
	cout << pi<long double> << endl;
	getchar();

}