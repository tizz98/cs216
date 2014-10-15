//runp7.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #7
//
//DUE DATE: 03-19-14
//
//POSSIBLE POINTS: 30 Points
//
//Purpose:
//  To use inheritance to input a number of student records from an input
//  file and then output them to an output file.
//************************************************************************
#include "ExtStudRdType.h"

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

 ExtStudRdType stud;
 int maleCount = 0, femaleCount = 0;
 int csCount = 0, cisCount = 0;
 int validCount = 0, invalidCount = 0;
 int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
 int freshCount = 0, sophCount = 0, junCount = 0, senCount = 0;

 outFile << "*~< Student Report >~*" << endl << endl;
 stud.PrintTitles(outFile); outFile << endl;
 stud.PrintUnderlines(outFile); outFile << endl;

 stud.GetRdFromFile(inFile);
 while(inFile)
 {
  stud.PrintRdToFile(outFile);

  if (stud.IsValid(validCount, invalidCount))
  { 
  	stud.PrintAvg(outFile);
   stud.PrintGradeStanding(outFile); outFile << endl;

   //Count stuff
  	stud.CountSex(maleCount, femaleCount);
  	stud.CountCsIs(csCount, cisCount);
   stud.CountGrade(aCount, bCount, cCount, dCount, fCount);
   stud.CountStanding(freshCount, sophCount, junCount, senCount);
  }
  else
  { stud.PrintInvalidMsg(outFile); outFile << endl; }

  stud.GetRdFromFile(inFile);
 }

 outFile << endl;
 if (validCount > 0) //for divide by 0
 { stud.PrintStats(outFile, maleCount, femaleCount, csCount, 
                   cisCount, validCount, invalidCount, aCount,
                   bCount, cCount, dCount, fCount, freshCount,
                   sophCount, junCount, senCount);}
 else
  outFile << ">>> No valid student records, therefore there are not any stats to be printed." << endl;

 outFile << endl;
 outFile << "*< end >*";

 inFile.close();
 outFile.close();

 return 0;
}