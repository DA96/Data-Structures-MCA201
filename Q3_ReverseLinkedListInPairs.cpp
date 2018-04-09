// Program to reverse linked list in pairs
// SUBMITTED BY - DIVYA AGARWAL ; ROLL NO. 12


#include<iostream>
using namespace std;

class SinglyLinkedList
{
    struct node
    {
        int data;
        node *next;

    }*head=NULL, *tail=NULL;

    public:

    void insert(int);
    void reversePairs(node*,node*,node*);
    void callRevPairs();
    void display();
};


void SinglyLinkedList :: insert(int ele)
{
    node *newNode = new node;
    newNode -> data = ele;
    newNode -> next = NULL;

    if(head==NULL)
        head = newNode;

    else
        tail -> next = newNode;

    tail = newNode;
}


void SinglyLinkedList :: display()
{
    node *t = head;

    while(t->next != NULL)
    {
        cout<<t->data<<" -> ";
        t = t->next;
    }
    cout<<t->data;
}


void SinglyLinkedList :: reversePairs(node* t1, node* t2, node *prev)
{
    if(t2==NULL || t1==NULL)  // At the end of list, t2 will be null for odd no. of nodes & t1 will be null for even no. of nodes
        return;

    else
    {
        t1->next = t2->next;  // Reversing (t1 & t2)'s positions
        t2->next = t1;

        //Now t1 & t2 are swapped

        if(prev == head)
            head = t2;
        else
            prev->next = t2;

        if(t1->next == NULL)  // For even no. of nodes, setting the tail pointer
         {
             tail = t1;
             return;
         }

        //Updating prev, t1 & t2
        prev = t1;
        t1 = (t1->next)->next;
        t2 = (t2->next)->next;
        reversePairs(t2,t1,prev);
    }
}


void SinglyLinkedList :: callRevPairs()
{
    node* t1 = head;
    node *t2 = t1->next;
    reversePairs(t1,t2,head);
}


int main()
{
    cout<<"\tSINGLE LINKED LIST \n";
    int ch;
    char cont;
    SinglyLinkedList sll;

    do
    {
        cout<<"1.Insert \n2.Reverse Pairs \n3.Display \n";
        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
                int ele;
                cout<<"\nEnter data : ";
                cin>>ele;
                sll.insert(ele);
                sll.display();

                break;

        case 2:
                sll.callRevPairs();
                sll.display();

                break;

        case 3:
                sll.display();

                break;

        default: cout<<"\nInvalid choice! ";
        }

        cout<<"\nWant to continue? Press y for yes ";
        cin>>cont;

    }while(cont=='y' || cont=='Y');

    return 0;
}
