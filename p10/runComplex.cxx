//runComplex.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #10
//
//DUE DATE: 04-09-14
//
//POSSIBLE POINTS: 30 Points
//
//Purpose:
//  To overload operators to do different arithmatic with complex numbers
//************************************************************************
#include "Complex.h"

int main()
{
	ifstream inFile;
 ofstream outFile;

 inFile.open("in.data");
 outFile.open("out.data");

 //Incase the inFile and outFile fail
 if (inFile.fail() || outFile.fail())
 {
  outFile << "Check your input and output file" << endl;
  return 1;
 }

 outFile.setf(ios::fixed);
 outFile.precision(1);

 Complex A, B, C, D, F;

 inFile >> A >> B >> C >> D;

 outFile << "<~ Operator Overloading ~>" << endl;

 outFile << endl;
 outFile << "A = " << A << endl;
 outFile << "B = " << B << endl;
 outFile << "C = " << C << endl;
 outFile << "D = " << D << endl;
 
 outFile << endl;
 F = A + B;
 outFile << "A + B = " << F << endl;
 F = A - B;
 outFile << "A - B = " << F << endl;
 F = A * B;
 outFile << "A * B = " << F << endl;
 F = A / B;
 outFile << "A / B = " << F << endl;

 C += D;
 outFile << "C += D = " << C << endl;

 D -= C;
 outFile << "D -= C = " << D << endl;

 F = ++C;
 outFile << "++C = " << F << endl;
 F = D++;
 outFile << "D++ = " << F << endl;

 outFile << endl;
 outFile << "~> end <~";

 inFile.close();
 outFile.close();

	return 0;
}