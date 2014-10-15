//ExtStudType.cxx
#include "ExtStudRdType.h"

char ExtStudRdType::GradeIs() const
//******************************************************************
//Purpose: To return the letter grade based on the average of the 3
//         exams
//Input: none
//Pre: An ExtStudRdType object has been initialized
//Output: char
//Post: The letter grade has been returned
//Note: exam1, exam2, exam3 must be protected or public data
//******************************************************************
{
 switch (int((exam1 + exam2 + exam3) / 3))
 {
  case 90 ... 100 : return 'A'; break;
  case 80 ... 89  : return 'B'; break;
  case 70 ... 79  : return 'C'; break;
  case 60 ... 69  : return 'D'; break;
  case 0  ... 59  : return 'F'; break;
  default: return 'Z';
 }
}

string ExtStudRdType::StandingIs() const
//******************************************************************
//Purpose: To return the standing of the student based on how many
//         credits they have
//Input: none
//Pre: An ExtStudRdType object has been initialized
//Output: string
//Post: The student's standing has been returned
//Note: totalCredits must be protected of public data
//******************************************************************
{
 switch (totalCredits)
 {
  case 0  ... 30 : return "Freshman";  break;
  case 31 ... 60 : return "Sophomore"; break;
  case 61 ... 90 : return "Junior";    break;
  default: //also used for greater than 90 credits
   if (totalCredits > 90)
    return "Senior";
   else
    return "Invalid # of credits";
 }
}

void ExtStudRdType::PrintGradeStanding(ofstream& outFile)
//******************************************************************
//Purpose: To print the letter grade and standing to the output file
//Input: none
//Pre: outFile is opened & ok; an ExtStudRdType object has been
//     initialized and record is valid
//Output: outFile
//Post: The letter grade and standing has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << left << setw(10) << GradeIs() << setw(15) << StandingIs();
}

void ExtStudRdType::PrintTitles(ofstream& outFile)
//******************************************************************
//Purpose: To print the titles to the output file
//Input: none
//Pre: outFile is opened & ok; an ExtStudRdType object has been
//     initialized 
//Output: outFile
//Post: The titles have been printed to outFile
//Note: calls PrintTitles from the base class
//******************************************************************
{
 StudRdType::PrintTitles(outFile);
 outFile << left << setw(10) << "Grade" << setw(15) << "Standing";
}

void ExtStudRdType::PrintUnderlines(ofstream& outFile)
//******************************************************************
//Purpose: To print the underlines to the output file
//Input: none
//Pre: outFile is opened & ok; an ExtStudRdType object has been
//     initialized
//Output: outFile
//Post: The underlines have been printed to outFile
//Note: calls PrintUnderlines from the base class
//******************************************************************
{
 StudRdType::PrintUnderlines(outFile);
 outFile << left << setw(10) << "-----" << setw(15) << "--------";
}

void ExtStudRdType::PrintStats(ofstream& outFile, int maleCount, int femaleCount, int csCount, 
                             int cisCount, int validCount, int invalidCount, int aCount,
                             int bCount, int cCount, int dCount, int fCount, int freshCount,
                             int sophCount, int junCount, int senCount)
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
{
 StudRdType::PrintStats(outFile, maleCount, femaleCount, csCount, 
                        cisCount, validCount, invalidCount);
 outFile << endl;
 outFile << "*** A: " << float(aCount) / float(validCount) * 100 << "%" << endl;
 outFile << "*** B: " << float(bCount) / float(validCount) * 100 << "%" << endl;
 outFile << "*** C: " << float(cCount) / float(validCount) * 100 << "%" << endl;
 outFile << "*** D: " << float(dCount) / float(validCount) * 100 << "%" << endl;
 outFile << "*** F: " << float(fCount) / float(validCount) * 100 << "%" << endl;

 outFile << endl;
 outFile << "*** Freshman:  " << float(freshCount) / float(validCount) * 100 << "%" << endl;
 outFile << "*** Sophomore: " << float(sophCount)  / float(validCount) * 100 << "%" << endl;
 outFile << "*** Junior:    " << float(junCount)   / float(validCount) * 100 << "%" << endl;
 outFile << "*** Senior:    " << float(senCount)   / float(validCount) * 100 << "%" << endl;
}


void ExtStudRdType::CountGrade(int& aCount, int& bCount, int& cCount, int& dCount, int& fCount)
//*********************************************************************************************
//Purpose: To count the number of each letter grade
//Input: aCount, bCount, cCount, dCount, fCount
//Pre: aCount, bCount, cCount, dCount, fCount are initialized and record is valid
//Output: aCount, bCount, cCount, dCount, fCount
//Post: aCount, bCount, cCount, dCount, fCount have been updated if necessary
//Note: exam1, exam2, exam3 must either be protected or private data
//*********************************************************************************************
{
 switch (int((exam1 + exam2 + exam3) / 3))
 {
  case 90 ... 100 : aCount++; break;
  case 80 ... 89  : bCount++; break;
  case 70 ... 79  : cCount++; break;
  case 60 ... 69  : dCount++; break;
  case 0  ... 59  : fCount++; break;
  default: break;
 }
}

void ExtStudRdType::CountStanding(int& freshCount, int& sophCount, int& junCount, int& senCount)
//**********************************************************************************************
//Purpose: To count the # of freshman, sophmores, juniors & seniors
//Input: freshCount, sophCount, junCount, senCount
//Pre: freshCount, sophCount, junCount, senCount are initialized and record is valid
//Output: freshCount, sophCount, junCount, senCount
//Post: freshCount, sophCount, junCount, senCount have been updated if necessary
//Note: totalCredits must either be protected or private data
//**********************************************************************************************
{
 switch (totalCredits)
 {
  case 0  ... 30 : freshCount++; break;
  case 31 ... 60 : sophCount++;  break;
  case 61 ... 90 : junCount++;   break;
  default: //also used for greater than 90 credits
   if (totalCredits > 90)
    senCount++;
   else
    break;
 }
}