#include <fstream>

using namespace std;

const int ARRAY_SIZE = 10;

void ReadToArray(ifstream& inFile, int intArray[], int& length);
//******************************************************************
//Purpose: To input 10 integers into an array from inFile
//Input: inFile
//Pre: inFile is opened and ok; intArray and length are declared
//Output: intArray, length
//Post: intArray holds what was input from inFile and length was
//		    updated
//Note: none
//******************************************************************

void printArray(ofstream& outFile, const int intArray[], int first, int last);
//****************************************************************************
//Purpose: To print intArray to the output file using recursion
//Input: intArray, first, last
//Pre: outFile is opened and ok; intArray, first, last have value
//Output: outFile
//Post: The array is printed to outFile
//Note: none
//****************************************************************************

void printArrayRev(ofstream& outFile, const int intArray[], int first, int last);
//*******************************************************************************
//Purpose: To print intArray in reverse order using recursion
//Input: intArray, first, last
//Pre: outFile is opened and ok; intArray, first, last have value
//Output: outFile
//Post: The array is printed in reverse to outFile
//Note: none
//*******************************************************************************

int maxOfArray(const int intArray[], int length);
//******************************************************************
//Purpose: To find the maximum number in the array using recursion
//Input: intArray, length
//Pre: intArray and length have value
//Output: int
//Post: The maximum number in intArray has been returned
//Note: none
//******************************************************************

int sumOfInt(int n);
//******************************************************************
//Purpose: To add up all the numbers from 1 to n using recursion
//Input: n
//Pre: n has value and is greater than 0
//Output: int
//Post: The sum of all integers from 1 to n has been returned
//Note: none
//******************************************************************

int power(int x, int n);
//******************************************************************
//Purpose: To find x to the power of n using recursion
//Input: x, n
//Pre: x & n have value
//Output: int
//Post: x to the power of n has been returned
//Note: none
//******************************************************************

void binConversion(ofstream& outFile, int n);
//******************************************************************
//Purpose: To convert n from decimal to binary using recursion
//Input: n
//Pre: outFile is opened and ok; n has value
//Output: outFile
//Post: n has been converted to binary and output to outFile
//Note: none
//******************************************************************