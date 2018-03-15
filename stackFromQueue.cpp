
#include <iostream>
#include <cstdlib>
#include<queue>

using namespace std;

class stack_fromQueue
{
    public:

    queue<int> q1;
    queue<int> q2;

    void st_push(int);
    int st_pop();
    int st_top();
    int st_size();
    void display();
    bool st_isEmpty();

};


bool stack_fromQueue :: st_isEmpty()
{
    if(q1.empty())
        return true;
    else
        return false;
}


void stack_fromQueue :: st_push(int ele)
{
    q2.push(ele);

    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1,q2);
}


int stack_fromQueue :: st_pop()
{
    int data = q1.front();
    q1.pop();
    return data;
}


int stack_fromQueue :: st_top()
{
    return q1.front();
}


int stack_fromQueue :: st_size()
{
    return q1.size();
}


void stack_fromQueue :: display()
{
    while(!q1.empty())
    {
        cout<<q1.front()<<endl;
        q1.pop();
    }
}



int main()
{
    cout<<"----Stack from Queue----\n";
    stack_fromQueue st;

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
                    cout<<"\nEnter elemennt : ";
                    int ele;
                    cin>>ele;
                    st.st_push(ele);
                    break;

          case 2 :
                    if(st.st_isEmpty())
                        cout<<"\nStack is empty \n";
                    else
                        cout<<"\nElement popped : "<<st.st_pop()<<endl;
                    break;

          case 3 :
                    cout<<"\nCurrent size of stack is : "<<st.st_size()<<endl;
                    break;

          case 4 :
                    if(st.st_isEmpty())
                        cout<<"\nStack is empty \n";
                    else
                        cout<<"\nTop element : "<<st.st_top()<<endl;
                    break;

          case 5 :
                    if(st.st_isEmpty())
                        cout<<"\nStack is empty \n";
                    else
                    {
                        cout<<"\nDisplaying stack... \n";
                        st.display();
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
