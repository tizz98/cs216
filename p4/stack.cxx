#include "stack.h"

StackType::StackType( )
{
  top = -1;
}

void StackType::MakeEmpty( ) 
{
  top = -1;
}

bool StackType::IsEmpty( ) const
{
  return ( top == -1 );
}

bool StackType::IsFull( ) const
{
  return  ( top == MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  top++;
  items[top] = newItem;	
}

void StackType::Pop(ItemType& item)
{
  item = items[top];
  top--;
}