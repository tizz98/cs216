#include "ItemType.h"

class StackType  
{
  public:
    StackType( );  

    void MakeEmpty( );
	
    bool IsEmpty( ) const;

    bool IsFull( ) const;
	
    void Push(ItemType newItem);
	
    void Pop(ItemType& item);

  private:
    int top;
    ItemType items[MAX_ITEMS];	// array of ItemType
};