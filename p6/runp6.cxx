//runp6.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #6
//
//DUE DATE: 03-12-14
//
//POSSIBLE POINTS: 10 Points
//
//Purpose:
//  Use sorted linked list of an ItemType with following private data: 
//  coefficient (float) and degree (integer) to create a polynomial
//************************************************************************
#include "SortedType.h"

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

 SortedType polyList;
 ItemType item, tempItem;
 char actionLetter;
 bool found;

 outFile << "<* Polynomial *>" << endl;

 inFile >> actionLetter;

 while(inFile)
 {
  actionLetter = toupper(actionLetter); //incase the letter is lowercase

  switch (actionLetter)
  {
   case 'A' :
     item.GetItemFromFile(inFile);

     if (!polyList.IsFull())
      polyList.InsertItem(item);
     else
      outFile << "*** List is full, no add!" << endl;
    break; //end case A
   case 'D' :
     item.GetDegreeFromFile(inFile);
     polyList.RetrieveItem(item, found);

     if (found)
      polyList.DeleteItem(item);
     else
     {
      outFile << endl;
      outFile << "*** Term of degree " << item.DegreeIs()
              << " was not found therefore can't be deleted." << endl;
     }
    break; //end case D
   case 'U' :
     item.GetItemFromFile(inFile);
     tempItem = item;

     polyList.RetrieveItem(item, found);

     if (found)
      polyList.UpdateItem(tempItem);
     else
     {
      outFile << endl;
      outFile << "*** Term of degree " << item.DegreeIs()
              << " was not found therefore can't be updated." << endl;
     }
    break; //end case U
   case 'P' :
     if (!(polyList.LengthIs() == 0))
     {
      outFile << endl;
      outFile << "P(X) = ";
      polyList.Print(outFile);
      outFile << endl;
     }
     else
     {
      outFile << endl;
      outFile << "*** P (X) = no polynomial to print!" << endl;
     }
    break; //end case P
   case 'T' :
     outFile << endl;

     if (!(polyList.LengthIs() == 0))
      if (polyList.LengthIs() == 1)
       outFile << ">>> Polynomial has 1 term" << endl;
      else
       outFile << ">>> Polynomial has " << polyList.LengthIs()
               << " terms" << endl;
     else
      outFile << "*** No polynomial! There is no term to count!" << endl;
    break; //end case T
   default  :
    outFile << ">>> Invalid action letter: " << actionLetter << endl;
  } //end switch

  inFile >> actionLetter;
 } //end while loop

 outFile << endl;
 outFile << "~ end ~";

 inFile.close();
 outFile.close();

	return 0;
}