//studType.cxx
#include "studType.h"

StudType::StudType(int idVal, int exam1Val, int exam2Val, int exam3Val)
//**********************************************************************
//Purpose: To assign value to all the private variables
//Input: idVal, exam1Val, exam2Val, exam3Val
//Pre: StudType class must be setup and studId & exam variables 
//     declared private
//Output: none
//Post: Value is assinged in studId, exam1, exam2, exam3
//Note: none
//**********************************************************************
{
 studId = idVal;
 exam1 = exam1Val;
 exam2 = exam2Val;
 exam3 = exam3Val;
}

StudType::StudType()
//******************************************************************
//Purpose: Default initialization of a StudType object
//Input: none
//Pre: StudType class is setup and studId & exam variables declared
//     private
//Output: none
//Post: studId, exam1, exam2, exam3 are assigned with weird values
//Note: default values if none are given to a StudType object
//******************************************************************
{
 studId = -999;
 exam1 = -141;
 exam2 = -142;
 exam3 = -143;
}

void StudType::SetRd(int idVal, int exam1Val, int exam2Val, int exam3Val)
//************************************************************************
//Purpose: To set value to studId, exam1, exma2 & exam3
//Input: idVal, exam1Val, exam2Val, exam3Val
//Pre: StudType class is created and studId & exams are declared as
//     private variables
//Output: none
//Post: studId, exam1, exam2, exam3 have value
//Note: none
//************************************************************************
{
 studId = idVal;
 exam1 = exam1Val;
 exam2 = exam2Val;
 exam3 = exam3Val;
}

int StudType::StudIdIs() const
//******************************************************************
//Purpose: Reutrns the student id
//Input: none
//Pre: studId has value & StudType class is created
//Output: int
//Post: An integer containing the student id is returned
//Note: none
//******************************************************************
{
 return studId;
}

int StudType::StudExam1Is() const
//******************************************************************
//Purpose: Reutrns the value exam1
//Input: none
//Pre: exam1 has value & StudType class is created
//Output: int
//Post: An integer containing exam1 is returned
//Note: none
//******************************************************************
{
 return exam1;
}

int StudType::StudExam2Is() const
//******************************************************************
//Purpose: Reutrns the value exam2
//Input: none
//Pre: exam2 has value & StudType class is created
//Output: int
//Post: An integer containing exam2 is returned
//Note: none
//******************************************************************
{
 return exam2;
}

int StudType::StudExam3Is() const
//******************************************************************
//Purpose: Reutrns the value exam3
//Input: none
//Pre: exam3 has value & StudType class is created
//Output: int
//Post: An integer containing exam3 is returned
//Note: none
//******************************************************************
{
 return exam3;
}

float StudType::ExamsAvg() const
//******************************************************************
//Purpose: Returns the average of 3 exams
//Input: none
//Pre: exam1, exam2, exam3 have value and the constant NUM_OF_EXAMS
//     has value
//Output: float
//Post: The average of 3 exams is returned
//Note: none
//******************************************************************
{
 return float((exam1 + exam2 + exam3)) / NUM_OF_EXAMS;
}

void StudType::ReadRd(ifstream& inFile)
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
{
 inFile >> studId >> exam1 >> exam2 >> exam3;
}

void StudType::PrintRd(ofstream& outFile, int& validCount, int& invalidCount)
//****************************************************************************
//Purpose: To print a student's record to the output file
//Input: none
//Pre: studId, exam1, exam2 & exam3 have value & outFile is opened and ok
//Output: outFile
//Post: A student record is printed to the output file and valid/invalid
//      counts have been incremented if necessary
//Note: none
//****************************************************************************
{
 outFile << left << setw(5) << studId << setw(10) << exam1 << setw(10) << exam2 << setw(10)
         << exam3 << setw(10);

 if(IsValid())
  {
   validCount++;
   outFile << left << ExamsAvg() << endl;
  }
 else
  {
   invalidCount++;
   outFile << left << "***Invalid data" << endl;
  }
}

bool StudType::IsValid()
//************************************************************************
//Purpose: To check if the student's record has a valid id and exam scores
//Input: none
//Pre: studId, exam1, exam2 & exam3 have value
//Output: bool
//Post: True or false has been returned based on their id and exam scores
//Note: none
//************************************************************************
{
	if(studId >= 111 && studId <= 999 && exam1 >= 0 && exam1 <= 100 && exam2 >= 0 && exam2 <= 100 &&
    exam3 >= 0 && exam3 <= 100)
  return true;
 else
  return false;
}

void printHeading(ofstream& outFile)
//******************************************************************
//Purpose: To print the heading of the output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: The heading is printed to the output file
//Note: none
//******************************************************************
{
 outFile << "*~< Student Exam Report >~*" << endl << endl;
 outFile << left << setw(5) << "Id" << setw(10) << "Exam1" << setw(10) << "Exam2" << setw(10)
         << "Exam3" << setw(10) << "AVG" << endl;
 outFile << left << setw(5) << "--" << setw(10) << "-----" << setw(10) << "-----" << setw(10)
         << "-----" << setw(10) << "---" << endl;
}

void printEndMsg(ofstream& outFile)
//******************************************************************
//Purpose: To print an end message to the output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: An end message is printed in the output file
//Note: none
//******************************************************************
{
 outFile << endl;
 outFile << "*< end >*";
}

void printStat(ofstream& outFile, int validCount, int invalidCount, int studCount)
//*********************************************************************************
//Purpose: To print the percent of valid and invalid data
//Input: validCount, invalidCount, studCount
//Pre: outFile is opened and ok
//Output: outFile
//Post: The percecnt of valid and invalid data are printed
//Note: none
//*********************************************************************************
{
 outFile << endl;
 if(studCount > 0) 
 {
  outFile << ">>>Valid data: " << float(validCount) / float(studCount) * 100 << "%" << endl;
  outFile << ">>>Invlaid data: " << float(invalidCount) / float(studCount) * 100 << "%" << endl;
 }
 else
  outFile << ">>>No student records! Valid/invalid data cannot be calculated" << endl;
}