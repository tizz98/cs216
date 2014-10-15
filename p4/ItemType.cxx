#include "ItemType.h"

ItemType::ItemType()
{
	myChar = 'x';
}

ItemType::ItemType(char inChar)
{
 myChar = inChar;
}

char ItemType::CharIs() const
{
 return myChar;
}

void ItemType::GetItemFromFile(ifstream& inFile)
{
 inFile >> myChar;
}

void ItemType::SetInt(int inInt)
{
 myChar = inInt;
}