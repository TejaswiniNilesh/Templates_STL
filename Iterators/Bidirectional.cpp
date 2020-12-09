#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template<typename Bidirectional>
bool isPalindrome(Bidirectional first, Bidirectional last)
{
	while (true)
	{
		last--;

		// when a character is a space, skip it
		while (*last == ' ') last--;
		while (*first == ' ') first++;
		if (first == last)
			break;

		// case insensitive comparison
		if (tolower(*first) != tolower(*last))
			return false;

		first++;

		if (first == last)
			break;
	}
	return true;
}

int main()
{
	string s[] = { "Never odd or even",
				  "No lemon, no melon",
				  "telnet",
				  "aa bb aa" };

	for (int i = 0; i < 4; i++) {
		cout << s[i] << " : "
			<< isPalindrome(s[i].begin(), s[i].end()) << endl;
	}
	getchar();
}