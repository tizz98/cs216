//runp8.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #8
//
//DUE DATE: 03-26-14
//
//POSSIBLE POINTS: 30 Points
//
//Purpose:
//  To use recursive functions to do various tasks with an integer array
//************************************************************************
#include "p8.h"

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

 int intArray[ARRAY_SIZE];
 int length, first, last, max;

 ReadToArray(inFile, intArray, length);
 length--;  //to reduce length by 1 because of the while loop on input
 max = maxOfArray(intArray, length);
 first = 0;
 last = ARRAY_SIZE - 1;

 outFile << "~ Recursion Output ~" << endl << endl;

 outFile << "Array: ";
 printArray(outFile, intArray, first, last); outFile << endl;

 outFile << endl;
 outFile << "Array in reverse order: ";
 printArrayRev(outFile, intArray, first, last); outFile << endl;

 outFile << endl;
 outFile << "Max of array: " << max << endl;

 outFile << endl;
 outFile << "SUM of 1..." << max << ": "
 		      << sumOfInt(max) << endl;

 outFile << endl;
 outFile << intArray[0] << " power of " << intArray[1] << ": "
         << power(intArray[0], intArray[1]) << endl;

 outFile << endl;
 outFile << "(" << max << ") DEC = " << "(";
 binConversion(outFile, max);
 outFile << ") BIN" << endl;

 outFile << endl;
 outFile << "<*~ end ~*>";

 inFile.close();
 outFile.close();

 return 0;
}