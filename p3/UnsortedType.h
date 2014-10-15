#include  "ItemType.h"

class  UnsortedType	
{			
 public :

   UnsortedType();
   void MakeEmpty();
   bool IsFull() const;              
   int LengthIs() const;  
   void RetrieveItem(ItemType& item, bool& found);
   void InsertItem(ItemType item); 	
   void DeleteItem(ItemType item); 	
   void ResetList();
   void GetNextItem(ItemType& item) ; 	 
   void PrintList(ofstream& outFile);
   void printCSMajors(ofstream& outFile, ItemType item, int csCount);
   void printISMajors(ofstream& outFile, ItemType item, int cisCount);
   void printTopGPA(ofstream& outFile, ItemType item);
   void countMaleFemale(int& maleCount, int& femaleCount);
   void countCsIs(int& csCount, int& cisCount);

 private :

  int length ;           
  ItemType info[MAX_ITEMS] ;          
  int currentPos ;
} ;
