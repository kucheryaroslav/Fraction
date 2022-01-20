#include "Fraction.h"
#include <iostream>

	Fraction::~Fraction() {}

void Fraction::toString() {
	if (_a == 0) {
		std::cout << 0 << std::endl;
	}
	else {
		std::cout << _a << "/" << _b << std::endl;
	}
	
}

void Fraction::reduction()
{
	int gcd = _getGCD(_a, _b);
	_a /= gcd;
	_b /= gcd;
}

void Fraction::getProperFraction()
{
	int tmp = _a / _b;
	std::cout << tmp << " and " << (_a - _b * tmp) 
		<< "/" << _b << std::endl;
}

Fraction Fraction::operator+(Fraction obj)
{
	Fraction tmp;
	tmp._b = _getLCM(_b, obj._b);
	int a1 = tmp._b / _b * _a;//70 / 14 * 5 = 25
	int a2 = tmp._b / obj._b * obj._a;//70 / 35 * 3 = 6
	tmp._a = a1 + a2;
	tmp.reduction();
	return tmp;
}

Fraction Fraction::operator+(int n)
{
	Fraction tmp;
	tmp._b = _b;
	tmp._a = n * _b + _a;
	tmp.reduction();
	return tmp;
}

Fraction Fraction::operator-(Fraction obj)
{
	Fraction tmp;
	tmp._b = _getLCM(_b, obj._b);
	int a1 = tmp._b / _b * _a;//70 / 14 * 5 = 25
	int a2 = tmp._b / obj._b * obj._a;//70 / 35 * 3 = 6
	tmp._a = a1 - a2;
	tmp.reduction();
	return tmp;
}

Fraction Fraction::operator*(Fraction obj)
{
	Fraction tmp;
	// 5 * 3 = 15
	tmp._a = _a * obj._a;
	tmp._b = _b * obj._b;
	tmp.reduction();
	return tmp;
}

Fraction Fraction::operator/(Fraction obj)
{
	Fraction tmp;
	// 5 * 3 = 15
	tmp._a = _a * obj._b;
	tmp._b = _b * obj._a;
	tmp.reduction();
	return tmp;
}

int Fraction::_getLCM(int x, int y)
{
	return x / _getGCD(x, y) * y;
}

int Fraction::_getGCD(int x, int y)
{
	if (x < y) {
		std::swap(x, y);
	}
	while (y != 0) {
		x = x % y;
		std::swap(x, y);
	}
	return x;
}

Fraction operator+(int n, Fraction obj)
{
	Fraction tmp;
	tmp._b =  obj._b;
	tmp._a = n * obj._b + obj._a;
	tmp.reduction();
	return tmp;
}

std::ostream& operator<<(std::ostream& stream, Fraction& obj)
{
	stream << obj.getA() << "/" << obj.getB();
	return stream;
}

std::istream& operator>>(std::istream& stream, Fraction& obj)
{
	stream >> obj._a >> obj._b;
	return stream;
}
