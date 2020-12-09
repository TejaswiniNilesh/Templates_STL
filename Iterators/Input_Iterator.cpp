#include<iostream>
#include<iterator>

using namespace std;

void message(const char* s) { cout << s << endl; }
int main()
{
	double d1 = 0, d2 = 0;
	
	message("Input two foat numbers : ");
	cout << flush;
	cin.clear();
	istream_iterator<double> eos;
	istream_iterator<double> itr(cin);
	if (itr != eos)
		d1 = *itr++;
	else
	{
		message("Inut 1 is invalid");
		return 0;
	}
	if (itr != eos)
		d2 = *itr;
	else
	{
		message("Inut 2 is invalid");
		return 0;
	}
	cin.clear();
	message("Multiplication value = ");
	cout << d1 * d2 << endl;

	getchar();
	getchar();
}