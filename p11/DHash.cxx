#include "DHash.h"

int h1(ItemType item);
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: none
//******************************************************************

int h2(ItemType item);
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: This is only used for double hashing
//******************************************************************


DHash::DHash()
//******************************************************************
//Purpose: To initialize all the values of the private data to -1
//Input: none
//Pre: A DHash object has been delcared
//Output: none
//Post: A DHash object has been initialized
//Note: none
//******************************************************************
{
	for (int i = 0; i < HASHT_SIZE; ++i)
  doubleHashTable[i] = -1;
}

void DHash::Sort()
//******************************************************************
//Purpose: To put all the elements from mainData[] in the hash table
//Input: none
//Pre: A DHash object has been initialized
//Output: none
//Post: The elements from mainData[] are put in the hash table
//Note: mainData[] is in the "Search" class
//******************************************************************
{
 int index;
 int i2 = 1;

 for (int i = 0; i < NUM_SUCCESS; ++i)
 {
  index = h1(mainData[i]);

  if (doubleHashTable[index] == -1) //index isn't occupied
   doubleHashTable[index] = mainData[i];
  else //find an index not occupied
  {
   while (!(doubleHashTable[index] == -1))
   {
    index = (h1(mainData[i]) + (i2 * (h2(mainData[i]) + 1))) % HASH_NUM;
    i2++;
   }

   doubleHashTable[index] = mainData[i];
  } //end else
 } //end for loop
}

void DHash::SearchAndPrint(ofstream& outFile)
//*******************************************************************
//Purpose: To search for elements from mainData[] & unsuccData[] and
//         print the results in an output file
//Input: none
//Pre: outFile is opened and ok & a DHash object has been initialized
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

void DHash::Search(ItemType item, bool& found)
//********************************************************************
//Purpose: To search for an item in the Hash Table by double hashing
//Input: item, found
//Pre: item & found have value and a DHash object has been initialized
//Output: found
//Post: The item has been searched for and if it was found
//      found == true
//Note: none
//********************************************************************
{
 int index = h1(item);
 int i2 = 1;
 found = false;
 comp = 0;

 if (doubleHashTable[index] == item)
 {
  comp++;
  found = true;
 }
 else if (doubleHashTable[index] == -1)
  comp++;
 else
 {
  comp++;

  while(!found && !(doubleHashTable[index] == -1))
  {
   comp++;
   if (doubleHashTable[index] == item)
    found = true;
   else
   {
    index = (h1(item) + (i2 * (h2(item) + 1))) % HASH_NUM;
    i2++;
   }
  } // end while loop

  if (doubleHashTable[index] == -1)
   comp++;
 } //end else (not found first try)

 totalComp += comp;
}

void DHash::PrintArr(ofstream& outFile) const
//******************************************************************
//Purpose: To print the hash table to an output file
//Input: none
//Pre: a DHash object has been initialized
//Output: outFile
//Post: doubleHashTable has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << "Storing with Double Hashing Method/Hash Table" << endl;

 outFile << endl;
 outFile << left << setw(15) << "Array Index" << setw(7) << "ID" << endl;
 outFile << left << setw(15) << "-----------" << setw(7) << "--" << endl;

 for (int i = 0; i < HASHT_SIZE; ++i)
  outFile << left << setw(15) << i << setw(7) << doubleHashTable[i] << endl;
}

void DHash::PrintHeading(bool successful, ofstream& outFile) const
//******************************************************************
//Purpose: To print the heading for the searches to an output file
//Input: successful
//Pre: outFile is opened & ok; successful has value; a DHash object
//     has been initialized
//Output: outFile
//Post: The heading has been print to outFile
//Note: none
//******************************************************************
{
 if (successful)
  outFile << "<<<*** Succ/Double Hashing Method ***>>>" << endl;
 else
  outFile << "<<<*** Unsucc/Double Hashing Method ***>>>" << endl;

 outFile << endl;
 outFile << left << setw(7) << "ID" << setw(15) << "Number of Comparison" << endl;
 outFile << left << setw(7) << "--" << setw(15) << "--------------------" << endl;
}

int h1(ItemType item)
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: none
//******************************************************************
{
 return (item % HASH_NUM);
}

int h2(ItemType item)
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: This is only used for double hashing
//******************************************************************
{
 return (item % (HASH_NUM - 1));
}