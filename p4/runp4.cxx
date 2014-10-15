//runp4.cxx
//************************************************************************
//AUTHOR: Elijah Wilson
//
//COURSE TITLE: Programming II
//
//PROF NAME: Moe Bidgoli
//
//ASSIGNMENT NUMBER: #4
//
//DUE DATE: 02-12-14
//
//POSSIBLE POINTS: 10 Points
//
//Purpose:
//  Use a single stack to evaluate a postfix expression with a maximum
//  size of 3
//************************************************************************
#include "stack.h"

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

 StackType stack;
 ItemType newItem, item;   //for the stack
 ItemType oprtrR, tempAns; //for operations
 char operand, myItem;
 int op, ans = 0;
 string line = "";
 bool error = false;

 outFile << "*** Evaluation of Postfix Expression ***" << endl;

 stack.MakeEmpty();
 newItem.GetItemFromFile(inFile);

 while(newItem.CharIs() != ';')
 {
  if (!stack.IsFull())
  {
   myItem = newItem.CharIs();

   if (line == "")    //to check if the string is empty
    line = newItem.CharIs();
   else
    line = line + " " + newItem.CharIs();

   if (isdigit(myItem))
    stack.Push(newItem);
   else
   {
    operand = myItem;

    if (!stack.IsEmpty())
    {
     stack.Pop(oprtrR);
     stack.Pop(tempAns);

     op = oprtrR.CharIs() - '0';
     ans = tempAns.CharIs() - '0';

     switch (operand)
     {
      case '/' : 
       ans = ans / op;
       break; //end case division
      case '*' :
       ans = ans * op;
       break; //end case mulitplication
      case '+' :
       ans = ans + op;
       break; //end case addition
      case '-' :
       ans = ans - op;
       break; //end case subtractions
      default :
       outFile << ">>>Invalid operand" << endl;
       break; //end default case
     } //end switch

     item.SetInt(ans);
     stack.Push(item);
    } //end if for stack being not empty
    else
    {
     if(!error) //to reduce redundancy for the output file
      outFile << "~~~Stack underflow! No evaluation!" << endl;
     error = true;
    }
   } //end else for stack being not a digit
  } //end if for stack being not full
  else
  {
   if(!error) //to reduce redundancy for the output file
    outFile << "~~~Stack overflow! No evaluation!" << endl;
   error = true;
  }

  newItem.GetItemFromFile(inFile);
 } //end while loop

 if (!error)
  outFile << line << "\t: " << ans << endl;

 outFile << endl;
 outFile << "< end >";

 return 0;
}