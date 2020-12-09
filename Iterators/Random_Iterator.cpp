#include<iostream>
#include<vector>
#include<iterator>

using namespace std;
template<typename T>
T getRandomElement(T first, T last)
{
	return first + (rand() % (last - first));
}
int main()
{
	vector<int> v1 = {100,200,300,400,500,600};
	cout << *getRandomElement(v1.begin(), v1.end()) << endl;

	getchar();
}