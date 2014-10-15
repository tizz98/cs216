#ifndef SEQSEARCH_H
#define SEQSEARCH_H

#include "Search.h"

class SeqSearch : public Search
{
 public:
  void PrintHeading(bool successful, ofstream& outFile) const;
  //******************************************************************
  //Purpose: To print the heading for the searches to an output file
  //Input: successful
  //Pre: outFile is opened & ok; successful has value; a SeqSearch 
  //     object has been initialized
  //Output: outFile
  //Post: The heading has been print to outFile
  //Note: none
  //******************************************************************

  void SearchAndPrint(ofstream& outFile);
  //*******************************************************************
  //Purpose: To search for elements from mainData[] & unsuccData[] and
  //         print the results in an output file
  //Input: none
  //Pre: outFile is opened and ok & a SeqSearch object has been 
  //     initialized
  //Output: outFile
  //Post: The elements from mainData[] & unsuccData[] have been
  //      searched for and results printed in outFile
  //Note: none
  //*******************************************************************

  void Search(ItemType item, bool& found);
  //************************************************************************
  //Purpose: To search for an item in the mainData[] using sequential search
  //Input: item, found
  //Pre: item & found have value and a SeqSearch object has been
  //     initialized
  //Output: found
  //Post: The item has been searched for and if it was found
  //      found == true
  //Note: none
  //************************************************************************

};

#endif /* SEQSEARCH_H */