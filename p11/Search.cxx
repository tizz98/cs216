#include "Search.h"

Search::Search()
//********************************************************************
//Purpose: To initialize the values in mainData[] & unsuccData[] to -1
//Input: none
//Pre: A Search object has been declared
//Output: none
//Post: mainData[] & unsuccData[] values are set to -1
//Note: comp, totalComp, ASLSucc & ASLUnsucc are set to 0
//********************************************************************
{
 for (int i = 0; i < NUM_SUCCESS; ++ i)
  mainData[i] = -1;

 for (int i = 0; i < NUM_UNSUCC; ++i)
  unsuccData[i] = -1;

 comp = 0;
 totalComp = 0;
 ASLSucc = 0;
 ASLUnSucc = 0;
}

void Search::GetDataFromFile(ifstream& inFile)
//**********************************************************************
//Purpose: To input data into mainData and unsuccData from an input file
//Input: inFile
//Pre: inFile is opened and ok; a Search object has been initialized
//Output: none
//Post: mainData and unsuccData are set from inFile
//Note: none
//**********************************************************************
{
 for (int i = 0; i < NUM_SUCCESS; ++i)
  inFile >> mainData[i];

 for (int i = 0; i < NUM_UNSUCC; ++i)
  inFile >> unsuccData[i];
}

float Search::AvgSuccProbes() const
//**********************************************************************
//Purpose: To return the average successful probes
//Input: none
//Pre: a Search object has been initialized
//Output: float
//Post: a float has been returned which is the average successful probes
//Note: none
//**********************************************************************
{
 return (float(totalComp) / float(NUM_SUCCESS));
}

float Search::AvgUnSuccProbes() const
//************************************************************************
//Purpose: To return the average unsuccessful probes
//Input: none
//Pre: a Search object has been initialized
//Output: float
//Post: a float has been returned which is the average unsuccessful probes
//Note: none
//************************************************************************
{
 return (float(totalComp) / float(NUM_UNSUCC));
}

float Search::ASLSuccIs() const
//******************************************************************
//Purpose: To return the value of private data ASLSucc
//Input: none
//Pre: a Search object has been initialized
//Output: float
//Post: a float has been returned which is the value of ASLSucc
//Note: none
//******************************************************************
{
 return ASLSucc;
}

float Search::ASLUnSuccIs() const
//******************************************************************
//Purpose: To return the value of private data ASLUnSucc
//Input: none
//Pre: a Search object has been initialized
//Output: float
//Post: a float has been returned which is the value of ASLUnSucc
//Note: none
//******************************************************************
{
 return ASLUnSucc;
}