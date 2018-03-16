// Reverse number using STL stack

#include<iostream>
using namespace std;

#include<stdlib.h>
#include<stack>
stack<int>s;


void pushDigits(int num)
{
    /*

    Objective : To push digits of a number in stack
    Input Parameters :
                        num : number whose digits are to be pushed
    return value : None

    */

    // Approach : using STL stack to push digits

     while(num!=0)
    {
        int digit = num%10;
        s.push(digit);
        num = num/10;
    }
}

int reverseNum()
{
    /*

    Objective : To reverse number
    Input Parameters : None
    return value : reversed number

    */

    // Approach : using STL stack

    int i = 1;
    int revNum = 0;

    while(!s.empty())
    {
        revNum = revNum + (s.top() * i);
        s.pop();
        i *= 10;
    }

    return revNum;

}


int main(){

    system("cls");
    int num;
    cout<<"Enter number to be reversed : ";
    cin>>num;
    pushDigits(num);
    cout<<"Reversed number is : "<<reverseNum();
    cin.get();
    return 0;

}
