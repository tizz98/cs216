//SortedType.h
#include "ItemType.h"

struct NodeType
{
  ItemType info;
  NodeType* next;
};

class SortedType
{
 public:
  SortedType();
  ~SortedType();
  SortedType(const SortedType& otherList);
  bool IsFull() const;
  int  LengthIs() const;
  void MakeEmpty();
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item); 
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
  void Print(ofstream& outFile); 
  void UpdateItem(ItemType item);

 private:
  NodeType* listData;
  int length;
  NodeType* currentPos;
};