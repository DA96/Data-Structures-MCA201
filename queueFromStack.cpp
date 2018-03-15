
#include <iostream>
#include<cstdlib>
#include<stack>

using namespace std;

class queue_fromStack
{
    public:

    stack<int> s1;
    stack<int> s2;

    void enqueue(int);
    int dequeue();
    int q_size();
    int q_front();
    void display();
    bool q_isEmpty();

};


bool queue_fromStack :: q_isEmpty()
{
    if(s1.empty())
        return true;
    else
        return false;
}


void queue_fromStack :: enqueue(int ele)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(ele);

    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}


int queue_fromStack :: dequeue()
{
    int data = s1.top();
    s1.pop();
    return data;
}


int queue_fromStack :: q_size()
{
    return s1.size();
}

int queue_fromStack :: q_front()
{
    return s1.top();
}

void queue_fromStack :: display()
{
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
}


int main()
{
    cout<<"----Queue from Stack----\n";
    queue_fromStack q;

    int choice;
    char ch;

  do
  {
      cout<<"\n1.ENQUEUE  \n2.DEQUEUE  \n3.SIZE OF QUEUE  \n4.FRONT ELEMENT OF QUEUE  \n5.DISPLAY  \n6.EXIT \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    cout<<"\nEnter elemennt : ";
                    int ele;
                    cin>>ele;
                    q.enqueue(ele);
                    break;

          case 2 :
                    if(q.q_isEmpty())
                        cout<<"\nQueue is empty \n";
                    else
                        cout<<"\nElement dequeued : "<<q.dequeue()<<endl;
                    break;

          case 3 :
                    cout<<"\nCurrent size of queue is : "<<q.q_size()<<endl;
                    break;

          case 4 :
                    if(q.q_isEmpty())
                        cout<<"\nQueue is empty \n";
                    else
                        cout<<"\nFront element : "<<q.q_front()<<endl;
                    break;

          case 5 :
                    if(q.q_isEmpty())
                        cout<<"\nQueue is empty \n";
                    else
                    {
                        cout<<"\nDisplaying queue... \n";
                        q.display();
                    }
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

