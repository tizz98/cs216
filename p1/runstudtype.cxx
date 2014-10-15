//runstudtype.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #1
//
//DUE DATE: 01-27-14
//
//POSSIBLE POINTS: 10 Points
//
//Purpose:
//
//  Using a class to take input from file for student id and 3 exams and
//  then print them to an output file
//************************************************************************

#include "studType.h"

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
 outFile.precision(2);

 StudType stud;

 stud.ReadRd(inFile);

 printHeading(outFile);
 stud.PrintRd(outFile);
 printEndMsg(outFile);

 inFile.close();
 outFile.close();

 return 0;
}