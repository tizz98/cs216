//studType.h
#ifndef STUDTYPE_H
#define STUDTYPE_H

#include <fstream>
#include <iostream>
#include <iomanip>

const int NUM_OF_EXAMS = 3;

using namespace std;

class StudType
{
 public:
 	StudType(int idVal, int exam1Val, int exam2Val, int exam3Val);
 	//**********************************************************************
  //Purpose: To assign value to all the private variables
  //Input: idVal, exam1Val, exam2Val, exam3Val
  //Pre: StudType class must be setup and studId & exam variables 
  //     declared private
  //Output: none
  //Post: Value is assinged in studId, exam1, exam2, exam3
  //Note: none
  //**********************************************************************
 	StudType();
  //******************************************************************
  //Purpose: Default initialization of a StudType object
  //Input: none
  //Pre: StudType class is setup and studId & exam variables declared
  //     private
  //Output: none
  //Post: studId, exam1, exam2, exam3 are assigned with weird values
  //Note: default values if none are given to a StudType object
  //******************************************************************
 	void SetRd(int idVal, int exam1Val, int exam2Val, int exam3Val);
  //************************************************************************
  //Purpose: To set value to studId, exam1, exma2 & exam3
  //Input: idVal, exam1Val, exam2Val, exam3Val
  //Pre: StudType class is created and studId & exams are declared as
  //     private variables
  //Output: none
  //Post: studId, exam1, exam2, exam3 have value
  //Note: none
  //************************************************************************
 	int StudIdIs() const;
  //******************************************************************
  //Purpose: Reutrns the student id
  //Input: none
  //Pre: studId has value & StudType class is created
  //Output: int
  //Post: An integer containing the student id is returned
  //Note: none
  //******************************************************************
 	int StudExam1Is() const;
  //******************************************************************
  //Purpose: Reutrns the value exam1
  //Input: none
  //Pre: exam1 has value & StudType class is created
  //Output: int
  //Post: An integer containing exam1 is returned
  //Note: none
  //******************************************************************
 	int StudExam2Is() const;
  //******************************************************************
  //Purpose: Reutrns the value exam2
  //Input: none
  //Pre: exam2 has value & StudType class is created
  //Output: int
  //Post: An integer containing exam2 is returned
  //Note: none
  //******************************************************************
 	int StudExam3Is() const;
  //******************************************************************
  //Purpose: Reutrns the value exam3
  //Input: none
  //Pre: exam3 has value & StudType class is created
  //Output: int
  //Post: An integer containing exam3 is returned
  //Note: none
  //******************************************************************
 	float ExamsAvg() const;
  //******************************************************************
  //Purpose: Returns the average of 3 exams
  //Input: none
  //Pre: exam1, exam2, exam3 have value and the constant NUM_OF_EXAMS
  //     has value
  //Output: float
  //Post: The average of 3 exams is returned
  //Note: none
  //******************************************************************
 	void ReadRd(ifstream& inFile);
  //******************************************************************
  //Purpose: To take input from a file and assign them to studId,
  //         exam1, exam2 & exam3
  //Input: inFile
  //Pre: inFile is opened and ok; studId, exam1, exam2, exam3 are
  //     declared
  //Output: none
  //Post: studId, exam1, exam2 & exam3 have value
  //Note: none
  //******************************************************************
 	void PrintRd(ofstream& outFile, int& validCount, int& invalidCount);
  //************************************************************************
  //Purpose: To print a student's record to the output file
  //Input: none
  //Pre: studId, exam1, exam2 & exam3 have value & outFile is opened and ok
  //Output: outFile
  //Post: A student record is printed to the output file
  //Note: none
  //************************************************************************
  bool IsValid();
  //************************************************************************
  //Purpose: To check if the student's record has a valid id and exam scores
  //Input: none
  //Pre: studId, exam1, exam2 & exam3 have value
  //Output: bool
  //Post: True or false has been returned based on their id and exam scores
  //Note: none
  //************************************************************************

 private:
  int studId, exam1, exam2, exam3;

};

void printHeading(ofstream& outFile);
//******************************************************************
//Purpose: To print the heading of the output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: The heading is printed to the output file
//Note: none
//******************************************************************
void printEndMsg(ofstream& outFile);
//******************************************************************
//Purpose: To print an end message to the output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: An end message is printed in the output file
//Note: none
//******************************************************************
void printStat(ofstream& outFile, int validCount, int invalidCount, int studCount);
//*********************************************************************************
//Purpose: To print the percent of valid and invalid data
//Input: validCount, invalidCount, studCount
//Pre: outFile is opened and ok
//Output: outFile
//Post: The percecnt of valid and invalid data are printed
//Note: none
//*********************************************************************************
#endif