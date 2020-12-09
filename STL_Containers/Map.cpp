#include<iostream>
#include<map>
#include<string>

using namespace std;

template<typename T1, typename T2>
void printpair(pair<T1, T2> &p)
{
	cout << p.first << ":" << p.second << endl;
}

template<typename T>
void printmap(const T &m)
{
	if (m.empty()) return;
	for (auto x : m) printpair(x);

	cout << endl;

}


void message(const char* message) { cout << message << endl; }

template<typename T>
void message(const char* message, const T &v) { cout << message << ": " << v << endl; }



int main()
{
	message("Map using intializer list");
	map<string, string> m = { {"One","Ten"},{"Two","Twenty"},{"Three","Thirty"},{"Four","Fourty"} };
	printmap(m);

	message("One", m["One"]);
	message("Two", m.at("Two"));
	message("Three", m.find("Three")->second);

	m.insert({ "Ten", "Hundered" });

	message("Size", m.size());

	printmap(m);


	message("Insert duplicate element");

	auto r = m.insert({"One","Ten"});

	if (!r.second) cout << "Insert failed";
	else printmap(m);



	message("-------------Multimap--------------");
	message("Multi Map using intializer list");
	multimap<string, string> mm = { {"One","Ten"},{"Two","Twenty"},{"Three","Thirty"},{"Four","Fourty"} };
	printmap(m);

	//message("One", mm["One"]);
	//message("Two", mm.at("Two"));
	message("Three", mm.find("Three")->second);

	mm.insert({ "Ten", "Hundered" });

	message("Size", mm.size());

	printmap(mm);


	message("Insert duplicate element");

	mm.insert({ "One","Ten" });
	mm.insert({ "One","Ten" });
	//if (!r.second) cout << "Insert failed";
	//else printmap(mm);
	printmap(mm);
	message("Find and erase");

	auto itr1 = mm.find("One");
	if (itr1 != mm.end())
	{
		mm.erase(itr1);
	}
	printmap(mm);
	getchar();
}