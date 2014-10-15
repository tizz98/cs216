//Complex.cxx
#include "Complex.h"

Complex::Complex()
{
	a = -42.42;
 b = 72.34;
}

Complex::Complex(const Complex& otherComplex)
{
 a = otherComplex.a;
 b = otherComplex.b;
}

istream& operator>>(istream& input, Complex& C)
{
 input >> C.a >> C.b;
 return input;
}

ostream& operator<<(ostream& output, Complex& C)
{
 output << "(" << C.a << ")" << " + " << "(" << C.b << ")i";
 return output;
}

Complex Complex::operator+(const Complex& otherComplex) const
{
 Complex tempComp;

 tempComp.a = (a + otherComplex.a);
 tempComp.b = (b + otherComplex.b);

 return tempComp;
}

Complex Complex::operator-(const Complex& otherComplex) const
{
 Complex tempComp;

 tempComp.a = (a - otherComplex.a);
 tempComp.b = (b - otherComplex.b);

 return tempComp;
}

Complex Complex::operator*(const Complex& otherComplex) const
{
 Complex tempComp;

 tempComp.a = (a * otherComplex.a) - (b * otherComplex.b);
 tempComp.b = (b * otherComplex.a) + (a * otherComplex.b);

 return tempComp;
}

Complex Complex::operator/(const Complex& otherComplex) const
{
 Complex tempComp;

 tempComp.a = ((a * otherComplex.a) + (b * otherComplex.b)) / (pow(otherComplex.a, 2) + pow(otherComplex.b, 2));
 tempComp.b = ((b * otherComplex.a) - (a * otherComplex.b)) / (pow(otherComplex.a, 2) + pow(otherComplex.b, 2));

 return tempComp;
}

void Complex::operator+=(const Complex& otherComplex)
{
 a += otherComplex.a;
 b += otherComplex.b;
}

void Complex::operator-=(const Complex& otherComplex)
{
 a -= otherComplex.a;
 b -= otherComplex.b;
}

Complex Complex::operator++()
{
 a++;
 return *this;
}

Complex Complex::operator++(int u)
{
 Complex temp = *this;
 ++b;
 return temp;
}