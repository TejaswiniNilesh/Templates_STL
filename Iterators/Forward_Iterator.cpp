#include <iostream>  
#include <fstream>  
#include <iterator>  
#include <vector>  

using namespace std;

template<class ForwardIterator>                                       // function template  
void display(ForwardIterator first, ForwardIterator last)            // display function  
{
	while (first != last)
	{
		cout << *first << " ";
		first++;
	}
}


int main()
{
	vector<int> a = {1,2,3,4,5,6,7,8,9,10};

	display(a.begin(), a.end());


	getchar();


}