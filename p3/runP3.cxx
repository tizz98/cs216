//runP3.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #3
//
//DUE DATE: 02-12-14
//
//POSSIBLE POINTS: 10 Points
//
//Purpose:
//
//  Using unsorted lists to input a number of student records from file
//  then print them to file.
//************************************************************************

#include "UnsortedType.h"
#include <fstream>

//Functions
void printHeading(ofstream& outFile);
void printTitleHeadings(ofstream& outFile);
void printEndMsg(ofstream& outFile);
void printCSMajors(ofstream& outFile, ItemType item);
void printISMajors(ofstream& outFile, ItemType item);
void printTopGPA(ofstream& outFile, ItemType item);
void printStat(ofstream& outFile, int csCount, int cisCount, int femaleCount, int maleCount, int validCount);
//End Funtions

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
 ItemType item;
 UnsortedType rdList;
 int maleCount = 0;
 int femaleCount = 0;
 int csCount = 0;
 int cisCount = 0;
 int validCount = 0;
 bool found;

 printHeading(outFile);

 rdList.MakeEmpty();

 inFile >> actionLetter;

 while (inFile)
 {
  switch (actionLetter)
  {   
   case 'A' :
         if(!rdList.IsFull())
         {
          item.GetItemFromFile(inFile);

          if (item.ValidItem())
          {
           validCount++;
           rdList.InsertItem(item);
          }
          else
           item.WriteInvalidItemToFile(outFile);
         }
         else
         {
          item.GetItemFromFile(inFile);
          outFile << "~~>List is full! No add!" << endl;
         }
         break; //end case A
   case 'D' :
         item.GetIdFromFile(inFile);
         rdList.RetrieveItem(item, found);
         if (found)
         {
          rdList.DeleteItem(item);
          validCount--;
         }
         else
          outFile << "ID: " << item.IdIs()
                  << " was not found, therefore cannot be deleted."
                  << endl;
         break; //end case D
   case 'P' :
         if (!(rdList.LengthIs() == 0))
         {
          outFile << endl;
          printTitleHeadings(outFile);
          rdList.PrintList(outFile);

          rdList.countMaleFemale(maleCount, femaleCount);
          rdList.countCsIs(csCount, cisCount);

          printStat(outFile, csCount, cisCount, femaleCount, maleCount, validCount);
         }
         else
          outFile << "~~> List is empty! No print!" << endl;
         break; //end case P
   case 'C' :
         rdList.printCSMajors(outFile, item, csCount);
         break; //end case C
   case 'I' :
         rdList.printISMajors(outFile, item, cisCount);
         break; //end case I
   case 'G' :
         rdList.printTopGPA(outFile, item);
         break; //end case G
   default :
         outFile << ">>>Invalid action letter: " << actionLetter << endl;
         break;
   } //end switch

  inFile >> actionLetter;
 } //end while loop

 printEndMsg(outFile);

 inFile.close();
 outFile.close();

 return 0;
} //end main

void printHeading(ofstream& outFile)
{
 outFile << "<~~~~~~~~~~~~~~        GPA Report      ~~~~~~~~~~~~~~~>" << endl;
}
void printEndMsg(ofstream& outFile)
{
 outFile << endl;
 outFile << ">>>*  End  Of GPA Report *<<<";
}
void printTitleHeadings(ofstream& outFile)
{
 outFile << left << setw(17) << "STUDENT ID" << setw(17) << "NAME" << setw(6) << "GPA" 
         << setw(10) << "MAJOR" << setw(3) << "SEX" << endl;
 outFile << left << setw(17) << "----------" << setw(17) << "----" << setw(6) << "---"
         << setw(10) << "-----" << setw(3) << "---" << endl;
}
void printStat(ofstream& outFile, int csCount, int cisCount, int femaleCount, int maleCount, int validCount)
{
 outFile << endl;
 outFile << "CIS: " << float(cisCount) / float(validCount) * 100 << "%" << endl;
 outFile << "CS : " << float(csCount)  / float(validCount) * 100 << "%" << endl;

 outFile << endl;
 outFile << "F: " << float(femaleCount) / float(validCount) * 100 << "%" << endl;
 outFile << "M: " << float(maleCount)   / float(validCount) * 100 << "%" << endl;
}