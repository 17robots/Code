// =============================================
// = Assignment E problem - binary search tree =
// =============================================
// EXAM PROBLEM PROGRAM
// COPYRIGHT (C)2015 The University of Akron, Department of Computer Science. All rights reserved.
// Instructions: You have 2 hours to debug the code. Make your changes and submit this by copying
//               your code into the quiz's answer.
// Refer to the document "ASSGNE Binary Tree Search Fix Me", located under UNIT 3 content in Brightspace, for details.
//
// This program is intended exclusively for use by The University of Akron's Department of Computer Science
// as an examination problem.
//
// THIS PROGRAM'S CONTENT IS PROTECTED
// The code and associated content are either the property of, or used with permission by, The University of Akron,
// Department of Computer Science and may be protected by copyright and other restrictions. Copyrights in the site
// content may also be owned by individuals and entities other than, and in addition to, The University of Akron,
// Department of Computer Science. The use of this code by you, or anyone else authorized by you, is prohibited,
// except for purposes of completing the final exam BST problem. Any unauthorized use of the coding may violate
// copyright laws, trademark laws, the laws of privacy and publicity, and communications regulations and statutes.


// The programmer has left for vacation in a big hurry, and you have been asked to fix this program's error(s)
// The program is poorly documented, and you will need to analyze the code and resolve the issue or issues that
// you encounter while testing. The program has been corrected once the test case completes and the success message
// wraps up the program. Do not change the test case coding in main.

#include <cstdlib>
#include <ctime>
#include <iostream>

class Node
{
 public:
  Node* left;
  Node* right;
  Node** parentConnection;
  int data;

  Node(const int& num) { data = num; left = right = 0; parentConnection = 0; }
};

class myTree
{
 public:
  Node* root;

  myTree();
  ~myTree();

  void insert(Node* addThis);
  void insert(Node* addThis, Node* subRoot);

  void del(const int&);

  void preorder();
  void preorder(Node* subRoot);

  void inorder();
  void inorder(Node* subRoot);

  void postorder();
  void postorder(Node* subRoot);

  Node* search(const int& num) { search(root, num); }
  Node* search(Node*, const int&);

  void layerorder();

  void display();
  void display(Node*, const int&);

  void empty();

  Node* findIOP(Node*);
};

myTree::myTree()
{
  root = 0;
}


myTree::~myTree()
{}


void myTree::insert(Node* addThis)
{
  if (!root)
    {
      root = addThis;
      root->parentConnection = &root;
    }
  else
    insert(addThis, root);
}

void myTree::insert(Node* addThis, Node* subRoot)
{
  if (addThis->data <= subRoot->data)
    {

      if (subRoot->left)
      {
        insert(addThis, subRoot->left);
      }
      else
      {
        subRoot->left = addThis;
        subRoot->left->parentConnection = &addThis;
      }
    }
  else
    {
      if (subRoot->right)
      {
        insert(addThis, subRoot->right);
      }
      else
      {
        subRoot->right = addThis;
        subRoot->right->parentConnection = &addThis;
      }
    }
}

void myTree::inorder()
{
  inorder(root);  // start the recursion
  std::cout << std::endl;
}

void myTree::inorder(Node* subRoot)
{
  if (!subRoot)
    return;
  inorder(subRoot->left);
  std::cout << subRoot->data << " ";
  inorder(subRoot->right);
}

void myTree::preorder()
{
  preorder(root);
  std::cout << std::endl;
}

void myTree::preorder(Node* subRoot)
{
  if (!subRoot)
    return;
  std::cout << subRoot->data << " ";
  preorder(subRoot->left);
  preorder(subRoot->right);
}

void myTree::postorder()
{
  postorder(root);
  std::cout << std::endl;
}
void myTree::postorder(Node* subRoot)
{
  if (!subRoot)
    return;
  postorder(subRoot->left);
  postorder(subRoot->right);
  std::cout << subRoot->data << " ";
}

void myTree::del(const int& num)
{

  Node* del = search(num);
  if (!del)
    return;
  if (del->left == del->right)
    {
      *(del->parentConnection) = del->right;
    }

  else if (!del->left || !del->right)
    {
      if (del->left)
      {
        *(del->parentConnection) = del->right;
        del->left->parentConnection = del->parentConnection;
      }
      else
      {
        *(del->parentConnection) = del->left;
        del->right->parentConnection = del->parentConnection;
      }
    }
  else
    {
      Node* iop = findIOP(del->left);

      if (iop->left)
      {
        iop->left->parentConnection = iop->parentConnection;
      }
      *(iop->parentConnection) = iop->left;

      iop->left = del->left;

      if (iop->left)
        iop->left->parentConnection = &iop->left;

      iop->right = del->right;
      if (iop->right)
	     iop->right->parentConnection = &iop->right;

      *(del->parentConnection) = iop;
      iop->parentConnection = del->parentConnection;

    }
  delete del;
}

Node* myTree::search(Node* subRoot, const int& num)
{
  if(!subRoot)
    return 0;
  if (subRoot->data == num)
    return subRoot;
  if (num < subRoot->data)
    return search(subRoot->left, num);
  return search(subRoot->right, num);
}

void myTree::display()
{
  display(root, 0);
}

void myTree::display(Node* subRoot, const int& indent)
{
  if (!subRoot)
    {
      for (int i = 0; i < indent; ++i)
	    std::cout << " ";
      std::cout << "NULL" << std::endl;
    }
  else
    {

      display(subRoot->right, indent + 5);
      for (int i = 0; i < indent; ++i)
        std::cout << " ";
      std::cout << subRoot->data << std::endl;
      display(subRoot->left, indent + 5);
    }
}

Node* myTree::findIOP(Node* subRoot)
{
  if (subRoot && !subRoot->right)
    return subRoot;
  return findIOP(subRoot->right);
}


int main()
{
  std::srand(59);

  // create the tree
  myTree *bst = new myTree();

  //fill the tree
  for (int i = 0; i < 10; ++i)
    {
      bst->insert(new Node(std::rand() % 100));
    }


  bst->display();
  std::cout << "********************************************" << std::endl;
  bst->inorder();
  std::cout << "********************************************" << std::endl;
  bst->preorder();
  std::cout << "********************************************" << std::endl;
  bst->postorder();
  std::cout << "********************************************" << std::endl;

  std::cout << "********************************************" << std::endl;
  bst->del(83);
  bst->display();
  std::cout << "********************************************" << std::endl;
  bst->inorder();
  std::cout << "********************************************" << std::endl;
  bst->preorder();
  std::cout << "********************************************" << std::endl;
  bst->postorder();

  std::cout << "***********     SUCCESS     ****************" << std::endl;


}

/*
Medhod Explanations
Insert - check to see if the value of the new node to append is smaller than the root node's value. If it is then try to put it on the left. If not, 
on the right it goes. If the side exists, try to insert the new node under than side. If it doesnt exist, then make that the new node and set the 
parent to be the node above

Inorder - check if the element is null, go down the left side with the same function, print the data, go down the right side

Preorder - check if the element is null, display the data, go down the left side of the tree with the same function, go down the right side with the same function

Postorder - check if the element is null, go down the left side with the same function, go down the right side, print the data

Del - search for the node in the tree then rewire things. If the two children are the same, then keep the right side. If the left only exists then trim the right 
and keep the left. Same with the right. If both exists, find an intersection point that can be used as the node instead of the one being deleted and finally rewire everything

Search - Check to see if the subroot exists. If it does, check to see if the value is the same, returning the subroot if it is. If the value is less than the subroot, 
then go down the left side recursively. If bigger, go the right side with the same function

Display - checks to see if the element is null, if it is, then go indent spaces and print NULL. If it isnt, then go through the right side recursively with 5 
extra spaces each time, print out the current number of spaces and then print out the data, then do the same on the left side to balance out

FindIOP - go down the right side and try to find a value that does not have a right side and return it, otherwise keep going down that side
*/

/*
Activity Log
1. Reviewed Code and ran it to see what errors it produced - no errors and success message displayed on first go
2. Since no errors, began by looking at unnecessary variables 
3. Deleted the Node* next variable as it was unnecessary
4. Added indent to make the code more readable for the for loop on line 
5. commented things out and am going method by method
6. Starting with the display method
7. Nothing seems wrong here
8. Moving to the inorder method - nothing wrong here either also output is correct
9. Moving to the preorder method - all good 
10. Checked the rest of the methods for printing out - all good 
11. There is no destructor defined - no need for one
*/