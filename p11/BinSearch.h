#ifndef BINSEARCH_H
#define BINSEARCH_H

#include "Search.h"

class BinSearch : public Search
{
 public:
  void SearchAndPrint(ofstream& outFile);
  //*******************************************************************
  //Purpose: To search for elements from mainData[] & unsuccData[] and
  //         print the results in an output file
  //Input: none
  //Pre: outFile is opened and ok & a BinSearch object has been 
  //     initialized
  //Output: outFile
  //Post: The elements from mainData[] & unsuccData[] have been
  //      searched for and results printed in outFile
  //Note: none
  //*******************************************************************

  void PrintHeading(bool successful, ofstream& outFile) const;
  //******************************************************************
  //Purpose: To print the heading for the searches to an output file
  //Input: successful
  //Pre: outFile is opened & ok; successful has value; a BinSearch 
  //     object has been initialized
  //Output: outFile
  //Post: The heading has been print to outFile
  //Note: none
  //******************************************************************

  void Search(ItemType item, bool& found);
  //********************************************************************
  //Purpose: To search for an item in the mainData[] using binary search
  //Input: item, found
  //Pre: item & found have value and a BinSearch object has been
  //     initialized
  //Output: found
  //Post: The item has been searched for and if it was found
  //      found == true
  //Note: none
  //********************************************************************

  void Sort();
  //******************************************************************
  //Purpose: To sort the mainData[] using heap sort
  //Input: none
  //Pre: a BinSearch object has been initialized
  //Output: none
  //Post: mainData[] has been sorted
  //Note: uses the recursive function ReheapDown & function Swap
  //******************************************************************

};

#endif /* BINSEARCH_H */