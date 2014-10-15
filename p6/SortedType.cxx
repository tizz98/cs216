//SortedType.cxx
#include "SortedType.h"

SortedType::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

SortedType::~SortedType() 
{
  MakeEmpty();
}

SortedType::SortedType(const SortedType& otherList)
{
    NodeType* fromPtr;	// Pointer into list being copied from
    NodeType* toPtr;   	// Pointer into new list being built
    if(otherList.listData == NULL)
    {
        listData = NULL;
        return;
    }
    // Copy first node
    fromPtr = otherList.listData;
    listData = new NodeType;
    listData->info = fromPtr->info;

    // Copy remaining nodes
   
    toPtr = listData;
    fromPtr = fromPtr->next;
    while (fromPtr != NULL)
    {
        toPtr->next = new NodeType;
        toPtr = toPtr->next;
        toPtr->info = fromPtr->info;
        fromPtr = fromPtr->next;
    }
    toPtr->next = NULL;
}

bool SortedType::IsFull() const
{
  NodeType* ptr;

  ptr = new NodeType;
  if (ptr == NULL)
    return true;
  else
  {
    delete ptr;
    return false;
  }
}

int SortedType::LengthIs() const
{
  return length;
}


void SortedType::MakeEmpty()
{
  NodeType* tempPtr;
  while (listData != NULL) // traverse list, deallocating each node in turn
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0; 
}


void SortedType::DeleteItem(ItemType item)
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item.ComparedTo(listData->info)== EQUAL)
  {
    tempLocation = location;
    listData = listData->next;		// Delete first node.
  }
  else
  {
    while (!((item.ComparedTo((location->next)->info))== EQUAL))
      location = location->next;
    
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void SortedType::ResetList()
{
  currentPos = NULL;
}
 

void SortedType::RetrieveItem(ItemType& item, bool& found)
{
  bool moreToSearch;
  NodeType* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    switch(item.ComparedTo(location->info))
    {
      case GREATER:
        location = location->next;
        moreToSearch = (location != NULL);
        break;
  
      case EQUAL:
        found = true;
        item = location->info;
        break;
  
      case LESS:
        moreToSearch = false;
        break;
    }
  }
}

void SortedType::InsertItem(ItemType item)
{
  NodeType* newNode;  // pointer to node being inserted
  NodeType* predLoc;  // trailing pointer
  NodeType* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if(item.ComparedTo(location->info) == GREATER)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType;
  newNode->info = item;

  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}


void SortedType::GetNextItem(ItemType& item)
{
  if (currentPos == NULL) //Wrap at end of list
    currentPos = listData; 

  item = currentPos->info;
  currentPos = currentPos->next;
} 

void SortedType::Print(ofstream& outFile)
{
   currentPos = listData;
   bool isFirst = true;

   while(currentPos != NULL)
   {
    currentPos ->info.WriteItemToFile(outFile, isFirst);
    currentPos = currentPos->next;

    isFirst = false;
   }
}

void SortedType::UpdateItem(ItemType item)
{
  DeleteItem(item);
  InsertItem(item);
}