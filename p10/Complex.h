#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Complex
{
 public:
	 Complex();
  Complex(const Complex& otherComplex);
  friend istream& operator>>(istream& input, Complex& C);
  friend ostream& operator<<(ostream& output, Complex& C);
  Complex operator+(const Complex&) const;
  Complex operator-(const Complex&) const;
  Complex operator*(const Complex&) const;
  Complex operator/(const Complex&) const;
  void operator+=(const Complex&);
  void operator-=(const Complex&);
  Complex operator++();
  Complex operator++(int);

 private:
  float a, b;
};