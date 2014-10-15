//ItemType.cxx
#include "ItemType.h"

ItemType::ItemType()
{
 coefficient = -99.99;
 degree = -42;
}

ItemType::ItemType(float inCoefficient, int inDegree)
{
 coefficient = inCoefficient;
 degree = inDegree;
}

RelationType ItemType::ComparedTo(ItemType otherItem)
{
 if (degree < otherItem.degree)
  return  LESS;
 else if (degree  > otherItem.degree)
  return  GREATER;
 else  
  return  EQUAL;
}

void ItemType::GetItemFromFile(ifstream& inFile)
{
 inFile >> coefficient >> degree;
}

void ItemType::GetDegreeFromFile(ifstream& inFile)
{
 inFile >> degree;
}

void ItemType::WriteItemToFile(ofstream& outFile, bool isFirst)
{
 if (degree != 0)
 {
  if (coefficient > 0) //positive coefficient
  {
   if (!isFirst) //not the first to be printed
    if (degree > 1)
     if (coefficient != 1)
      outFile << " + " << coefficient << "X^" << degree;
     else //coefficient == 1
      outFile << " + X^" << degree;
    else
     if (coefficient != 1)
      outFile << " + " << coefficient << "X";
     else //coefficient == 1
      outFile << " + X";
   else //first to be printed
    if (degree > 1)
     if (coefficient != 1)
      outFile << coefficient << "X^" << degree;
     else //coefficient == 1
      outFile << "X^" << degree;
    else if (degree == 1)
     if (coefficient != 1)
      outFile << coefficient << "X";
     else //coefficient == 1
      outFile << "X";
  } //end if for positive coefficient
  else //negative coefficient
  {
   if (!isFirst) //not the first to be printed
    if (degree > 1)
     if (coefficient != -1)
      outFile << " - " << abs(coefficient) << "X^" << degree;
     else //coefficient == -1
      outFile << " - X^" << degree;
    else
     if (coefficient != -1)
      outFile << " - " << abs(coefficient) << "X";
     else //coefficient == -1
      outFile << " - X";
   else //first to be printed
    if (degree > 1)
     if (coefficient != -1)
      outFile << coefficient << "X^" << degree;
     else //coefficient == -1
      outFile << "-X^" << degree;
    else if (degree == 1)
     if (coefficient != -1)
      outFile << coefficient << "X";
     else //coefficient == -1
      outFile << "-X";
  } //end if for negative coefficient
 } //end if for degree not equal to 0
 else if (degree == 0)
  outFile << coefficient;
}

int ItemType::DegreeIs() const
{
 return degree;
}