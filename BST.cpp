//BST

#include<iostream>
using namespace std;

class BSTree
{
 class BSTNode
 {
  public:
  int key;
  BSTNode *left, *right;
  BSTNode()
  {
   left=NULL;
   right=NULL;
  }
 };

 public:

 BSTNode *root;
 BSTree()
 {
  root=NULL;
 }

 void insert(int);
 void findAndDelMerg(int);
 void findAndDelCopy(int);
 void search(int);
 void dftraverse();

 protected:

 void delMerg(BSTNode* &node);
 void delCopy(BSTNode* &node);
 void post(BSTNode *q);
 void pre(BSTNode *q);
 void in(BSTNode *q);
};


 void BSTree::insert(int el)
 {
  BSTNode *p=root, *prev=NULL;
  BSTNode *temp=new BSTNode();
  temp->key=el;
  temp->right=NULL;
  temp->left=NULL;

  while(p!=NULL)     // finding place to insert new node
  {
   prev=p;

   if(el > p->key)
    p=p->right;

   else if(el < p->key)
    p=p->left;

   else
   {
    cout<<"\n"<<el<<" is already inserted. Cannot insert duplicate values \n";
    return;
   }
  }

  if(root==NULL)   // tree is empty
   root=temp;
  else if(el > prev->key)
   prev->right=temp;
  else
   prev->left=temp;
 }

 void BSTree::dftraverse()
 {
  int ch;
  cout<<"\n1.Preorder ";
  cout<<"\n2.Postorder ";
  cout<<"\n3.Inorder \n";
  cin>>ch;
  switch(ch)
  {
   case 1: pre(root);
	   break;

   case 2: post(root);
	   break;

   case 3: in(root);
	   break;

   default: cout<<"\nWrong choice ";
  }
 }

 void BSTree::pre(BSTNode *q)
 {
  if(q!=NULL)
  {
   cout<<q->key<<" ";
   pre(q->left);
   pre(q->right);
  }
 }

 void BSTree::post(BSTNode *q)
 {
  if(q!=NULL)
  {
   post(q->left);
   post(q->right);
   cout<<q->key<<" ";
  }
 }

 void BSTree::in(BSTNode *q)
 {
  if(q!=NULL)
  {
   in(q->left);
   cout<<q->key<<" ";
   in(q->right);
  }
 }

 void BSTree::search(int d)
 {
  BSTNode *t=root;
  int flag=0;
  while(t!=NULL)
   if(d==t->key)
   {
    flag=1;
    break;
   }
   else if(d < t->key)
    t=t->left;
   else
    t=t->right;

  if(flag==1)
   cout<<"\nELEMENT FOUND \n";
  else
   cout<<"\nELEMENT NOT FOUND \n";
 }


 void BSTree::findAndDelMerg(int el)
 {
  BSTNode *node=root, *prev=NULL;
  while(node!=NULL)
  {
   if(el==node->key)
    break;
   prev=node;
   if(el>node->key)
    node=node->right;
   else
    node=node->left;
  }
  if(node!=NULL && node->key==el)
     if(node==root)
      delMerg(root);
     else if(prev->left==node)
      delMerg(prev->left);
     else
      delMerg(prev->right);
  else if(root!=NULL)
   cout<<"\nkey "<<el<<" is not in the tree \n";
  else
   cout<<"\ntree is empty \n";
 }


 void BSTree::delMerg(BSTNode *&node)
 {
  BSTNode *tmp=node;
  if(node!=NULL)
  {
   if(node->right==NULL)
    node=node->left;
   else if(node->left==NULL)
    node=node->right;
   else
   {
    tmp=node->left;
    while(tmp->right!=NULL)
     tmp=tmp->right;

    tmp->right=node->right;
    tmp=node;
    node=node->left;
   }
   delete tmp;
  }
 }

 void BSTree::findAndDelCopy(int el)
 {
  BSTNode *node=root, *prev=NULL;
  while(node!=NULL)
  {
   if(el==node->key)
    break;
   prev=node;
   if(el>node->key)
    node=node->right;
   else
    node=node->left;
  }

  if(node!=NULL && node->key==el)
     if(node==root)
      delCopy(root);
     else if(prev->left==node)
      delCopy(prev->left);
     else
      delCopy(prev->right);
  else if(root!=NULL)
   cout<<"\nkey "<<el<<" is not in the tree \n";
  else
   cout<<"\ntree is empty \n";
 }

 void BSTree::delCopy(BSTNode* &node)
 {
  BSTNode *prev,*tmp=node;
  if(node->right==NULL)
   node=node->left;
  else if(node->left==NULL)
   node=node->right;
  else
  {
   tmp=node->left;
   prev=node;
   while(tmp->right!=NULL)
   {
    prev=tmp;
    tmp=tmp->right;
   }
   node->key=tmp->key;
   if(prev==node)
    prev->left=tmp->left;
   else
    prev->right=tmp->left;
  }
  delete tmp;
 }


int main()
{
 int ch;
 BSTree t;
 do
 {
  cout<<"\n\t\tBINARY SEARCH TREE \n";
  cout<<"\n\tEnter your choice \n";
  cout<<"\n\t1.Insert \n";
  cout<<"\t2.Delete by copying \n";
  cout<<"\t3.Delete by merging \n";
  cout<<"\t4.Search a number \n";
  cout<<"\t5.Depth first Traversal \n";
  cout<<"\t6.Exit \n";
  cin>>ch;
  switch(ch)
  {
   case 1: int ele;
	   cout<<"\nEnter element ";
	   cin>>ele;
	   t.insert(ele);
	   break;

   case 2: int itm;
	   cout<<"\nEnter item to be deleted by copying \n";
	   cin>>itm;
	   t.findAndDelCopy(itm);
	   break;

   case 3: int item;
	   cout<<"\nEnter item to be deleted by merging \n";
	   cin>>item;
	   t.findAndDelMerg(item);
	   break;

   case 4: int data;
	   cout<<"Enter data ";
	   cin>>data;
	   t.search(data);
	   break;

   case 5: t.dftraverse();
	   break;

   case 6: cout<<"Exiting... ";
	   break;

   default: cout<<"\nInvalid choice ";
  }
 }while(ch!=6);

 return 0;
}
