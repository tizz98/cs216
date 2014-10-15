#include "SeqSearch.h"

void SeqSearch::PrintHeading(bool successful, ofstream& outFile) const
//********************************************************************
//Purpose: To print the heading for the searches to an output file
//Input: successful
//Pre: outFile is opened & ok; successful has value; a SeqSearch 
//     object has been initialized
//Output: outFile
//Post: The heading has been print to outFile
//Note: none
//********************************************************************
{
	if (successful)
  outFile << "<<<*** Successful Sequential Search ***>>>" << endl;
 else
  outFile << "<<<*** Unsuccessful Sequential Search ***>>>" << endl;

 outFile << endl;
 outFile << left << setw(7) << "ID" << setw(15) << "Number of Comparison" << endl;
 outFile << left << setw(7) << "--" << setw(15) << "--------------------" << endl;
}

void SeqSearch::SearchAndPrint(ofstream& outFile)
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

void SeqSearch::Search(ItemType item, bool& found)
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
{
 int index = 0;
 comp = 0;

 while (index < NUM_SUCCESS && item != mainData[index])
 {
  index++;
  comp++;
 }

 if (index < NUM_SUCCESS)
  comp++;

 totalComp += comp;
 found = (index < NUM_SUCCESS);
}