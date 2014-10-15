#include "BinSearch.h"

void Swap(ItemType& item1, ItemType& item2);
//******************************************************************
//Purpose: To swap two items
//Input: item1, item2
//Pre: item1 and item2 have value
//Output: item1, item2
//Post: item1 has the value item2 started with & vice versa
//Note: none
//******************************************************************

void ReheapDown(ItemType values[], int root, int bottom);
//******************************************************************
//Purpose: To make a heap out of values[]
//Input: values[], root, bottom
//Pre: values[], root & bottom have value
//Output: values[]
//Post: values[] is now a heap
//Note: recursive function
//******************************************************************


void BinSearch::SearchAndPrint(ofstream& outFile)
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
{
 bool found;
 totalComp = 0;

 PrintHeading(true, outFile);
 for (int i = 0; i < NUM_SUCCESS; ++i)
 {
  Search(mainData[i], found);
  outFile << left << setw(7) << mainData[i] << setw(15) << comp << endl;
 }
 
 ASLSucc = Search::AvgSuccProbes();
 outFile << endl;
 outFile << "Average Number of probes: " << ASLSucc << endl;

 totalComp = 0;
 outFile << endl;
 PrintHeading(false, outFile);
 for (int i = 0; i < NUM_UNSUCC; ++i)
 {
  Search(unsuccData[i], found);
  outFile << left << setw(7) << unsuccData[i] << setw(15) << comp << endl;
 }

 ASLUnSucc = Search::AvgUnSuccProbes();
 outFile << endl;
 outFile << "Average Number of probes: " << ASLUnSucc << endl;
}

void BinSearch::PrintHeading(bool successful, ofstream& outFile) const
//********************************************************************
//Purpose: To print the heading for the searches to an output file
//Input: successful
//Pre: outFile is opened & ok; successful has value; a BinSearch 
//     object has been initialized
//Output: outFile
//Post: The heading has been print to outFile
//Note: none
//********************************************************************
{
 if (successful)
  outFile << "<<<*** Successful Binary Search ***>>>" << endl;
 else
  outFile << "<<<*** Unsuccessful Binary Search ***>>>" << endl;

 outFile << endl;
 outFile << left << setw(7) << "ID" << setw(15) << "Number of Comparison" << endl;
 outFile << left << setw(7) << "--" << setw(15) << "--------------------" << endl;
}

void BinSearch::Search(ItemType item, bool& found)
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
{
 int first = 0;
 int last = NUM_SUCCESS - 1;
 comp = 0;
 int middle;
 found = false;

 while (last >= first && !found)
 {
  middle = (first + last) / 2;
  if (item < mainData[middle])
  {
   comp++;
   last = middle - 1;
  }
  else if (item > mainData[middle])
  {
   comp += 2;
   first = middle + 1;
  }
  else
  {
   comp += 2;
   found = true;
  }
 }

 totalComp += comp;
}

void BinSearch::Sort()
//******************************************************************
//Purpose: To sort the mainData[] using heap sort
//Input: none
//Pre: a BinSearch object has been initialized
//Output: none
//Post: mainData[] has been sorted
//Note: uses the recursive function ReheapDown & function Swap
//******************************************************************
{
 int index;

 //convert array into heap
 for (index = NUM_SUCCESS/2 - 1; index >= 0; index--)
  ReheapDown(mainData, index, NUM_SUCCESS - 1);

 //sort array
 for (index = NUM_SUCCESS - 1; index >= 1; index--)
 {
  Swap(mainData[0], mainData[index]);
  ReheapDown(mainData, 0, index - 1);
 }
}

void Swap(ItemType& item1, ItemType& item2)
//******************************************************************
//Purpose: To swap two items
//Input: item1, item2
//Pre: item1 and item2 have value
//Output: item1, item2
//Post: item1 has the value item2 started with & vice versa
//Note: none
//******************************************************************
{
 int temp = item1;
 item1 = item2;
 item2 = temp;
}

void ReheapDown(ItemType values[], int root, int bottom)
//******************************************************************
//Purpose: To make a heap out of values[]
//Input: values[], root, bottom
//Pre: values[], root & bottom have value
//Output: values[]
//Post: values[] is now a heap
//Note: recursive function
//******************************************************************
{
 int maxChild;
 int rightChild;
 int leftChild;

 leftChild = root * 2 + 1;
 rightChild = root * 2 + 2;

 if (leftChild <= bottom)
 {
  if (leftChild == bottom)
   maxChild = leftChild;
  else
  {
   if (values[leftChild] <= values[rightChild])
    maxChild = rightChild;
   else
    maxChild = leftChild;
  }
  if (values[root] < values[maxChild])
  {
   Swap(values[root], values[maxChild]);
   ReheapDown(values, maxChild, bottom);
  }
 }
}