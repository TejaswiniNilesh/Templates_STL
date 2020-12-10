#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int main()
{
	string in = "I am happy.";
	cout << in << endl;

	string out(in.size(),'.');
	
	transform(in.begin(), in.end(), out.begin(), ::toupper);
	cout << out << endl;

	getchar();
}