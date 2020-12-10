#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


int getFirst(std::pair<int, string> p)
{
	return p.first;
}
int sum(int i, int j) { return i + j; }

int main()
{
	cout << "--------Transform on one range-------------" <<endl;
	map<int, string> m = { {1,"foo"}, {42, "bar"}, {7, "baz"} };
	vector<int> keys;
	std::transform(m.begin(), m.end(), std::back_inserter(keys), getFirst);

	//vector<int>::iterator itr = keys.begin();
	for (auto itr : keys)
		cout << itr << " ";
	cout << endl;


	cout << "--------Transform on two ranges-------------" << endl;

	vector<int> numbers1 = { 1, 5, 42, 7, 8 };
	vector<int> numbers2 = { 10, 7, 4, 2, 2 };
	vector<int> results;
	
	std::transform(numbers1.begin(), numbers1.end(),
		numbers2.begin(),
		std::back_inserter(results),sum);

	cout << "Transform using function" << endl;
	for (auto itrv : results)
		cout << itrv << " ";
	cout << endl;


	cout << "Transform using lambda function" << endl;
	std::transform(numbers1.begin(), numbers1.end(),
		numbers2.begin(),
		std::back_inserter(results),
		[](int i, int j) {return i + j; });

	for (auto itrv : results)
		cout << itrv <<  " ";
	cout << endl;

	getchar();
}