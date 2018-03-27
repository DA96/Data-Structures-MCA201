//Program to implement queue using singly linked list.

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
	friend class Queue; // provides Queue access to SNode
};


class Queue {
	/*
	objective: Create a Queue class
	input parameters: none
	output value: none
    approach: Class definition
	*/
	public:
	Queue();							// empty Queue constructor
	~Queue();							// destructor
	bool empty() const; 				// is Queue empty?
	const string& front() const;		// get top element
	void enqueue(const string& e); 		// push element to Queue
    void dequeue();					    	// pop element from Queue
	void print(); 			    		// display Queue
    int size();                         // returns size of Queue

	private:
	SNode* head; 						// pointer to the head/front of Queue
};


Queue :: Queue()
{
    head = NULL;
}

Queue :: ~Queue()
{
    delete(head);
}

bool Queue :: empty() const
{
    if(head == NULL)
        return true;
    else
        return false;
}

const string& Queue :: front() const
{
    return head->elem;
}


void Queue :: enqueue(const string& e)
{
    SNode* newnode = new SNode;
    newnode->elem = e;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;

    else
    {
        SNode* t = head;
        while(t->next != NULL)
            t = t->next;

        t->next = newnode;
    }
}


void Queue :: dequeue()
{
    SNode* t = head;
    cout<<"\nElement dequeued : "<<head->elem<<endl;
    head = head->next;
    delete(t);
}

int Queue :: size()
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

void Queue :: print()
{
    SNode*t = head;
    while(t->next != NULL)
    {
        cout<<t->elem<<" -> ";
        t = t->next;
    }
    cout<<t->elem;
}


int main()
{
  Queue q;
  cout<<"  QUEUE USING SINGLY LINKED LIST \n";
  int choice;
  char ch;
  string data;

  do
  {
      cout<<"\n1.ENQUEUE \n2.DEQUEUE  \n3.FRONT ELEMENT \n4.SIZE OF QUEUE \n5.DISPLAY QUEUE \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    cout<<"\nEnter data : ";
                    cin>>data;
                    q.enqueue(data);
                    break;

          case 2 :
                    if(q.empty())
                        cout<<"\nQueue is Empty ";
                    else
                        q.dequeue();
                    break;

          case 3 :
                    if(q.empty())
                        cout<<"\nQueue is Empty ";
                    else
                        cout<<"\nTop element : "<<q.front();
                    break;

          case 4 :
                    cout<<"\nQueue Size : "<<q.size();
                    break;

          case 5 :
                    if(q.empty())
                        cout<<"\nQueue is Empty ";
                    else
                        {   cout<<endl;
                            q.print();
                        }
                    break;

          default : cout<<"\nInvalid choice \n";
      }

      cout<<"\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

    return 0;
}

