#include "queue.h"

const int VEC_SIZE = MAX_SIZE + 1;

void Queue::MakeEmpty()
{
  front = rear = VEC_SIZE - 1;
  length = 0;
}	

Queue::Queue()
{
  front = rear = VEC_SIZE - 1;
  length = 0;
}

bool Queue::IsEmpty() const
{
  return (rear == front);
}

bool Queue::IsFull() const
{
  return ((rear + 1) % VEC_SIZE == front);
}

void Queue::Enqueue(ItemType newItem)
{
  rear = (rear + 1) % VEC_SIZE;
  //data[rear] = newItem;
  strncpy(data[rear], newItem, NAME_SIZE);
  length++;
}

void Queue::Dequeue(ItemType& itemInQueue)
{
  front = (front + 1) % VEC_SIZE;
  //itemInQueue = data[front];
  strncpy(itemInQueue, data[front], NAME_SIZE);
  length--;
}

int Queue::LengthIs()
{
 return length;
}