#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

struct Complex {
	double Re = 0;
	double Im = 0;
	Complex sum(Complex a);
	Complex substract(Complex a);
	Complex multiple(Complex a);
	Complex devide(Complex a);
	void write();
	double mod();
};

#endif