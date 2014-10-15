//StudRdType.cxx
#include "StudRdType.h"

StudRdType::StudRdType()
//******************************************************************
//Purpose: Default constructor for the StudRdType class
//Input: none
//Pre: A StudRdType object has been declared
//Output: none
//Post: All the private data has been initialized
//Note: none
//******************************************************************
{
 studId = 0;
 strncpy(studName, "ZZZZZ", NAME_SIZE);
 sex = 'X';
 major = "VVV";
 totalCredits = 0;
 exam1 = exam2 = exam3 = -10;
}

StudRdType::StudRdType(int inStudId, char inStudName[], char inSex, string inMajor,
                       int inTotalCredits, float inExam1, float inExam2, float inExam3)
//**************************************************************************************
//Purpose: An initializer for the StudRdType class
//Input: inStudId, inStudName, inSex, inMajor, inTotalCredits, inExam1, inExam2, inExam3
//Pre: A StudRdType object has been declared (or is being delcared)
//Output: none
//Post: The private data has been assigned
//Note: none
//**************************************************************************************
{
 studId = inStudId;
 strncpy(studName, inStudName, NAME_SIZE);
 sex = inSex;
 major = inMajor;
 totalCredits = inTotalCredits;
 exam1 = inExam1;
 exam2 = inExam2;
 exam3 = inExam3;
}

void StudRdType::Set(int inStudId, char inStudName[], char inSex, string inMajor,
                     int inTotalCredits, float inExam1, float inExam2, float inExam3)
//**************************************************************************************
//Purpose: To initialize the data for the StudRdType class
//Input: inStudId, inStudName, inSex, inMajor, inTotalCredits, inExam1, inExam2, inExam3
//Pre: A StudRdType object has been declared (or is being delcared)
//Output: none
//Post: The private data has been assigned
//Note: none
//**************************************************************************************
{
 studId = inStudId;
 strncpy(studName, inStudName, NAME_SIZE);
 sex = inSex;
 major = inMajor;
 totalCredits = inTotalCredits;
 exam1 = inExam1;
 exam2 = inExam2;
 exam3 = inExam3;
}

int StudRdType::IdIs() const
//******************************************************************
//Purpose: To return the value of the student id
//Input: none
//Pre: A StudRdType object is delcared
//Output: int
//Post: The student id has been returned
//Note: none
//******************************************************************
{
 return studId;
}

string StudRdType::NameIs() const
//******************************************************************
//Purpose: To return the value of the student name
//Input: none
//Pre: A StudRdType object has been declared
//Output: string
//Post: The student name has been returned
//Note: none
//******************************************************************
{
 return string(studName);
}

char StudRdType::SexIs() const
//******************************************************************
//Purpose: To return the value of the student's gender
//Input: none
//Pre: A StudRdType object has been declared
//Output: char
//Post: The student's gender has been returned
//Note: none
//******************************************************************
{
 return sex;
}

string StudRdType::MajorIs() const
//******************************************************************
//Purpose: To return the student's major
//Input: none
//Pre: A StudRdType object has been declared
//Output: string
//Post: The major has been returned
//Note: CIS is input as "IS" so this function converts it to "CIS"
//******************************************************************
{
 if (major == "IS")
  return "CIS";
 else
  return major;
}

int StudRdType::TotCreditsIs() const
//******************************************************************
//Purpose: To return the number of credits the student has
//Input: none
//Pre: A StudRdType object has been declared
//Output: int
//Post: The number of credits the student has been returned
//Note: none
//******************************************************************
{
 return totalCredits;
}

float StudRdType::Exam1Is() const
//******************************************************************
//Purpose: To return the value of exam1
//Input: none
//Pre: A StudRdType object has been declared
//Output: float
//Post: The value of exam1 has been returned
//Note: none
//******************************************************************
{
 return exam1;
}

float StudRdType::Exam2Is() const
//******************************************************************
//Purpose: To return the value of exam2
//Input: none
//Pre: A StudRdType object has been declared
//Output: float
//Post: The value of exam2 has been returned
//Note: none
//******************************************************************
{
 return exam2;
}

float StudRdType::Exam3Is() const
//******************************************************************
//Purpose: To return the value of exam3
//Input: none
//Pre: A StudRdType object has been declared
//Output: float
//Post: The value of exam3 has been returned
//Note: none
//******************************************************************
{
 return exam3;
}

void StudRdType::GetRdFromFile(ifstream& inFile)
//**********************************************************************
//Purpose: To input the record from an input file
//Input: inFile
//Pre: inFile is opened and ok; a StudRdType object has been initialized
//Output: none
//Post: The private data has been input
//Note: none
//**********************************************************************
{
 inFile >> studId >> studName >> sex >> major >> totalCredits >> exam1 >> exam2 >> exam3;
}

void StudRdType::PrintRdToFile(ofstream& outFile)
//*********************************************************************
//Purpose: To print the student record to the output file
//Input: none
//Pre: outFile is opened & ok; a StudRdType object has been initialized
//Output: outFile
//Post: The student record has been printed to outFile
//Note: none
//*********************************************************************
{
 outFile << left << setw(5) << studId << setw(20) << studName << setw(5) << sex << setw(10) << MajorIs()
         << setw(15) << totalCredits << setw(10) << exam1 << setw(10) << exam2 << setw(10) << exam3;
}

void StudRdType::PrintTitles(ofstream& outFile)
//*********************************************************************
//Purpose: To print the titles to the output file
//Input: none
//Pre: outFile is opened & ok; a StudRdType object has been initialized
//Output: outFile
//Post: The titles have been printed to outFile
//Note: none
//*********************************************************************
{
 outFile << left << setw(5) << "Id" << setw(20) << "Name" << setw(5) << "SEX" << setw(10) << "Major"
         << setw(15) << "TOTCredits" << setw(10) << "Exam1" << setw(10) << "Exam2" << setw(10) << "Exam3"
         << setw(10) << "AVG";
}

void StudRdType::PrintUnderlines(ofstream& outFile)
//*********************************************************************
//Purpose: To print the underlines to the output file
//Input: none
//Pre: outFile is opened & ok; a StudRdType object has been initialized
//Output: outFile
//Post: The underlines have been printed to outFile
//Note: none
//*********************************************************************
{
 outFile << left << setw(5) << "--" << setw(20) << "----" << setw(5) << "---" << setw(10) << "-----"
         << setw(15) << "----------" << setw(10) << "-----" << setw(10) << "------" << setw(10) << "------"
         << setw(10) << "---";
}

bool StudRdType::IsValid(int& validCount, int& invalidCount)
//******************************************************************
//Purpose: To check to see if the data is valid
//Input: validCount, invalidCount
//Pre: a StudRdType object has been initialized; validCount &
//     invalidCount have been declared
//Output: bool, validCount, invalidCount
//Post: True or false has been returned and validCount/invalidCount
//      have been updated if necessary
//Note: validCount & invalidCount used for stat function
//******************************************************************
{
 if (studId >= 111 && studId <= 999 && (sex == 'F' || sex == 'M') && (major == "CS" || major == "IS") &&
     totalCredits >= 0 && totalCredits <= 500 && exam1 >= 0 && exam1 <= 100 && exam2 >= 0 && exam2 <= 100
     && exam3 >= 0 && exam3 <= 100)
 {
  validCount++;
  return true;
 }
 else
 {
  invalidCount++;
  return false;
 }
}

void StudRdType::CountSex(int& maleCount, int& femaleCount)
//**********************************************************************
//Purpose: To count the number of male & female
//Input: maleCount, femaleCount
//Pre: a StudRdType object, maleCount, femaleCount have been initialized
//     and the record is valid
//Output: maleCount, femaleCount
//Post: maleCount & femaleCount have been updated if necessary
//Note: none
//**********************************************************************
{
 if (sex == 'M')
  maleCount++;
 else if (sex == 'F')
  femaleCount++;
}

void StudRdType::CountCsIs(int& csCount, int& cisCount)
//******************************************************************
//Purpose: To count the number of CS & CIS majors
//Input: csCount, cisCount
//Pre: a StudRdType object, csCount, cisCount have been initialized
//     and the record is valid
//Output: csCount, cisCount
//Post: csCount & cisCount have been updated if necessary
//Note: none
//******************************************************************
{
 if (major == "CS")
  csCount++;
 else if (major == "IS")
  cisCount++;
}

void StudRdType::PrintAvg(ofstream& outFile)
//******************************************************************
//Purpose: To print the average of the 3 exams to the output file
//Input: none
//Pre: outFile is opened & ok; a StudRdType object has been
//     initialized and the record is valid
//Output: outFile
//Post: The average of the 3 exams has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << left << setw(10) << (exam1 + exam2 + exam3) / 3;
}

void StudRdType::PrintInvalidMsg(ofstream& outFile)
//******************************************************************
//Purpose: To print an invalid message to the output file
//Input: none
//Pre: outFile is opened & ok; a StudRdType object has been
//     initialized and the record is invalid
//Output: outFile
//Post: An invalid message has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << left << setw(10) << "~* Invalid data *~";
}

void StudRdType::PrintStats(ofstream& outFile, int maleCount, int femaleCount, int csCount, 
	                           int cisCount, int validCount, int invalidCount)
//*****************************************************************************************
//Purpose: To print statistical information about the records to the output file
//Input: maleCount, femaleCount, csCount, cisCount, validCount, invalidCount
//Pre: a StudRdType object, maleCount, femaleCount, csCount, cisCount, validCount
//     invalidCount have been initialized; outFile is opened & ok
//Output: outFile
//Post: Statistical information has been printed to outFile
//Note: none
//*****************************************************************************************
{
 outFile << "Num of valid data:   " << validCount << endl;
 outFile << "Num of invalid data: " << invalidCount << endl;

 outFile << endl;
 outFile << "Male:   " << float(maleCount) / float(validCount) * 100 << "%" << endl;
 outFile << "Female: " << float(femaleCount) / float(validCount) * 100 << "%" << endl;

 outFile << endl;
 outFile << "CS:  " << float(csCount) / float(validCount) * 100 << "%" << endl;
 outFile << "CIS: " << float(cisCount) / float(validCount) * 100 << "%" << endl;
}