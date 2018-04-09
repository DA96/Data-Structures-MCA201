// Program to print all root leaf paths of a binary tree
// SUBMITTED BY - DIVYA AGARWAL ; ROLL NO. 12


#include<iostream>
using namespace std;

 struct node
    {
        int data;
        node *right, *left;
    };

node* insertNode(int);
void printPaths(node*,int[],int);
void printArray(int[],int);


node* insertNode(int ele)
{
    node* newNode = new node;
    newNode->data = ele;
    newNode->left = NULL;
    newNode->right = NULL;

    return(newNode);
}


void printArray(int arr[], int len)
{
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}


void printPaths(node* n, int path[], int pathLen)
{
  if (n==NULL)
    return;

  /* append this node to the path array */
  path[pathLen] = n->data;
  pathLen++;

  /* it's a leaf, so print the path that led to here  */
  if (n->left==NULL && n->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    /* otherwise try both subtrees */
    printPaths(n->left, path, pathLen);
    printPaths(n->right, path, pathLen);
  }
}


int main()
{
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  7
  */

  node *root = insertNode(10);
  root->left = insertNode(8);
  root->right = insertNode(2);
  root->left->left  = insertNode(3);
  root->left->right = insertNode(5);
  root->right->left = insertNode(7);

  int arrPath[100];
  printPaths(root,arrPath,0);

  return 0;
}


