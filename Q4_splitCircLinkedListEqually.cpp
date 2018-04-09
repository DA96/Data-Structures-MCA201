// Program to split a circular linked list into two equal parts circular linked lists. (If odd no. of nodes, first list with one extra)
// SUBMITTED BY - DIVYA AGARWAL ; ROLL NO. 12


#include<iostream>
using namespace std;

class CircularLinkedList
{
    struct node
    {
        int data;
        node *next;

    }*head=NULL;

    public:

    void insert(int);
    void display(node*);
    void callDisplay();
    void split();
};


void CircularLinkedList :: insert(int ele)
{
    node *newNode = new node;
    newNode -> data = ele;

    if(head==NULL)
        head = newNode;

    else
    {
        node *t = head;
        while(t->next != head)
            t = t->next;

        t->next = newNode;
    }

    newNode -> next = head;
}


void CircularLinkedList :: display(node *headPtr)
{
    node *t = headPtr;

    while(t->next != headPtr)
    {
        cout<<t->data<<" -> ";
        t = t->next;
    }
    cout<<t->data;
}


void CircularLinkedList :: callDisplay()
{
    display(head);
}


void CircularLinkedList :: split()
{
    node *sp = head;  //slow pointer
    node *fp = head;  //fast pointer

    //Base case for odd no. of nodes
    if(sp->next == head)  // 1 node in list
    {
        cout<<"\nList cannot be split. Only one node existing \n";
        display(head);
        return;
    }

    node *head2;

    //Base case for even no. of nodes
    if(sp->next->next == head)  // 2 nodes in list
    {
        head2 = sp->next;
        sp->next = head;
        head2->next = head2;

        cout<<"\nCircular Linked list 1 : ";
        display(head);
        cout<<"\nCircular Linked list 2 : ";
        display(head2);

        return;
    }

    //Setting sp and fp
    while(1)
    {
        sp = sp->next;
        fp = fp->next->next;

        if(fp->next == head || fp->next->next == head)  //fp->next == head, for odd no. of nodes and fp->next->next == head, for even no. of nodes
            break;
    }

    //Splitting
    head2 = sp->next;  //Setting head pointer of second list
    sp->next = head;  //List 1 is split

    if(fp->next == head)  //in odd case
        fp->next = head2;
    else if(fp->next->next == head)  //in even case
        fp->next->next = head2;

    cout<<"\nCircular Linked list 1 : ";
    display(head);
    cout<<"\nCircular Linked list 2 : ";
    display(head2);
}



int main()
{
    cout<<"\tCIRCULAR LINKED LIST \n";
    int ch;
    char cont;
    CircularLinkedList cll;

    do
    {
        cout<<"1.Insert \n2.Split \n3.Display \n";
        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
                int ele;
                cout<<"\nEnter data : ";
                cin>>ele;
                cll.insert(ele);
                cll.callDisplay();

                break;

        case 2:
                cll.split();
                break;

        case 3:
                cll.callDisplay();
                break;

        default: cout<<"\nInvalid choice! ";
        }

        cout<<"\nWant to continue? Press y for yes ";
        cin>>cont;

    }while(cont=='y' || cont=='Y');

    return 0;
}
