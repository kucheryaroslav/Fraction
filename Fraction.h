#pragma once
#include <fstream>

class Fraction
{
public:
	Fraction() { _a = _b = 1; };
	Fraction(int a, int b) { _a = a; _b = b; }
	~Fraction();
	int getA() { return _a; }
	int getB() { return _b; }
	void setA(int a) { _a = a; }
	void setB(int b) { _b = b; }
	void toString();
	void reduction();
	void getProperFraction();

	Fraction operator+(Fraction obj);
	Fraction operator+(int n);
	friend Fraction operator+(int n, Fraction obj);
	Fraction operator-(Fraction obj);
	Fraction operator*(Fraction obj);
	Fraction operator/(Fraction obj);
	friend std::ostream& operator<<(std::ostream& stream, Fraction& obj);
	friend std::istream& operator>>(std::istream& stream, Fraction& obj);
	

private: 
	int _a; //числитель
	int _b;//знаменатель 
	//находим НОК (найменшое обш кратноу ), знаменатель
	
	int _getLCM(int x, int y);
	//находим НОД найбольше общ общый знаменатель
	int _getGCD(int x, int y);

};


