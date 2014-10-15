//runSearch.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #11
//
//DUE DATE: 04-23-14
//
//POSSIBLE POINTS: 30 Points
//
//Purpose:
//  To use sequential search, binary search, hashing-division and double
//  hasing with a set of 40 integers, 20 for data/successful search and 
//  20 for unsuccessful search.
//************************************************************************
#include "BinSearch.h"
#include "SeqSearch.h"
#include "Hash.h"
#include "DHash.h"
#include "runSearch.h"

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

 SeqSearch sequential;
 BinSearch binary;
 Hash hashing;
 DHash dHashing;

 /* Sequential */
 sequential.GetDataFromFile(inFile);
 sequential.SearchAndPrint(outFile); outFile << endl;

 openCloseInFile(inFile);  //to be able to use inFile again

 /* Binary */
 binary.GetDataFromFile(inFile);
 binary.Sort();
 binary.SearchAndPrint(outFile); outFile << endl;

 openCloseInFile(inFile);  //to be able to use inFile again

 /* Hashing Division */
 hashing.GetDataFromFile(inFile);
 hashing.Sort();
 hashing.PrintArr(outFile); outFile << endl;
 hashing.SearchAndPrint(outFile); outFile << endl;

 openCloseInFile(inFile);  //to be able to use inFile again

 /* Double Hashing */
 dHashing.GetDataFromFile(inFile);
 dHashing.Sort();
 dHashing.PrintArr(outFile); outFile << endl;
 dHashing.SearchAndPrint(outFile); outFile << endl;

 /* Stats & End Msg */
 printStats(outFile, sequential, binary, hashing, dHashing);
 printEndMsg(outFile);

 inFile.close();
 outFile.close();

 return 0;
}