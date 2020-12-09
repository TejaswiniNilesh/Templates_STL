#include<iostream>
#include<set>
#include<unordered_set>
#include<string>

using namespace std;


template<typename T>
void prints(const T &s)
{
	if(s.empty()) return;
	for (auto x : s) cout << x << " ";
		cout << endl;
}

void message(const char* message) { cout << message << endl; }

template<typename T>
void message(const char* message, const T &v) { cout << message << ": " << v << endl; }


int main()
{
	message("set set1");
	set<string> s1 = { "Aa","Bb","Cc","Dd","Ee" };
	prints(s1);
	s1.insert("Ff");

	message("Set Size = ", s1.size());
	prints(s1);

	set<string>::iterator itr = s1.find("Ff");
	if (itr != s1.end())
	{
		message("Erase element", *itr);
		s1.erase(itr);
	}
	else
		message("Element not found");


	message("Insert duplicate element");
	auto i = s1.insert("Bb");
	if (!i.second) message("Insert failed");
	prints(s1);


	message("Insert an element");
	s1.insert("Pp");
	prints(s1);



	message("Insert an element");
	s1.insert("Gg");
	prints(s1);

	message("------------Multiset-------------");

	message("set set1");
	multiset<string> s2 = { "Aa","Bb","Cc","Dd","Ee" };
	prints(s2);
	s2.insert("Ff");

	message("Set Size = ", s2.size());
	prints(s2);

	itr = s2.find("Ff");
	if (itr != s2.end())
	{
		message("Erase element", *itr);
		s2.erase(itr);
	}
	else
		message("Element not found");


	message("Insert duplicate element");
	 s2.insert("Bb");
	//if (!j.second) message("Insert failed");
	prints(s2);


	message("Insert an element");
	s2.insert("Gg");
	prints(s2);


	message("------------Unordered set-------------");

	message("set set1");
	unordered_set<string> s3 = { "pen","bat","cat","mat","band"};
	prints(s3);
	s3.insert("Ff");

	message("Set Size = ", s3.size());
	prints(s3);

	auto itr3 = s3.find("Ff");
	if (itr3 != s3.end())
	{
		message("Erase element", *itr3);
		s3.erase(itr3);
	}
	else
		message("Element not found");


	message("Insert duplicate element");
	s3.insert("bat");
	//if (!j.second) message("Insert failed");
	prints(s3);


	message("Insert an element");
	s3.insert("Gg");
	prints(s3);



	message("------------Unordered multiset-------------");

	message("set set1");
	unordered_multiset<string> s4 = { "pen","bat","cat","mat","band" };
	prints(s4);
	s4.insert("Ff");

	message("Set Size = ", s4.size());
	prints(s4);

	auto itr4 = s4.find("Ff");
	if (itr4 != s4.end())
	{
		message("Erase element", *itr4);
		s4.erase(itr4);
	}
	else
		message("Element not found");


	message("Insert duplicate element");
	s4.insert("bat");
	//if (!j.second) message("Insert failed");
	prints(s4);


	message("Insert an element");
	s4.insert("Gg");
	prints(s4);


	getchar();
}