//Program to implement stack using singly linked list.

#include<iostream>
#include<string>
using namespace std;

class SNode {
	/*
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure
	approach: Class defines data item is names element with datatype string
			and link is named next pf snode type
	*/
	private:
	  string elem;
	  SNode* next;
	friend class Stack; // provides Stack access to SNode
};


class Stack {
	/*
	objective: Create a Stack class
	input parameters: none
	output value: none
    approach: Class definition
	*/
	public:
	Stack();							// empty stack constructor
	~Stack();							// destructor
	bool empty() const; 				// is stack empty?
	const string& topEle() const;		// get top element
	void push(const string& e); 		// push element to stack
    void pop();					    	// pop element from stack
	void print(); 			    		// display stack
    int size();                         // returns size of stack

	private:
	SNode* head; 						// pointer to the head/top of stack
};


Stack :: Stack()
{
    head = NULL;
}

Stack :: ~Stack()
{
    delete(head);
}

bool Stack :: empty() const
{
    if(head == NULL)
        return true;
    else
        return false;
}

const string& Stack :: topEle() const
{
    return head->elem;
}


void Stack :: push(const string& e)
{
    SNode* newnode = new SNode;
    newnode->elem = e;
    newnode->next = head;
    head = newnode;
}


void Stack :: pop()
{
    SNode* t = head->next;
    cout<<"\nElement popped : "<<head->elem<<endl;
    delete(head);
    head = t;
}

int Stack :: size()
{
    int ctr = 0;
    if(head == NULL)
        return ctr;

    else
    {
        SNode *t = head;
        ctr = 1;
        while(t->next != NULL)
        {
            ctr++;
            t = t->next;
        }
    }
     return ctr;
}

void Stack :: print()
{
    SNode*t = head;
    while(t != NULL)
    {
        cout<<t->elem<<endl;
        t = t->next;
    }
}


int main()
{
  Stack s;
  cout<<"  STACK USING SINGLY LINKED LIST \n";
  int choice;
  char ch;
  string data;

  do
  {
      cout<<"\n1.PUSH \n2.POP  \n3.TOP ELEMENT \n4.SIZE OF STACK \n5.DISPLAY STACK \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    cout<<"\nEnter data : ";
                    cin>>data;
                    s.push(data);
                    break;

          case 2 :
                    if(s.empty())
                        cout<<"\nStack is Empty ";
                    else
                        s.pop();
                    break;

          case 3 :
                    if(s.empty())
                        cout<<"\nStack is Empty ";
                    else
                        cout<<"\nTop element : "<<s.topEle();
                    break;

          case 4 :
                    cout<<"\nStack Size : "<<s.size();
                    break;

          case 5 :
                    if(s.empty())
                        cout<<"\nStack is Empty ";
                    else
                        {   cout<<endl;
                            s.print();
                        }
                    break;

          default : cout<<"\nInvalid choice \n";
      }

      cout<<"\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

    return 0;
}

