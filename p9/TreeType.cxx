//TreeType.cxx
#include "TreeType.h"

void Destroy(TreeNode* &tree);
void CopyTree(TreeNode* &copy, const TreeNode* originalTree);
void RetrieveHelper(TreeNode* tree, ItemType &item, bool &found);
void InsertHelper(TreeNode* &ptr, ItemType item);
void Delete(TreeNode* &tree, ItemType item);
void DeleteNode(TreeNode* &tree);
void GetPredecessor(TreeNode* tree, ItemType& data);
void Inorder(TreeNode* tree, ofstream& outFile);
int Height(TreeNode* root);
void Preorder(TreeNode* tree, ofstream& outFile);
void PostOrder(TreeNode* tree, ofstream& outFile);
void PrintHeading(ofstream& outFile);
int CountNodeHelper(TreeNode* node);

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

TreeType::TreeType()
{
  root = NULL;
}

TreeType::~TreeType()
{
  Destroy(root);
}

void Destroy(TreeNode* &tree)
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

TreeType::TreeType(const TreeType &originalTree)
// Calls recursive function CopyTree to copy tree pointed 
// to by originalTree into self.
{
  CopyTree(root, originalTree.root);
}

void CopyTree(TreeNode* &copy, const TreeNode* originalTree)
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}


void TreeType::operator=(const TreeType &originalTree)
// Calls recursive function CopyTree to copy tree pointed
// to by originalTree into self.
{
  if (&originalTree == this)
    return;                // Ignore assigning self to self.
  Destroy(root);           // Deallocate existing tree nodes.
  CopyTree(root, originalTree.root);
}


bool TreeType::IsEmpty() const
{
  return (root == NULL);
}

bool TreeType::IsFull() const
{
   TreeNode* ptr;
   
   ptr = new TreeNode;
   if(ptr == NULL)
     return true;
   else
   {
     delete ptr;
     return false;
   }
}

void TreeType::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  RetrieveHelper(root, item, found);
}

void RetrieveHelper(TreeNode* tree, ItemType &item, bool &found)
{
  if (tree == NULL)
    found = false;                              // item is not found.
  else if (item.ComparedTo(tree->info) == LESS)
    RetrieveHelper(tree->left, item, found);    // Search left subtree.
  else if (item.ComparedTo(tree->info) == GREATER)
    RetrieveHelper(tree->right, item, found);   // Search right subtree.
  else
  {
    item = tree->info;                           // item is found.
    found = true;
  }
}


void TreeType::InsertItem(ItemType item)
{
  InsertHelper(root, item);
}


void InsertHelper(TreeNode* &ptr, ItemType item)
{
  if (ptr == NULL)
  {
     ptr =new TreeNode;
     ptr->right = NULL;
     ptr->left = NULL;
     ptr->info = item;
  }
  else if(item.ComparedTo(ptr->info)== LESS)
          InsertHelper(ptr->left, item);
  else if(item.ComparedTo(ptr->info) == GREATER)
          InsertHelper(ptr->right, item);
}


void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}

void Delete(TreeNode* &tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
     Delete(tree->left, item);
  else
     if (item.ComparedTo(tree->info) == GREATER)
	Delete(tree->right, item);
     else
        DeleteNode(tree);
} 	


void DeleteNode(TreeNode* &tree)
{
  ItemType data;
  TreeNode* tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else 
    if (tree->right == NULL)
    {
       tree = tree->left;
       delete tempPtr;
    }
    else
    {
       GetPredecessor(tree->left, data);
       tree->info = data;
       Delete(tree->left, data);    // Delete predecessor node.
    }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}


void TreeType::PrintInorder(ofstream& outFile) const
// Calls recursive function to print items inorder.
{
 outFile << "Inorder:" << endl;
 PrintHeading(outFile);
 Inorder(root, outFile);
}

void Inorder(TreeNode* tree, ofstream& outFile)
// Prints info member of items inorder.
{
  if (tree != NULL)
  {
    Inorder(tree->left, outFile);   // Print left subtree.
    tree->info.WriteItemToFile(outFile);
    Inorder(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::PrintPreorder(ofstream& outFile) const
{
 outFile << "Preorder:" << endl;
 PrintHeading(outFile);
 Preorder(root, outFile);
}

void Preorder(TreeNode* tree, ofstream& outFile)
{
 if (tree != NULL)
 {
  tree->info.WriteItemToFile(outFile);
  Preorder(tree->left, outFile);    //Print left subtree
  Preorder(tree->right, outFile);   //Print right subtree
 }
}

void TreeType::PrintPostorder(ofstream& outFile) const
{
 outFile << "Postorder:" << endl;
 PrintHeading(outFile);
 PostOrder(root, outFile);
}

void PostOrder(TreeNode* tree, ofstream& outFile)
{
 if (tree != NULL)
 {
  PostOrder(tree->left, outFile);   //Print left subtree
  PostOrder(tree->right, outFile);  //Print right subtree
  tree->info.WriteItemToFile(outFile);
 }
}

int TreeType::HeightIs()
{
 return Height(root);
}

int Height(TreeNode* root)
{
 if (root == NULL)
  return 0;
 else
 {
  int left_height = Height(root->left);
  int right_height = Height(root->right);

  if (left_height > right_height)
   return left_height + 1;
  else
   return right_height + 1;
 }
}

int TreeType::CountNode()
{
 return (CountNodeHelper(root) - 1);
}

int CountNodeHelper(TreeNode* node)
{
 if (node == NULL)
  return 1;
 else
 {
  int left_count = CountNodeHelper(node->left);
  int right_count = CountNodeHelper(node->right);
  return left_count + right_count;
 }
}

void PrintHeading(ofstream& outFile)
{
 outFile << left << setw(15) << "Student Id" << setw(10) << "GPA"
         << setw(10) << "Major" << setw(5) << "Sex" << endl;

 outFile << left << setw(15) << "----------" << setw(10) << "---"
         << setw(10) << "-----" << setw(5) << "---" << endl;
}

void TreeType::PrintMajorStat(ofstream& outFile, int cisCount, int csCount)
{
 outFile << "CIS: " << (float(cisCount) / float(CountNode())) * 100 << "%" << endl;
 outFile << "CS: "  << (float(csCount) / float(CountNode())) * 100 << "%" << endl;
}

void TreeType::PrintSexStat(ofstream& outFile, int maleCount, int femaleCount)
{
 outFile << "Male: " << (float(maleCount) / float(CountNode())) * 100 << "%" << endl;
 outFile << "Female: " << (float(femaleCount) / float(CountNode())) * 100 << "%" << endl;
}