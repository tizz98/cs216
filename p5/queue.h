#include <string.h>
#include "ItemType.h"

using namespace std;

const int MAX_SIZE = 10;

class Queue
{
  public:

    void MakeEmpty();

    bool IsEmpty() const;

    bool IsFull() const;

    void Enqueue(ItemType newItem);

    void Dequeue(ItemType& itemInQueue);

    int LengthIs();

    Queue();

private:
    ItemType data[MAX_SIZE+1];
    int front;
    int rear;
    int length;
};
