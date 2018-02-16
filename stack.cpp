//Program to implement stack using dynamic array(using template)

// SUBMITTED BY - DIVYA AGARWAL

#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;

template <class T>
class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
{
	T *arr;			         // for dynamic array
	int top;                         // top of stack
	int capacity;			 // checks size defined by user
public:
	stack(int size = MAXSIZE);	 // constructor to create array dynamically
	~stack();			 // destructor to delete dynamically created array
	void push(T);                    // pushes data in stack
	T pop();                         // pops data from stack
	T peek();                        // shows top element of stack
	int size();			 // Current size of stack
	bool isEmpty();                  // checks if stack is empty
	bool isFull();                   // checks if stack is full
	T input();                       // inputs data from user
	void display();                  // displays stack
};


template <class T>
stack<T> :: stack(int size)
{
    arr = new T[size];
    top = -1;
    capacity = size;
}

template <class T>
stack<T> :: ~stack()
{
    delete arr;
}

template <class T>
int stack<T> :: size()
{
    return top+1;
}

template <class T>
bool stack<T> :: isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

template <class T>
bool stack<T> :: isFull()
{
    if(top == capacity-1)
        return true;
    else
        return false;
}

template <class T>
T stack<T> :: peek()
{
    if(!isEmpty())
        return arr[top];
    else
    {
        char emp = '\0';
        cout<<"Stack is empty \n";
        return emp;
    }
}

template <class T>
void stack<T> :: push(T data)
{
    if(!isFull())
    {
        top++;
        arr[top] = data;
    }
    else
    {
        cout<<"Stack is already full \n";
    }
}

template <class T>
T stack<T> :: pop()
{
    if(!isEmpty())
    {
        T data = arr[top];
        top--;
        return data;
    }
    else
    {
        char emp = '\0';
        cout<<"Stack is empty \n";
        return emp;
    }
}

template <class T>
void stack<T> :: display()
{
     if(!isEmpty())
     {
         for(int i=top;i>=0;i--)
         {
             cout<<arr[i]<<endl;
         }
     }
     else
     {
         cout<<"Stack is empty \n";
     }
}

template <class T>
T stack<T> :: input()
{
    T data;
    cout<<"Enter data : ";
    cin>>data;
    return data;
}



int main()
{

  system("cls");

  cout<<"-----STACK-----\n";
  int sz;
  cout<<"\nEnter size of stack : ";
  cin>>sz;

  stack<int> st(sz);
  int choice;
  char ch;

  do
  {
      cout<<"\n1.PUSH  \n2.POP  \n3.SIZE OF STACK  \n4.TOP ELEMENT OF STACK  \n5.DISPLAY  \n6.EXIT \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    st.push(st.input());
                    break;

          case 2 :
                    cout<<"Element popped : "<<st.pop()<<endl;
                    break;

          case 3 :
                    cout<<"Current size of stack is : "<<st.size()<<endl;
                    break;

          case 4 :
                    cout<<"Top element : "<<st.peek()<<endl;
                    break;

          case 5 :
                    cout<<"\nDisplaying stack... \n";
                    st.display();
                    break;

          case 6 :
                    exit(0);
                    break;

          default : cout<<"\nInvalid choice \n";
      }

      cout<<"\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

  cin.get();

  return 0;
}

