#include "ItemType.h"

struct TreeNode;

class TreeType
{
 public: 
 TreeType(); 	          

	~TreeType(); 		

	TreeType(const TreeType &originalTree);
	// copy constructor

	void operator=(const TreeType &originalTree);
	// Overloads the assignment operator.

	bool IsEmpty() const;	
	// Function: Determines whether the tree is empty.
	// Post: Function value = (tree is empty)

 bool IsFull() const;

	void RetrieveItem(ItemType& item, bool& found);
	// Function: Retrieves item whose key matches item's key
	// (if present).

	void InsertItem(ItemType item);
	// Function: Adds item to the tree.

	void DeleteItem(ItemType item);
	// Function: Deletes the item whose key matches item's key.
	
	void PrintInorder(ofstream& outFile) const;
	// Function: Prints the values in the tree inorder

 void PrintPreorder(ofstream& outFile) const;
	// Function: Prints the values in the tree preorder

 void PrintPostorder(ofstream& outFile) const;
	// Function: Prints the values in the tree postoeder

 int HeightIs();

 int CountNode();

 void PrintMajorStat(ofstream& outFile, int cisCount, int csCount);

 void PrintSexStat(ofstream& outFile, int maleCount, int femaleCount);
	
 private:
	TreeNode* root;
};