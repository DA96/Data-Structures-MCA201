// Program to check if each successive pair in stack is consecutive or not
// SUBMITTED BY - DIVYA AGARWAL ; ROLL NO. 12


#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

bool consecutivePairs(stack<int> s2)  // copying stack s1 into stack s2
{
    if(s2.size()%2 != 0)  //odd no. of elements in stack
        s2.pop();

    int ele1, ele2;
    while(!s2.empty())
    {
        ele1 = s2.top();
        s2.pop();
        ele2 = s2.top();
        s2.pop();

        if(abs(ele1 - ele2) != 1)
            return false;
    }

    return true;
}

int main()
{
  stack<int> s1;
  int choice;
  char ch;

  do
  {
      cout<<"\n1.PUSH  \n2.POP  \n3.SIZE OF STACK  \n4.TOP ELEMENT OF STACK  \n5.CONSECUTIVE PAIRS OR NOT \n";
      cout<<"\nENTER YOUR CHOICE : ";
      cin>>choice;

      switch(choice)
      {
          case 1 :
                    cout<<"\nEnter data : ";
                    int ele;
                    cin>>ele;
                    s1.push(ele);
                    break;

          case 2 :
                    if(s1.empty())
                        cout<<"\nStack is empty";
                    else
                    {
                        cout<<"Element popped : "<<s1.top()<<endl;
                        s1.pop();
                    }

                    break;

          case 3 :
                    cout<<"Current size of stack is : "<<s1.size()<<endl;
                    break;

          case 4 :
                    if(s1.empty())
                        cout<<"\nStack is empty";
                    else
                        cout<<"Top element : "<<s1.top()<<endl;

                    break;

          case 5 :
                    if(consecutivePairs(s1))
                        cout<<"\nEach successive pair in stack is consecutive";
                    else
                        cout<<"\nEach successive pair in stack is NOT consecutive";

                    break;

         default : cout<<"\nInvalid choice \n";
      }

      cout<<"\n\nWant to continue? Press y for yes ";
      cin>>ch;

  }while(ch=='y'||ch=='Y');

  return 0;
}
