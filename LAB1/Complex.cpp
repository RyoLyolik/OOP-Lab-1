#include "Complex.h"

void Complex::write()
{
	if (this->Re == 0)
	{
		cout << this->Im << "*i";
	}
	else if (this->Im < 0)
	{
		cout << this->Re << this->Im << "*i";
	}
	else if (this->Im == 0)
	{
		cout << this->Re;
	}
	else
	{
		cout << this->Re << "+" << this->Im << "*i";
	}
}

Complex Complex::sum(Complex a)
{
	double result_re = this->Re + a.Re;
	double result_im = this->Im + a.Im;
	return Complex{ result_re, result_im };
}

Complex Complex::substract(Complex a)
{
	double result_re = this->Re - a.Re;
	double result_im = this->Im - a.Im;
	return Complex{ result_re, result_im };
}

Complex Complex::multiple(Complex a)
{
	double result_re = this->Re * a.Re - this->Im * a.Im;
	double result_im = this->Im * a.Re + this->Re * a.Im;
	return Complex{ result_re, result_im };
}

Complex Complex::devide(Complex a)
{
	double result_re = (this->Re * a.Re + this->Im * a.Im) / (a.Re * a.Re + a.Im * a.Im);
	double result_im = (this->Im * a.Re - this->Re * a.Im) / (a.Re * a.Re + a.Im * a.Im);
	return Complex{ result_re, result_im };
}
double Complex::mod()
{
	return pow(pow(this->Re, 2) + pow(this->Im, 2), 0.5);
}