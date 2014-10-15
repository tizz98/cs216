#include <fstream>
#include <cctype>
#include <string>

using namespace std;

const int MAX_ITEMS = 3;

class ItemType
{
 public:
	 ItemType();
  ItemType(char inChar);
  char CharIs() const;
  void GetItemFromFile(ifstream& inFile);
  void SetInt(int inInt);

 private:
  char myChar;
};