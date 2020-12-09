#include<iostream>
#include<iterator>
#include<vector>

using namespace std;



template<typename Incrementable, typename OutputIterator>
void generate_sequence(Incrementable from, Incrementable to, OutputIterator output) {
	for (Incrementable k = from; k != to; ++k)
	{
		*output++ = k;
		
	}
	cout << endl;
}


int main()
{
	ostream_iterator<int> o(cout, " ");

	for (int i : {30, 40, 50, 20})
		o++ = i;
	cout << endl;

	std::vector<int> digits;

	/*
	Several values of the same type can be returned by passing an output iterator to the function. 
	This is particularly common for generic functions (like the algorithms of the standard library).
	*/
	generate_sequence(0, 10, std::back_inserter(digits));
	
	for (auto i : digits) cout << i << endl;

	getchar();
}