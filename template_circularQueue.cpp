//Program to implement circular queue using template.

#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

template <class T>
class queue
	/*
	objective: Create a class to implement Queue(circular) using dynamically created array

	input parameters: none

	output value: none

	description:  Class definition

	approach: Class definition provides data member and member functions for the Queue class

	*/

{
	T *arr;			// array to store queue elements
	int capacity;		// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q

public:

	queue(int size = SIZE);			// constructor

	~queue();

	void dequeue();

	void enqueue(T);

	T peek();  				// returns front element

	int size();				// returns current size of Q

	void display();

	bool isEmpty();

	bool isFull();

};

template <class T>
queue<T> :: queue(int size)
{
    capacity = size ;
    arr = new T[capacity];
    count = 0;
    front = -1;
    rear = -1;
}

template <class T>
queue<T> :: ~queue()
{
    delete(arr);
}


template <class T>
bool queue<T> :: isEmpty()
{
    if(front == -1 && rear == -1 )
        return true;
    else
        return false;
}


template <class T>
bool queue<T> :: isFull()
{
    if( (front == 0 && rear == capacity-1) || rear == front-1 )
        return true;
    else
        return false;
}


template <class T>
void queue<T> :: enqueue(T data)
{
    if(isFull())
        cout<<"Queue is full \n";

    else
    {
        if(isEmpty())   // inserting first element
        {
            front = 0;
            rear = 0;
        }

        else if(rear == capacity-1)   // when rear is at end and queue is not full
            rear = 0;

        else
            rear++;

        count++;
        arr[rear] = data;
    }

}


template <class T>
void queue<T> :: dequeue()
{
    if(isEmpty())
        cout<<"Queue is empty \n";

    else
    {
        T ele = arr[front];

        if(front == capacity-1)
            front = 0;

        else if(front == rear)   // only 1 element is left
        {
            front = -1;
            rear = -1;
        }

        else
            front++;

        cout<<"Element deleted is : "<<ele<<endl ;
        count--;
    }
}


template <class T>
T queue<T> :: peek()
{
    return arr[front];
}


template <class T>
int queue<T> :: size()
{
    return count;
}


template <class T>
void queue<T> :: display()
{
    if(!isEmpty())
    {
        int i = front;;
        if(front > rear)
        {
            for(; i <= capacity-1; i++)
                cout<<arr[i]<<" ";

            for(i = 0; i <= rear; i++)
                cout<<arr[i]<<" ";
        }

        else
        {
            for(; i<= rear; i++)
                cout<<arr[i]<<" ";
        }
    }
    else
        cout<<"\nQueue is empty";
}


int main()
{

  cout<<"-----CIRCULAR QUEUE-----\n";
  int sz;
  cout<<"\nEnter size of circular queue : ";
  cin>>sz;

  queue<int> cq(sz);
  int choice;
  char ch;

  do
  {
      cout<<"\n1.ENQUEUE  \n2.DEQUEUE  \n3.SIZE OF QUEUE  \n4.PEEK  \n5.DISPLAY  \n6.EXIT \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    int ele;
                    cout<<"\nEnter data : ";
                    cin>>ele;
                    cq.enqueue(ele);
                    break;

          case 2 :
                    cq.dequeue();
                    break;

          case 3 :
                    cout<<"Current size of stack is : "<<cq.size()<<endl;
                    break;

          case 4 :
                    if(cq.isEmpty())
                        cout<<"\nQueue is empty ";
                    else
                        cout<<"Front element : "<<cq.peek()<<endl;
                    break;

          case 5 :
                    cout<<"\nDisplaying stack... \n";
                    cq.display();
                    break;

          case 6 :
                    exit(0);
                    break;

          default : cout<<"\nInvalid choice \n";
      }

      cout<<"\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

    return 0;
}
