#include  "UnsortedType.h"

UnsortedType::UnsortedType()
{
  length = 0;
}   	

void UnsortedType::MakeEmpty ( )  
{    
   length = 0 ;
}
bool UnsortedType::IsFull () const
{
   return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{    
   return length ;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)  
{    bool moreToSearch;
     int location = 0;

     found = false;
	moreToSearch = (location < length);
	while (moreToSearch  &&  !found)
	{ switch (item.ComparedTo(info[location]))
    	  {       case  LESS	:
		  case  GREATER : location++;
				  moreToSearch = (location < length);
                                  break ;
		  case  EQUAL	: found = true;
				  item = info[location] ;
				  break ;
   	  }
        }
}

void UnsortedType::InsertItem(ItemType item)
{
	info[length] = item ;
	length++ ;
}


void UnsortedType::DeleteItem(ItemType item) 
{    
     int location = 0;
    
     while (item.ComparedTo(info[location]) != EQUAL)
	location++;

	info[location] = info[length - 1] ;
	length-- ;
}


void UnsortedType::ResetList()  
{    
   currentPos = -1;
}

void  UnsortedType::GetNextItem(ItemType& item)  
{
   currentPos++;
   item = info[currentPos];
}

void UnsortedType::PrintList(ofstream& outFile)
{
  ItemType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     item.WriteItemToFile(outFile);
  }
}

void UnsortedType::printCSMajors(ofstream& outFile, ItemType item, int csCount)
{
 outFile << "-----------------------------------------------------------------" << endl;
 outFile << "CS Major" << endl;
 outFile << "--------" << endl;

 ResetList();

 if(csCount > 0)
 {
  for (int i = 0; i < length; ++i)
  {
   GetNextItem(item);

   if (item.MajorIs() == CS)
   {
    outFile << left << setw(6) << item.IdIs() << setw(6) << item.GpaIs() << setw(3) 
            << item.GenderIs() << endl;
   }
  }
 }
 else
  outFile << ">>>No CS majors!" << endl;
}

void UnsortedType::printISMajors(ofstream& outFile, ItemType item, int cisCount)
{
 outFile << "-----------------------------------------------------------------" << endl;
 outFile << "CIS Major" << endl;
 outFile << "--------" << endl;

 ResetList();

 if(cisCount > 0)
 {
  for (int i = 0; i < length; ++i)
  {
   GetNextItem(item);

   if (item.MajorIs() == "CIS")
   {
    outFile << left << setw(6) << item.IdIs() << setw(6) << item.GpaIs() << setw(3) 
            << item.GenderIs() << endl;
   }
  }
 }
 else
  outFile << ">>>No CIS majors!" << endl;
}

void UnsortedType::printTopGPA(ofstream& outFile, ItemType item)
{
 int count = 0;

 outFile << "-----------------------------------------------------------------" << endl;
 outFile << left << setw(17) << "TOP STUDENT ID" << setw(17) << "Name" << setw(6) << "GPA" << endl;
 outFile << left << setw(17) << "--------------" << setw(17) << "----" << setw(6) << "---" << endl;

 ResetList();

 for (int i = 0; i < length; ++i)
 {
  GetNextItem(item);

  if (item.GpaIs() >= 3.00)
  {
   count++;

   outFile << left << setw(17) << item.IdIs() << setw(17) << item.NameIs() << setw(6) 
           << item.GpaIs() << endl;
  }
 }

 if (count == 0)
  outFile << ">>>No students with GPA above 3.00!" << endl;

 outFile << endl;
}

void UnsortedType::countMaleFemale(int& maleCount, int& femaleCount)
{
 ItemType item;
 ResetList();

 for (int i = 0; i < length; ++i)
 {
  GetNextItem(item);

  if (item.GenderIs() == MALE)
   maleCount++;
  else if (item.GenderIs() == FEMALE)
   femaleCount++;
 }
}
void UnsortedType::countCsIs(int& csCount, int& cisCount)
{
 ItemType item;
 ResetList();

 for (int i = 0; i < length; ++i)
 {
  GetNextItem(item);

  if (item.MajorIs() == CS)
   csCount++;
  else if (item.MajorIs() == "CIS")
   cisCount++;
 }
}