#include "ItemType.h"

ItemType::ItemType()
{
  id = -100;
  gpa = -4.00;
  major = "ZZZ";
  sex = 'X';
}   	

ItemType::ItemType(int i, float g, string m, char s)
{
  id = i;
  gpa = g;
  major = m;
  sex = s;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{						
 if (id < otherItem.id)
	 return  LESS;
 else if (id  > otherItem.id)
  return  GREATER;
 else  
  return  EQUAL;
}

void ItemType::GetItemFromFile(ifstream& inFile)
{
  inFile >> id >> gpa >> major >> sex;
}

void ItemType::GetIdFromFile(ifstream& inFile)
{
  inFile >> id;
}

void ItemType::WriteIdToFile(ofstream& outFile)
{
  outFile << id;
}  

void ItemType::WriteItemToFile(ofstream& outFile) const 
{
  outFile << left << setw(15) << id << setw(10) << gpa << setw(10)
          << MajorIs() << setw(5) << sex << endl;
}

void ItemType::WriteInvalidItemToFile(ofstream& outFile) const
{
  outFile << id << setw(10) << gpa << setw(10) << MajorIs() << setw(5) << sex
          << setw(20) << "**** Invalid data" << endl;
}

void ItemType::Initialize(int i, float g, string m, char s)
{
  id = i;
  gpa = g;
  major = m;
  sex = s;
} 	

bool ItemType::ValidItem()
{
  return ((id >= MIN_ID) && (id <= MAX_ID) 
          && (gpa >= MIN_GPA) && (gpa <= MAX_GPA)
          && ((MajorIs() == "CIS") || (MajorIs() == "CS"))
          && ((sex == 'M') || (sex == 'F')));
}

string ItemType::MajorIs() const
{
 if (major == "IS")
  return "CIS";
 else
  return major;
}

void ItemType::CountMaleFemale(int& maleCount, int& femaleCount)
{
 if (sex == 'M')
  maleCount++;
 else if (sex == 'F')
  femaleCount++;
}

void ItemType::CountCsIs(int& csCount, int& cisCount)
{
 if (MajorIs() == "CS")
  csCount++;
 else if (MajorIs() == "CIS")
  cisCount++;
}

void ItemType::ReduceMajorCount(int& cisCount, int& csCount)
{
 if (MajorIs() == "CS")
  csCount--;
 else if (MajorIs() == "CIS")
  cisCount--;
}

void ItemType::ReduceSexCount(int& maleCount, int& femaleCount)
{
 if (sex == 'M')
  maleCount--;
 else if (sex == 'F')
  femaleCount--;
}

int ItemType::IdIs() const
{
 return id;
}