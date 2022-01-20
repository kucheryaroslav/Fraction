#include <iostream>
#include <fstream>
#include "Fraction.h"

using namespace std;



int main() {
	//int x = 10;
	//int y = 20;
	//int z = x + y;
	//cout << z << endl;

	Fraction a(5, 14);
	Fraction b(3, 35);
	Fraction c(1, 4);
	Fraction d(1, 4);
	Fraction e(1, 2);

	cout << a << endl;
	cout << b << endl;
	(a / b).getProperFraction();
	(e + 5).toString();
	(5 + e).toString();
	//(c - d).toString();
	
	ofstream fout("output.txt");
	fout << a << endl;
	Fraction f;
	cin >> f;
	cout << f << endl;
	ifstream fin("input.txt");
	Fraction g;
	fin >> g;
	cout << g << endl;
}