//runstudtype.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #2
//
//DUE DATE: 02-03-14
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
 int validCount = 0;
 int invalidCount = 0; 
 int studCount = 0;

 printHeading(outFile);   //Prints heading to outFile

 stud.ReadRd(inFile);     //Priming read from infile

 while(inFile)
 {
  studCount++;

  stud.PrintRd(outFile, validCount, invalidCount);  //Prints record to file
  stud.ReadRd(inFile);    //Reads next record from infile
 }

 printStat(outFile, validCount, invalidCount, studCount);      //Prints percent of valid and invalid
 printEndMsg(outFile);    //Prints end message

 inFile.close();
 outFile.close();

 return 0;
}