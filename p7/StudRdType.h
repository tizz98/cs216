//StudRdType.h
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

const int NAME_SIZE = 20;

class StudRdType
{
 public:
  StudRdType();
  //******************************************************************
  //Purpose: Default constructor for the StudRdType class
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: none
  //Post: All the private data has been initialized
  //Note: none
  //******************************************************************

  StudRdType(int inStudId, char inStudName[], char inSex, string inMajor,
             int inTotalCredits, float inExam1, float inExam2, float inExam3);
  //**************************************************************************************
  //Purpose: An initializer for the StudRdType class
  //Input: inStudId, inStudName, inSex, inMajor, inTotalCredits, inExam1, inExam2, inExam3
  //Pre: A StudRdType object has been declared (or is being delcared)
  //Output: none
  //Post: The private data has been assigned
  //Note: none
  //**************************************************************************************

  void Set(int inStudId, char inStudName[], char inSex, string inMajor,
           int inTotalCredits, float inExam1, float inExam2, float inExam3);
  //**************************************************************************************
  //Purpose: To initialize the data for the StudRdType class
  //Input: inStudId, inStudName, inSex, inMajor, inTotalCredits, inExam1, inExam2, inExam3
  //Pre: A StudRdType object has been declared (or is being delcared)
  //Output: none
  //Post: The private data has been assigned
  //Note: none
  //**************************************************************************************

  int IdIs() const;
  //******************************************************************
  //Purpose: To return the value of the student id
  //Input: none
  //Pre: A StudRdType object is delcared
  //Output: int
  //Post: The student id has been returned
  //Note: none
  //******************************************************************

  string NameIs() const;
  //******************************************************************
  //Purpose: To return the value of the student name
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: string
  //Post: The student name has been returned
  //Note: none
  //******************************************************************

  char SexIs() const;
  //******************************************************************
  //Purpose: To return the value of the student's gender
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: char
  //Post: The student's gender has been returned
  //Note: none
  //******************************************************************

  string MajorIs() const;
  //******************************************************************
  //Purpose: To return the student's major
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: string
  //Post: The major has been returned
  //Note: CIS is input as "IS" so this function converts it to "CIS"
  //******************************************************************

  int TotCreditsIs() const;
  //******************************************************************
  //Purpose: To return the number of credits the student has
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: int
  //Post: The number of credits the student has been returned
  //Note: none
  //******************************************************************

  float Exam1Is() const;
  //******************************************************************
  //Purpose: To return the value of exam1
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: float
  //Post: The value of exam1 has been returned
  //Note: none
  //******************************************************************

  float Exam2Is() const;
  //******************************************************************
  //Purpose: To return the value of exam2
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: float
  //Post: The value of exam2 has been returned
  //Note: none
  //******************************************************************

  float Exam3Is() const;
  //******************************************************************
  //Purpose: To return the value of exam3
  //Input: none
  //Pre: A StudRdType object has been declared
  //Output: float
  //Post: The value of exam3 has been returned
  //Note: none
  //******************************************************************

  void GetRdFromFile(ifstream& inFile);
  //**********************************************************************
  //Purpose: To input the record from an input file
  //Input: inFile
  //Pre: inFile is opened and ok; a StudRdType object has been initialized
  //Output: none
  //Post: The private data has been input
  //Note: none
  //**********************************************************************

  void PrintRdToFile(ofstream& outFile);
  //*********************************************************************
  //Purpose: To print the student record to the output file
  //Input: none
  //Pre: outFile is opened & ok; a StudRdType object has been initialized
  //Output: outFile
  //Post: The student record has been printed to outFile
  //Note: none
  //*********************************************************************

  void PrintTitles(ofstream& outFile);
  //*********************************************************************
  //Purpose: To print the titles to the output file
  //Input: none
  //Pre: outFile is opened & ok; a StudRdType object has been initialized
  //Output: outFile
  //Post: The titles have been printed to outFile
  //Note: none
  //*********************************************************************

  void PrintUnderlines(ofstream& outFile);
  //*********************************************************************
  //Purpose: To print the underlines to the output file
  //Input: none
  //Pre: outFile is opened & ok; a StudRdType object has been initialized
  //Output: outFile
  //Post: The underlines have been printed to outFile
  //Note: none
  //*********************************************************************

  bool IsValid(int& validCount, int& invalidCount);
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

  void CountSex(int& maleCount, int& femaleCount);
  //**********************************************************************
  //Purpose: To count the number of male & female
  //Input: maleCount, femaleCount
  //Pre: a StudRdType object, maleCount, femaleCount have been initialized
  //     and the record is valid
  //Output: maleCount, femaleCount
  //Post: maleCount & femaleCount have been updated if necessary
  //Note: none
  //**********************************************************************

  void CountCsIs(int& csCount, int& cisCount);
  //******************************************************************
  //Purpose: To count the number of CS & CIS majors
  //Input: csCount, cisCount
  //Pre: a StudRdType object, csCount, cisCount have been initialized
  //     and the record is valid
  //Output: csCount, cisCount
  //Post: csCount & cisCount have been updated if necessary
  //Note: none
  //******************************************************************

  void PrintAvg(ofstream& outFile);
  //******************************************************************
  //Purpose: To print the average of the 3 exams to the output file
  //Input: none
  //Pre: outFile is opened & ok; a StudRdType object has been
  //     initialized and the record is valid
  //Output: outFile
  //Post: The average of the 3 exams has been printed to outFile
  //Note: none
  //******************************************************************

  void PrintInvalidMsg(ofstream& outFile);
  //******************************************************************
  //Purpose: To print an invalid message to the output file
  //Input: none
  //Pre: outFile is opened & ok; a StudRdType object has been
  //     initialized and the record is invalid
  //Output: outFile
  //Post: An invalid message has been printed to outFile
  //Note: none
  //******************************************************************

  void PrintStats(ofstream& outFile, int maleCount, int femaleCount, int csCount, 
                  int cisCount, int validCount, int invalidCount);
  //*****************************************************************************************
  //Purpose: To print statistical information about the records to the output file
  //Input: maleCount, femaleCount, csCount, cisCount, validCount, invalidCount
  //Pre: a StudRdType object, maleCount, femaleCount, csCount, cisCount, validCount
  //     invalidCount have been initialized; outFile is opened & ok
  //Output: outFile
  //Post: Statistical information has been printed to outFile
  //Note: none
  //*****************************************************************************************

 protected:
  int totalCredits;
  float exam1, exam2, exam3;

 private:
  int studId;
  char studName[NAME_SIZE];
  char sex;
  string major;
};