#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 5;
const int MAX_ID = 999;
const int MIN_ID = 111;
const float MAX_GPA = 4.0;
const float MIN_GPA = 0.0;
const char MALE = 'M';
const char FEMALE = 'F';
const string CS = "CS";
const string CIS = "IS";

enum  RelationType {LESS, EQUAL, GREATER};

class ItemType
{						
  public :
    
    ItemType();
    ItemType(int inId, string inNamee, float inGpa, char inGender, string inMajor);   
    RelationType ComparedTo(ItemType otheritem) const;
    void GetItemFromFile(ifstream& inFile);
    void GetIdFromFile(ifstream& inFile);
    void WriteItemToFile(ofstream& outFile) const;
    void WriteInvalidItemToFile(ofstream& outFile) const;
    bool ValidItem();
    int IdIs() const;
    string NameIs() const;
    float GpaIs() const;
    char GenderIs() const;
    string MajorIs() const;

  private :		
    int id;
    string name;
    float gpa;
    char gender;
    string major;       
} ;	
