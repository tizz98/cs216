//ExtStudRdType.h
#include "StudRdType.h"

class ExtStudRdType : public StudRdType
{
 public:
  char GradeIs() const;
  //******************************************************************
  //Purpose: To return the letter grade based on the average of the 3
  //         exams
  //Input: none
  //Pre: An ExtStudRdType object has been initialized
  //Output: char
  //Post: The letter grade has been returned
  //Note: exam1, exam2, exam3 must be protected or public data
  //******************************************************************

  string StandingIs() const;
  //******************************************************************
  //Purpose: To return the standing of the student based on how many
  //         credits they have
  //Input: none
  //Pre: An ExtStudRdType object has been initialized
  //Output: string
  //Post: The student's standing has been returned
  //Note: totalCredits must be protected of public data
  //******************************************************************

  void PrintGradeStanding(ofstream& outFile);
  //******************************************************************
  //Purpose: To print the letter grade and standing to the output file
  //Input: none
  //Pre: outFile is opened & ok; an ExtStudRdType object has been
  //     initialized and record is valid
  //Output: outFile
  //Post: The letter grade and standing has been printed to outFile
  //Note: none
  //******************************************************************

  void PrintTitles(ofstream& outFile);
  //******************************************************************
  //Purpose: To print the titles to the output file
  //Input: none
  //Pre: outFile is opened & ok; an ExtStudRdType object has been
  //     initialized 
  //Output: outFile
  //Post: The titles have been printed to outFile
  //Note: calls PrintTitles from the base class
  //******************************************************************

  void PrintUnderlines(ofstream& outFile);
  //******************************************************************
  //Purpose: To print the underlines to the output file
  //Input: none
  //Pre: outFile is opened & ok; an ExtStudRdType object has been
  //     initialized
  //Output: outFile
  //Post: The underlines have been printed to outFile
  //Note: calls PrintUnderlines from the base class
  //******************************************************************

  void PrintStats(ofstream& outFile, int maleCount, int femaleCount, int csCount, 
                  int cisCount, int validCount, int invalidCount, int aCount,
                  int bCount, int cCount, int dCount, int fcount, int freshCount,
                  int sophCount, int junCount, int senCount);
  //********************************************************************************************
  //Purpose: To print statistical information about the input student records to the output file
  //Input: maleCount, femaleCount, csCount, cisCount, validCount, invalidCount, aCount, bCount,
  //       cCount, dCount, fCount, freshCount, sophCount, junCount, senCount
  //Pre: maleCount, femaleCount, csCount, cisCount, validCount, invalidCount, aCount, bCount,
  //     cCount, dCount, fCount, freshCount, sophCount, junCount, senCount are initialized &
  //     have value and outFile is opened & ok
  //Output: outFile
  //Post: Statistical information about the record has been printed to outFile
  //Note: calls PrintStats from the base class
  //********************************************************************************************

  void CountGrade(int& aCount, int& bCount, int& cCount, int& dCount, int& fcount);
  //*********************************************************************************************
  //Purpose: To count the number of each letter grade
  //Input: aCount, bCount, cCount, dCount, fCount
  //Pre: aCount, bCount, cCount, dCount, fCount are initialized and record is valid
  //Output: aCount, bCount, cCount, dCount, fCount
  //Post: aCount, bCount, cCount, dCount, fCount have been updated if necessary
  //Note: exam1, exam2, exam3 must either be protected or private data
  //*********************************************************************************************

  void CountStanding(int& freshCount, int& sophCount, int& junCount, int& senCount);
  //**********************************************************************************************
  //Purpose: To count the # of freshman, sophmores, juniors & seniors
  //Input: freshCount, sophCount, junCount, senCount
  //Pre: freshCount, sophCount, junCount, senCount are initialized and record is valid
  //Output: freshCount, sophCount, junCount, senCount
  //Post: freshCount, sophCount, junCount, senCount have been updated if necessary
  //Note: totalCredits must either be protected or private data
  //**********************************************************************************************
}; 