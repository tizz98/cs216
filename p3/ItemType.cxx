#include "ItemType.h"

ItemType::ItemType()
{
  id = -100;
  name = "zzzzzzz";
  gpa = -1.00;
  gender = 'x';
  major = "vvvvvvvvv";
}   	

ItemType::ItemType(int inId, string inName, float inGpa, char inGender, string inMajor)
{
  id = inId;
  name = inName;
  gpa = inGpa;
  gender = inGender;
  major = inMajor;
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
  inFile >> id >> name >> gpa >> major >> gender;
}

void ItemType::GetIdFromFile(ifstream& inFile)
{
  inFile >> id;
}
  
void ItemType::WriteItemToFile(ofstream& outFile) const 
{
  outFile.setf(ios::left);
  outFile << setw(17) << id << setw(17) << name << setw(6) << gpa << setw(10) << MajorIs() << setw(10)
          << gender << endl;
}

void ItemType::WriteInvalidItemToFile(ofstream& outFile) const
{
  outFile.setf(ios::left);
  outFile << setw(17) << id << setw(17) << name << setw(6) << gpa << setw(10) << MajorIs() << setw(5) 
          << gender << "  *** Invalid data" << endl;
}

bool ItemType::ValidItem()
{
  return ((id >= MIN_ID)&& 
          (id <= MAX_ID)&&
          (gpa >= MIN_GPA)&&
          (gpa <= MAX_GPA)&&
          ((gender == MALE)||(gender == FEMALE))&&
          ((major == CS)||(major == CIS)));
}

int ItemType::IdIs() const
{
 return id;
}

string ItemType::NameIs() const
{
 return name;
}

float ItemType::GpaIs() const
{
 return gpa;
}

char ItemType::GenderIs() const
{
 return gender;
}

string ItemType::MajorIs() const
{
 if (major == CS)
  return major;
 if (major == CIS)
  return "CIS";
}