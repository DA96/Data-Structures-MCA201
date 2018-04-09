// Program to eliminate every M th person around the circle and finding out the last one remaining
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
    void display();
    void eliminateM_findLast(int);
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


void CircularLinkedList :: display()
{
    node *t = head;

    while(t->next != head)
    {
        cout<<t->data<<" -> ";
        t = t->next;
    }
    cout<<t->data;
}


void CircularLinkedList :: eliminateM_findLast(int m)
{
    node *temp = head;

    while(temp->next != temp)
    {
        int count = 1;

        while(count != m-1)  // Visiting m-1 th node
        {
            temp = temp->next;
            count++;
        }

        //Deleting m th node
        node *t = temp->next;  // t is m th node
        temp->next = t->next;
        temp = temp->next;
        cout<<endl<<" person "<<t->data<<" eliminated.\n";
        delete(t);
    }

    cout<<"\nThe last one remaining is : "<<temp->data;
}

int main()
{
    int n,m;
    CircularLinkedList cll;

    cout<<"\nEnter no. of people N : ";
    cin>>n;

    for(int i=1; i<=n; i++)
        cll.insert(i);

   // cout<<endl;
   // cll.display();

    cout<<"\n\nEliminate very M th person, enter M : ";
    cin>>m;

    cll.eliminateM_findLast(m);

    return 0;
}
