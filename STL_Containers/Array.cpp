#include<iostream>
#include<array>
#include<string>
using namespace std;

template<typename T,size_t N>
void printa(array<T, N> &a)
{
	for (T &i : a) cout << i << " : ";
	cout << endl;
}


void message(const char* message) { cout << message << endl; }

template<typename T>
void message(const char* message, const T &v) { cout << message << ": " << v << endl; }
int main()
{
	message("default constructor");
	array<int,5> a1;
	a1 = { 5,5,5,5,5 };
	printa(a1);

	message("Initializer list");
	array<string, 3> a2 = { "One","Two","Three" };
	printa(a2);


	message("Size of an array : ", a1.size());
	message("Second element of an array : " ,a2[2]);
	message("First element of an array ", a1.at(0));

	string *itr = a2.data();
	for (int i = 0; i < a2.size(); i++)
	{
		message(itr->c_str());
		itr++;
	}


	getchar();
}