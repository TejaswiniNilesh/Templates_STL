#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void printv(vector<T> & v)
{
	if (v.empty()) return;
	else
		for (T &i : v)
			cout << i;
	cout << endl;
}

void message(const char*s) { cout << s << endl; }
void message(const char*s, const int n) { cout << s << n << endl; }

int main()
{
	cout << "Vector from initializer list : " << endl;
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	printv(v1);

	message("size", (int)v1.size());
	message("front", (int)v1.front());
	message("back", (int)v1.back());
	message("element at 5 : ", (int)v1.at(5));
	message("element at 5 : ", (int)v1[5]);

	v1.insert(v1.begin() + 5, 100);
	printv(v1);
	
	v1.erase(v1.begin() + 5);
	printv(v1);

	v1.push_back(47);
	printv(v1);

	v1.pop_back();
	printv(v1);


	vector<int> v2 = { 1,2,3 };
	while (!v2.empty())
	{
		printv(v2);
		v2.pop_back();
	}

	message("Insert elements at begin with initializer list : ");
	v2.insert(v2.begin(), { 100,200,300,400 });
	printv(v2);

	v2.clear();
	message("Elements after clear : ");
	printv(v2);

	// Vector from array
	constexpr int n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v3(arr, arr + 5);
	message("Built vector from array : ");
	printv(v3);


	message("Vector from string");
	vector<string> v4(5, "string");
	printv(v4);


	message("Vector copy constructor");
	vector<string> v5(v4);
	printv(v5);

	message("Vector move constructor");
	vector<string> v6(std::move(v5));
	message("vector moved from : ");
	printv(v5);
	message("Vector moved to");
	printv(v6);
	getchar();
}