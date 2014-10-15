//runBST.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #9
//
//DUE DATE: 04-03-14
//
//POSSIBLE POINTS: 30 Points
//
//Purpose:
//  Using a binary search tree, input items from file, print them &
//  print statistics about the BST and the items that were input
//************************************************************************
#include "TreeType.h"

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

 char actionLetter;
 TreeType binSTree;
 ItemType item;
 bool found;
 int cisCount = 0, csCount = 0, maleCount = 0, femaleCount = 0, validCount = 0;

 outFile << "<~~~~~~~~~~~~~~ GPA Report ~~~~~~~~~~~~~~~>" << endl;

 inFile >> actionLetter;
 while (inFile)
 {
  switch (actionLetter)
  {
   case 'A' :
    if (!binSTree.IsFull())
    {
     item.GetItemFromFile(inFile);

     if (item.ValidItem())
     { 
      item.CountMaleFemale(maleCount, femaleCount);
      item.CountCsIs(csCount, cisCount);

      binSTree.InsertItem(item);
     }
     else
      item.WriteInvalidItemToFile(outFile);
    }
    else
     outFile << endl << "No memory! No insert!" << endl;
    break; //end case A

   case 'D' :
    item.GetIdFromFile(inFile);
    if (!binSTree.IsEmpty())
    {
     binSTree.RetrieveItem(item, found);

     if (found)
     {
      binSTree.DeleteItem(item);
      item.ReduceMajorCount(cisCount, csCount);
      item.ReduceSexCount(maleCount, femaleCount);
     }
     else
      outFile << endl << "Item with id, " << item.IdIs()  << ", not found! No delete!" << endl;
    }
    else
     outFile << endl << "Tree is empty! No delete!" << endl;
    break; //end case D

   case 'P' :
    if (!binSTree.IsEmpty())
    {
     binSTree.PrintInorder(outFile); outFile << endl;
     binSTree.PrintPreorder(outFile); outFile << endl;
     binSTree.PrintPostorder(outFile); outFile << endl;
     binSTree.PrintMajorStat(outFile, cisCount, csCount); outFile << endl;
     binSTree.PrintSexStat(outFile, maleCount, femaleCount);
    }
    else
     outFile << endl << "Tree is empty! No print!" << endl;
    break; //end case P

   case 'C' :
    if (!binSTree.IsEmpty())
     outFile << endl << "Number of students: " << binSTree.CountNode() << endl;
    else
     outFile << endl << "Tree is empty! Number of nodes is zero!" << endl;
    break; //end case C

   case 'H' :
    if (!binSTree.IsEmpty())
     outFile << endl << "Height of Binary Search Tree is: " << binSTree.HeightIs() << endl;
    else
     outFile << endl << "Tree is empty! No height!" << endl;
    break; //end case H

   default  :
    outFile << "*** Invalid actionLetter: " << actionLetter << endl;
  } //end switch

  inFile >> actionLetter;
 } //end while loop for input

 outFile << endl << ">>> END <<<";

 inFile.close();
 outFile.close();

	return 0;
}