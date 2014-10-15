#include "Hash.h"

int h(ItemType item);
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: none
//******************************************************************


Hash::Hash()
//******************************************************************
//Purpose: To initialize the private data to -1
//Input: none
//Pre: a Hash object has been declared
//Output: none
//Post: All the values in hashDivTable[] are set to -1
//Note: none
//******************************************************************
{
 for (int i = 0; i < HASHT_SIZE; ++i)
  hashDivTable[i] = -1;
}

void Hash::Sort()
//******************************************************************
//Purpose: To put all the elements from mainData[] in the hash table
//Input: none
//Pre: A Hash object has been initialized
//Output: none
//Post: The elements from mainData[] are put in the hash table
//Note: mainData[] is in the "Search" class
//******************************************************************
{
 int index;

 for (int i = 0; i < NUM_SUCCESS; ++i)
 {
  index = h(mainData[i]);

  if (hashDivTable[index] == -1) //index isn't occupied
   hashDivTable[index] = mainData[i];
  else //find an index not occupied
  {
   while (!(hashDivTable[index] == -1))
    index++;

   hashDivTable[index] = mainData[i];
  } //end else
 } //end for loop
}

void Hash::SearchAndPrint(ofstream& outFile)
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

void Hash::Search(ItemType item, bool& found)
//********************************************************************
//Purpose: To search for an item in the Hash Table by hashing division
//Input: item, found
//Pre: item & found have value and a Hash object has been initialized
//Output: found
//Post: The item has been searched for and if it was found
//      found == true
//Note: none
//********************************************************************
{
 int index = h(item);
 int tempIndex = index;
 found = false;
 comp = 0;

 if (hashDivTable[index] == item)
 {
  comp++;
  found = true;
 }
 else if (hashDivTable[index] == -1)
  comp++;
 else
 {
  comp++;
  if (index == HASHT_SIZE - 1)
     index = 0;
  else
     index++;
  while(!found && (index != tempIndex) && (hashDivTable[index] != -1))
  {
   comp++;
   if (hashDivTable[index] == item)
    found = true;
   else
   {
    if (index == HASHT_SIZE - 1)
     index = 0;
    else
     index++;
   } // end else (not found nth try in while loop)
  } // end while loop

  if (hashDivTable[index] == -1)
   comp++;
 } //end else (not found first try)

 totalComp += comp;
}

void Hash::PrintArr(ofstream& outFile) const
//******************************************************************
//Purpose: To print the hash table to an output file
//Input: none
//Pre: a Hash object has been initialized
//Output: outFile
//Post: hashDivTable has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << "Storing with Division Method/Hash Table" << endl;

 outFile << endl;
 outFile << left << setw(15) << "Array Index" << setw(7) << "ID" << endl;
 outFile << left << setw(15) << "-----------" << setw(7) << "--" << endl;

 for (int i = 0; i < HASHT_SIZE; ++i)
  outFile << left << setw(15) << i << setw(7) << hashDivTable[i] << endl;
}

void Hash::PrintHeading(bool successful, ofstream& outFile) const
//******************************************************************
//Purpose: To print the heading for the searches to an output file
//Input: successful
//Pre: outFile is opened & ok; successful has value; a Hash object
//     has been initialized
//Output: outFile
//Post: The heading has been print to outFile
//Note: none
//******************************************************************
{
 if (successful)
  outFile << "<<<*** Succ/Division Method ***>>>" << endl;
 else
  outFile << "<<<*** Unsucc/Division Method ***>>>" << endl;

 outFile << endl;
 outFile << left << setw(7) << "ID" << setw(15) << "Number of Comparison" << endl;
 outFile << left << setw(7) << "--" << setw(15) << "--------------------" << endl;
}

int h(ItemType item)
//******************************************************************
//Purpose: To "hash" an item and return that value
//Input: item
//Pre: item has value
//Output: int
//Post: The hash value of "item" has been returned
//Note: none
//******************************************************************
{
	return item % HASH_NUM;
}