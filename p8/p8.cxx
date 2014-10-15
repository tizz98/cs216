#include "p8.h"

void ReadToArray(ifstream& inFile, int intArray[], int& length)
//******************************************************************
//Purpose: To input 10 integers into an array from inFile
//Input: inFile
//Pre: inFile is opened and ok; intArray and length are declared
//Output: intArray, length
//Post: intArray holds what was input from inFile and length was
//      updated
//Note: none
//******************************************************************
{
 length = 0;
	while (inFile)
 {
  inFile >> intArray[length];
  length++;
 }
}

void printArray(ofstream& outFile, const int intArray[], int first, int last)
//****************************************************************************
//Purpose: To print intArray to the output file using recursion
//Input: intArray, first, last
//Pre: outFile is opened and ok; intArray, first, last have value
//Output: outFile
//Post: The array is printed to outFile
//Note: none
//****************************************************************************
{
 if (first <= last)
 {
  outFile << intArray[first] << " ";
  printArray(outFile, intArray, first + 1, last);
 }
}

void printArrayRev(ofstream& outFile, const int intArray[], int first, int last)
//*******************************************************************************
//Purpose: To print intArray in reverse order using recursion
//Input: intArray, first, last
//Pre: outFile is opened and ok; intArray, first, last have value
//Output: outFile
//Post: The array is printed in reverse to outFile
//Note: none
//*******************************************************************************
{
 if (first <= last)
 {
  outFile << intArray[last] << " ";
  printArrayRev(outFile, intArray, first, last - 1);
 }
}

int maxOfArray(const int intArray[], int length)
//******************************************************************
//Purpose: To find the maximum number in the array using recursion
//Input: intArray, length
//Pre: intArray and length have value
//Output: int
//Post: The maximum number in intArray has been returned
//Note: none
//******************************************************************
{
 if(length == 0) 
  return intArray[0];

 int tempMax = maxOfArray(intArray, length-1);

 if(intArray[length - 1] > tempMax) 
  return intArray[length - 1];
 else
  return tempMax;
}

int sumOfInt(int n)
//******************************************************************
//Purpose: To add up all the numbers from 1 to n using recursion
//Input: n
//Pre: n has value and is greater than 0
//Output: int
//Post: The sum of all integers from 1 to n has been returned
//Note: none
//******************************************************************
{
 if (n == 1)
  return 1;
 else
  return (n + sumOfInt(n-1));
}

int power(int x, int n)
//******************************************************************
//Purpose: To find x to the power of n using recursion
//Input: x, n
//Pre: x & n have value
//Output: int
//Post: x to the power of n has been returned
//Note: none
//******************************************************************
{
 if (n == 0)
  return 1;
 else
  return (x * power(x, n-1));
}

void binConversion(ofstream& outFile, int n)
//******************************************************************
//Purpose: To convert n from decimal to binary using recursion
//Input: n
//Pre: outFile is opened and ok; n has value
//Output: outFile
//Post: n has been converted to binary and output to outFile
//Note: none
//******************************************************************
{
 int remainder;

 if(n <= 1) //if n is 1 or 0
 {
  outFile << n;
  return;
 }

 remainder = n % 2; //the remainder of n / 2
 n = n / 2;         //getting the result of n / 2

 binConversion(outFile, n);    
 outFile << remainder;
}