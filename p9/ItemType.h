#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ID = 999;
const int MIN_ID = 111;
const float MAX_GPA = 4.00;
const float MIN_GPA = 0.00;

enum  RelationType {LESS, EQUAL, GREATER};

class ItemType
{						
  public:
    
    ItemType();
    ItemType(int i, float g, string m, char s);   
    RelationType ComparedTo(ItemType otheritem) const;
    void GetItemFromFile(ifstream& inFile);
    void GetIdFromFile (ifstream& inFile);
    void WriteIdToFile(ofstream& outFile);
    void WriteItemToFile(ofstream& outFile) const;
    void WriteInvalidItemToFile(ofstream& outFile) const;
    void Initialize(int i, float g, string m, char s);
    bool ValidItem();
    string MajorIs() const;
    void CountMaleFemale(int& maleCount, int& femaleCount);
    void CountCsIs(int& csCount, int& cisCount);
    void ReduceMajorCount(int& cisCount, int& csCount);
    void ReduceSexCount(int& maleCount, int& femaleCount);
    int IdIs() const;

  private:		
    int id;
    float gpa;
    string major;
    char sex;      
};	