#include <iostream>
using namespace std;

template <typename T>
class multiply_by {
	T _mult = 0;
	multiply_by();
public:
	multiply_by(T n) : _mult(n) {}
	void mult(T n) { _mult = n; }
	T mult() const { return _mult; }
	T operator() (T n) const { return _mult * n; }
};


int main() {
	multiply_by<float> x(9.2);
	cout << "x mult is " << x.mult() << endl;

	cout << "x(5) is " << x(5) << endl;
	cout << "x(25) is " << x(25) << endl;

	x.mult(7.0);
	cout << "x mult is " << x.mult() << endl;

	cout << "x(5) is " << x(5) << endl;
	cout << "x(25) is " << x(25) << endl;

	getchar();
	return 0;
}
