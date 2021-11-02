#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Fraction
{
public:
	Fraction() {}
	Fraction(int _n, int _d) :n(_n), d(_d)
	{
		assert(d != 0);
		countObj++;
	}
	Fraction(const Fraction& fraction) : n(fraction.n), d(fraction.d)
	{
		cout << "Copy constructor" << endl;
	}
	Fraction& operator = (const Fraction& fraction)
	{
		n = fraction.n;
		d = fraction.d;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	const Fraction& operator*(const Fraction& fraction) const
	{
		Fraction result(this->n * fraction.getN(), this->d * fraction.getD());
		return result;
	}
	const Fraction& operator-(const Fraction& fraction) const
	{
		Fraction result(this->n * fraction.getD() - fraction.getN() * this->d, this->d * fraction.getD());
		return result;
	}
	const Fraction& operator+(const Fraction& fraction) const
	{
		Fraction result(this->n * fraction.getD() + fraction.getN() * this->d, this->d * fraction.getD());
		return result;
	}

	int getN() const { return n; }
	int getD() const { return d; }
	void simplify();
	static int totalObjects() { return countObj; }

private:
	int n;
	int d;
	static int countObj;
};

int Fraction::countObj = 0;
ostream& operator<<(ostream& out, const Fraction& fraction)
{
	out << fraction.n << " / " << fraction.d;
	return out;
}

void Fraction::simplify()
{
	int d2;
	d2 = max(n, d);
	for (int i = 2; i <= d2;)
	{
		if ((n % i == 0) && (d % i == 0))
		{
			n = n / i;
			d = d / i;
		}
		else
		{
			i++;
		}
	}
}

int main()
{
	Fraction fraction1(16, 24);
	Fraction fraction2(4, 8);
	Fraction Copy(fraction1);
	Fraction a;
	a = fraction2;
	Fraction result = fraction1 * fraction2;
	Fraction result2 = fraction1 - fraction2;
	Fraction result3 = fraction1 + fraction2;
	result.simplify();
	result2.simplify();
	result3.simplify();
	cout << Copy << endl;
	cout << a << endl;
	cout << result.getN() << " / " << result.getD() << endl;
	cout << result2.getN() << " / " << result2.getD() << endl;
	cout << result3.getN() << " / " << result3.getD() << endl;
	cout << "Total objects created: " << Fraction::totalObjects() << endl;
	return 0;
}
