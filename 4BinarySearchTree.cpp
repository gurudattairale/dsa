/*
Beginning with an empty binary search tree, construct binary search tree by inserting the values in the order given.
After constructing a binary tree –
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/


//code==

#include<iostream>
#include<math.h>
using namespace std;

// Structure defining each node of the binary search tree
struct Bstnode
{
 int data;
 Bstnode *left = NULL;
 Bstnode *right = NULL;
};

// Class for Binary Tree operations
class Btree
{
  int n; // Number of elements to be inserted
  int x; // Variable to store user input
  
public:
  Bstnode * root; // Pointer to the root of the binary search tree
  
  // Constructor to initialize root to NULL
 Btree()
 {
  root = NULL;
 }
 
 // Function to create a new node with given data
 Bstnode *GetNewNode(int in_data)
 {
  Bstnode * ptr = new Bstnode();
  ptr->data = in_data;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
 }
 
 // Function to insert a node with given data into the binary search tree
 Bstnode *insert( Bstnode *temp , int in_data)
 {
  if( temp == NULL )
  {
   temp = GetNewNode(in_data);
  }
  else if( temp->data > in_data)
  {
   temp->left = insert(temp->left , in_data);
  }
  else
  {
   temp->right = insert( temp->right , in_data);
  }
  return temp;
 }
 
 // Function to take user input for elements and insert them into the tree
 void input()
 {
  cout<<"ENTER NUMBER OF ELEMENTS IN THE BST : ";
  cin>>n;
  for(int i = 0 ; i < n ; i++)
  {
   cout<<"NUMBER = ";
   cin>>x;
   root = insert(root , x);
  }
 }
 
 // Function to find the minimum value in the binary search tree
 void minvalue(Bstnode *temp)
 {
  while(temp->left != NULL)
  {
   temp = temp->left;
  }
  cout<<"MINIMUM VALUE = "<<temp->data<<endl;
 }
 
 // Function to find the maximum value in the binary search tree
 void maxvalue(Bstnode *temp)
 {
  while(temp->right != NULL)
  {
   temp = temp->right;
  }
  cout<<"MAX VALUE = "<<temp->data<<endl;
 }
   
 // Function to create a mirror image of the binary search tree
 void mirror(Bstnode *temp)
 {
  if(temp == NULL)
  {
   return;
  }
  else
  { 
   Bstnode *ptr;
   mirror(temp->left);
   mirror(temp->right);
   ptr = temp->left;
   temp->left = temp->right;
   temp->right = ptr; 
  }
 }
 
 // Function to display the tree in inorder, postorder, and preorder traversals
 void display()
 {
  cout<<endl<<"--- INORDER TRAVERSAL ---"<<endl;
  inorder(root);
  cout<<endl;
  cout<<endl<<"--- POSTORDER TRAVERSAL ---"<<endl;
  postorder(root);
  cout<<endl;
  cout<<endl<<"--- PREORDER TRAVERSAL ---"<<endl;
  preorder(root);
  cout<<endl;
 }
 
 // Function for inorder traversal
 void inorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   inorder(temp->left);
   cout<<temp->data<<"  ";
   inorder(temp->right);
  }
 } 
 
 // Function for postorder traversal
 void postorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->data<<" ";
  }
 }
 
 // Function for preorder traversal
 void preorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   cout<<temp->data<<" ";
   preorder(temp->left);
   preorder(temp->right);
  }
 } 
};




// Main function
int main()
{
 Btree obj; // Creating object of class Btree
 obj.input(); // Taking user input for constructing the tree
 obj.display(); // Displaying the tree in inorder, postorder, and preorder traversals
 obj.minvalue(obj.root); // Finding the minimum value in the tree
 obj.maxvalue(obj.root); // Finding the maximum value in the tree
 obj.mirror(obj.root); // Creating a mirror image of the tree
 cout<<"Mirror of inorder = ";
 obj.inorder(obj.root); // Displaying the mirror image of the tree
 return 0;
} 