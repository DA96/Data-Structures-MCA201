//Program to implement singly linked list using template.

#include<iostream>
#include<string>
template<class T> class SLinkedList;
using namespace std;

template <class T>
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
	  T elem;
	  SNode<T>* next;
	friend class SLinkedList<T>; // provides SLinkedList access to SNode
};

template <class T>
class SLinkedList {
	/*
	objective: Create a Single LInked List class
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/
	public:
	SLinkedList();							// empty list constructor
	~SLinkedList();							// destructor
	bool empty() const; 					// is list empty?
	const T& front() const; 			// get front element
	void addFront(const T& e); 		// add to front of list
	void addBack(const T& e); 			// add to back of list
	void removeFront();			 			// remove from front
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL

	private:
	SNode<T>* head; 							// pointer to the head of list
};

template <class T>
SLinkedList<T> :: SLinkedList()
{
    head = NULL;
}

template <class T>
SLinkedList<T> :: ~SLinkedList()
{
    delete(head);
}

template <class T>
bool SLinkedList<T> :: empty() const
{
    if(head == NULL)
        return true;
    else
        return false;
}

template <class T>
const T& SLinkedList<T> :: front() const
{
    return head->elem;
}

template <class T>
void SLinkedList<T> :: addFront(const T& e)
{
    SNode<T>* newnode = new SNode<T>;
    newnode->elem = e;
    newnode->next = head;
    head = newnode;
}

template <class T>
void SLinkedList<T> :: addBack(const T& e)
{
    SNode<T>* newnode = new SNode<T>;
    newnode->elem = e;

    if(head == NULL)
        head = newnode;

    else
    {
        SNode<T>* t = head;
        while(t->next != NULL)
            t = t->next;

        t->next = newnode;
    }
}

template <class T>
void SLinkedList<T> :: removeFront()
{
    SNode<T>* t = head->next;
    delete(head);
    head = t;
}

template <class T>
void SLinkedList<T> :: removeEnd()
{
    SNode<T>* t = head;
    while(t->next->next != NULL)
        t = t->next;

    delete(t->next);
    t->next = NULL;
}

template <class T>
void SLinkedList<T> :: print()
{
    SNode<T>*t = head;
    while(t->next != NULL)
    {
        cout<<t->elem<<" -> ";
        t = t->next;
    }
    cout<<t->elem;
}


int main()
{
  SLinkedList<string> sll;
  cout<<"  SINGLY LINKED LIST \n";
  int choice;
  char ch;
  string data;

  do
  {
      cout<<"\n1.ADD NODE IN FRONT \n2.ADD NODE AT BACK  \n3.REMOVE NODE FROM FRONT \n4.REMOVE NODE FROM END \n5.FRONT ELEMENT  \n6.PRINT LIST \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    cout<<"\nEnter data : ";
                    cin>>data;
                    sll.addFront(data);
                    break;

          case 2 :
                    cout<<"\nEnter data : ";
                    cin>>data;
                    sll.addBack(data);
                    break;

          case 3 :
                    if(sll.empty())
                        cout<<"\nList is Empty ";
                    else
                        sll.removeFront();
                    break;

          case 4 :
                    if(sll.empty())
                        cout<<"\nList is Empty ";
                    else
                        sll.removeEnd();
                    break;

          case 5 :
                    if(sll.empty())
                        cout<<"\nList is Empty ";
                    else
                        cout<<"\nFront element : "<<sll.front();
                    break;

          case 6 :
                    if(sll.empty())
                        cout<<"\nList is Empty ";
                    else
                        {   cout<<endl;
                            sll.print();
                        }
                    break;

          default : cout<<"\nInvalid choice \n";
      }

      cout<<"\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

    return 0;
}
