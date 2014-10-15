//ItemType.h
#include <fstream>
#include <cctype> //toupper
#include <cmath>  //abs

enum RelationType { GREATER, EQUAL, LESS };

using namespace std;

class ItemType
{
 public:
 	ItemType();
  ItemType(float inCoefficient, int inDegree);
  RelationType ComparedTo(ItemType item);
  void GetItemFromFile(ifstream& inFile);
  void GetDegreeFromFile(ifstream& inFile);
  void WriteItemToFile(ofstream& outFile, bool isFirst);
  int DegreeIs() const;

 private:
  float coefficient;
  int degree;	
};