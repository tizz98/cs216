//runp5.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #5
//
//DUE DATE: 02-26-14
//
//POSSIBLE POINTS: 10 Points
//
//Purpose:
//  Using queues to pair people together for a dance scenario
//************************************************************************
#include <fstream>
#include "queue.h"

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

 char sex;
 ItemType male, female, name;
 Queue maleQ, femaleQ;

 inFile >> sex >> name;
 while(inFile)
 {
  if (sex == 'M')
  {
   if (!maleQ.IsFull())
    maleQ.Enqueue(name);
   else
    outFile << "~~~Queue overflow! No enqueue!" << endl;
  } // end if for male
  else if (sex == 'F')
  {
   if (!femaleQ.IsFull())
    femaleQ.Enqueue(name);
   else
    outFile << "~~~Queue overflow! No enqueue!" << endl;
  } //end else if for female

  inFile >> sex >> name;
 } //end input while loop

 outFile << "~<* ACM dancing partners *>~" << endl;

 while(!maleQ.IsEmpty() && !femaleQ.IsEmpty())
 {
  maleQ.Dequeue(male);
  femaleQ.Dequeue(female);

  outFile << male << " + " << female << endl;
 } //end while loop for printing pairs

 outFile << endl;
 
 if (maleQ.IsEmpty() && femaleQ.IsEmpty())
  outFile << "~** Dance cannot be start! No male or female show up so far! **~" << endl;

 if (!maleQ.IsEmpty())
 {
  if (maleQ.LengthIs() == 1)
   outFile << "*** There is 1 man waiting for the next round." << endl;
  else
   outFile << "*** There are " << maleQ.LengthIs() << " men waiting for the next round." << endl;

  maleQ.Dequeue(male);
  outFile << "*** " << male << " will be the first one to get a partner." << endl;
 } //end if male queue still has items

 if (!femaleQ.IsEmpty())
 {
  if (femaleQ.LengthIs() == 1)
   outFile << "*** There is 1 woman waiting for the next round." << endl;
  else
   outFile << "*** There are " << femaleQ.LengthIs() << " women waiting for the next round." << endl;

  femaleQ.Dequeue(female);
  outFile << "*** " << female << " will be the first one to get a partner." << endl;
 } //end if female queue still has items

 outFile << endl;
 outFile << "<~* end *~>";

 return 0;
}