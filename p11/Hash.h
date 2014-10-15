#ifndef HASH_H
#define HASH_H

#include "Search.h"

class Hash : public Search
{
 public:
  Hash();
  //******************************************************************
  //Purpose: To initialize the private data to -1
  //Input: none
  //Pre: a Hash object has been declared
  //Output: none
  //Post: All the values in hashDivTable[] are set to -1
  //Note: none
  //******************************************************************

  void Sort();
  //******************************************************************
  //Purpose: To put all the elements from mainData[] in the hash table
  //Input: none
  //Pre: A Hash object has been initialized
  //Output: none
  //Post: The elements from mainData[] are put in the hash table
  //Note: mainData[] is in the "Search" class
  //******************************************************************

  void SearchAndPrint(ofstream& outFile);
  //*******************************************************************
  //Purpose: To search for elements from mainData[] & unsuccData[] and
  //         print the results in an output file
  //Input: none
  //Pre: outFile is opened and ok & a Hash object has been initialized
  //Output: outFile
  //Post: The elements from mainData[] & unsuccData[] have been
  //      searched for and results printed in outFile
  //Note: none
  //*******************************************************************

  void Search(ItemType item, bool& found);
  //********************************************************************
  //Purpose: To search for an item in the Hash Table by hashing division
  //Input: item, found
  //Pre: item & found have value and a Hash object has been initialized
  //Output: found
  //Post: The item has been searched for and if it was found
  //      found == true
  //Note: none
  //********************************************************************

  void PrintArr(ofstream& outFile) const;
  //******************************************************************
  //Purpose: To print the hash table to an output file
  //Input: none
  //Pre: a Hash object has been initialized
  //Output: outFile
  //Post: hashDivTable has been printed to outFile
  //Note: none
  //******************************************************************

  void PrintHeading(bool successful, ofstream& outFile) const;
  //******************************************************************
  //Purpose: To print the heading for the searches to an output file
  //Input: successful
  //Pre: outFile is opened & ok; successful has value; a Hash object
  //     has been initialized
  //Output: outFile
  //Post: The heading has been print to outFile
  //Note: none
  //******************************************************************
  

 private:
  ItemType hashDivTable[HASHT_SIZE];
};

#endif /* HASH_H */