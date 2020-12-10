#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BinaryTransform
{
public : 
	int sum = 1;
	int operator()(const int &first, const int & second) { return sum = first * second*sum; }
};

void display(vector<int> v)
{
	if (!v.size())return;
	for (auto value : v)
		cout << value << " ";
	cout << endl;
}
int main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v2 = { 10,9,8,7,6,5,4,3,2,1 };
	vector<int> v3(v1.size(), 0);
	BinaryTransform bt;
	cout << "v1 : ";
	display(v1);

	cout << "v2 : ";
	display(v2);

	cout << "v3 : ";
	display(v3);

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),bt);
	cout << "After transform v3 : ";
	display(v3);

	cout << "Standard stl functors : multiplies : " << endl;
	multiplies<int> ml;
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), ml);
	cout << "After transform v3 : ";
	display(v3);

	getchar();
}