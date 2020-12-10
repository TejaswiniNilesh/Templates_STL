#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v1({ 11,22,33,44,55,66,77 });
	for_each(v1.begin(), v1.end(), [](const int &element) { cout << element << " "; });
	cout << endl;

	getchar();
}