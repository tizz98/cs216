#ifndef SEARCH_H
#define SEARCH_H

#include "ItemType.h"

class Search
{
 public:
 	Search();
  //********************************************************************
  //Purpose: To initialize the values in mainData[] & unsuccData[] to -1
  //Input: none
  //Pre: A Search object has been declared
  //Output: none
  //Post: mainData[] & unsuccData[] values are set to -1
  //Note: comp, totalComp, ASLSucc & ASLUnsucc are set to 0
  //********************************************************************

  void GetDataFromFile(ifstream& inFile);
  //**********************************************************************
  //Purpose: To input data into mainData and unsuccData from an input file
  //Input: inFile
  //Pre: inFile is opened and ok; a Search object has been initialized
  //Output: none
  //Post: mainData and unsuccData are set from inFile
  //Note: none
  //**********************************************************************

  float AvgSuccProbes() const;
  //**********************************************************************
  //Purpose: To return the average successful probes
  //Input: none
  //Pre: a Search object has been initialized
  //Output: float
  //Post: a float has been returned which is the average successful probes
  //Note: none
  //**********************************************************************

  float AvgUnSuccProbes() const;
  //************************************************************************
  //Purpose: To return the average unsuccessful probes
  //Input: none
  //Pre: a Search object has been initialized
  //Output: float
  //Post: a float has been returned which is the average unsuccessful probes
  //Note: none
  //************************************************************************

  float ASLSuccIs() const;
  //******************************************************************
  //Purpose: To return the value of private data ASLSucc
  //Input: none
  //Pre: a Search object has been initialized
  //Output: float
  //Post: a float has been returned which is the value of ASLSucc
  //Note: none
  //******************************************************************

  float ASLUnSuccIs() const;
  //******************************************************************
  //Purpose: To return the value of private data ASLUnSucc
  //Input: none
  //Pre: a Search object has been initialized
  //Output: float
  //Post: a float has been returned which is the value of ASLUnSucc
  //Note: none
  //******************************************************************

 protected:
  ItemType mainData[NUM_SUCCESS];
  ItemType unsuccData[NUM_UNSUCC];
  int comp;
  int totalComp;
  float ASLSucc;
  float ASLUnSucc;
};

#endif /* SEARCH_H */