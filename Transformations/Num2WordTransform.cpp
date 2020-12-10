// numword.cpp by Bill Weinman <http://bw.org/>
// version as of 2019-09-27
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

namespace bw {

	constexpr const char * _version = "2019.09.27";
	typedef uint64_t numnum;    // yummy numbers

	// _maxstr is max size of string
	constexpr size_t _maxstr = 1024;

	// _maxnum is nine hundred ninty-nine quadrillion nine hundred ninty-nine trillion nine hundred ninty-nine billion nine hundred ninty-nine million nine hundred ninty-nine thousand nine hundred ninty-nine
	constexpr numnum _maxnum = 999999999999999999;

	static const char * errnum = "error";

	static const char * _singles[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	static const char * _teens[] = {
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};

	static const char * _tens[] = {
		errnum, errnum, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty",
	};

	static const char * _hundred = "hundred";

	static const char * _powers[] = {
		errnum, "thousand", "million", "billion", "trillion", "quadrillion"
	};

	static const char * _hyphen = "-";
	static const char * _space = " ";

	class numword {
		numnum _num = 0;
		char * _buf = nullptr;
		size_t _buflen = 0;
		bool hyphen_flag = false;

		void clearbuf();
		void initbuf();
		void appendspace();
		void appendbuf(const char * s);

	public:
		numword() : _num(0) {}
		numword(const numnum num) : _num(num) {}
		~numword();
		const char * version() const { return _version; }
		void setnum(const numnum num) { _num = num; }
		numnum getnum() const { return _num; }
		numnum operator = (const numnum num);
		const char * words();
		const char * words(const numnum num);
		const char * operator () (const numnum num) { return words(num); };
	};

}

using namespace bw;
using namespace std;
// destructor
numword::~numword() {
	clearbuf();
}

// assignment operator
numnum numword::operator = (const numnum num) {
	setnum(num);
	return getnum();
}

const char * numword::words() {
	return words(_num);
}

// convert to words
const char * numword::words(const numnum num) {
	if (num > _maxnum) {
		return errnum;
	}
	initbuf();
	numnum n = num;
	if (n == 0) {
		appendbuf(_singles[n]);
		return _buf;
	}

	// powers of 1000
	if (n >= 1000) {
		for (int i = 5; i > 0; --i) {
			numnum power = (numnum)pow(1000.0, i);
			numnum _n = (n - (n % power)) / power;
			if (_n) {
				int index = i;
				numword _nw(_n);
				appendspace();
				appendbuf(_nw.words());
				appendspace();
				appendbuf(_powers[index]);
				n -= _n * power;
			}
		}
	}
	// hundreds
	if (n >= 100 && n < 1000) {
		numnum _n = (n - (n % 100)) / 100;
		numword _nw(_n);
		appendspace();
		appendbuf(_nw.words());
		appendspace();
		appendbuf(_hundred);
		n -= _n * 100;
	}
	// tens
	if (n >= 20 && n < 100) {
		numnum _n = (n - (n % 10)) / 10;
		appendspace();
		appendbuf(_tens[_n]);
		n -= _n * 10;
		hyphen_flag = true;
	}
	// teens
	if (n >= 10 && n < 20) {
		appendspace();
		appendbuf(_teens[n - 10]);
		n = 0;
	}
	// singles
	if (n > 0 && n < 10) {
		appendspace();
		appendbuf(_singles[n]);
	}
	return _buf;
}

// -- private methods --

// reset the buffer
void numword::clearbuf() {
	if (_buf != nullptr) {
		free(_buf);
		_buf = nullptr;
	}
	_buflen = 0;
}

// initialize the buffer
void numword::initbuf() {
	clearbuf();
	_buf = (char *)malloc(_maxstr);
	*_buf = 0;
	hyphen_flag = false;
}

// append space (or hyphen)
void numword::appendspace() {
	if (_buflen) {
		appendbuf(hyphen_flag ? _hyphen : _space);
		hyphen_flag = false;
	}
}

// append text to the string buffer
void numword::appendbuf(const char * s) {
	if (!s) return;
	size_t slen = strnlen(s, _maxstr);
	if (slen < 1) {
		return;
	}
	if ((slen + _buflen + 1) >= _maxstr) {
		return;
	}
	memcpy(_buf + _buflen, s, slen);
	_buflen += slen;
	_buf[_buflen] = 0;
}



template <typename T>
void disp_v(const T & v) {
	if (!v.size()) return;
	bool first = true;
	for (auto e : v) {
		if (first) first = false;
		else cout << ", ";
		cout << e;
	}
	cout << endl;
}

int main() {
	const vector<uint64_t> nums = { 1, 2, 3, 4, 5, 60, 72, 847, 9001, 10002052 };
	disp_v(nums);

	bw::numword nw;
	vector<string> words(nums.size());
	transform(nums.begin(), nums.end(), words.begin(), nw);
	disp_v(words);


	getchar();
	return 0;
}
