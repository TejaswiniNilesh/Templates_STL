#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> v1 = {"Mom","Pop","Sis","Bro","Me"};
	vector<string>::iterator ibegin = v1.begin();
	vector<string>::iterator iend = v1.end();
	for (auto itr = ibegin; itr < iend; ++itr)
	{
		cout << *itr << endl;
	}
getchar();
}