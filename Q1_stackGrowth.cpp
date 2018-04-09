// Program to find whether stack on machine grows upward or downward
// SUBMITTED BY - DIVYA AGARWAL ; ROLL NO. 12

#include<iostream>
using namespace std;

void chkStackGrowth()
{
    int var1, var2;
   // cout<<"Address1 : "<<&var1<<endl<<"Address2 : "<<&var2;
    if(&var1 < &var2)
        cout<<"\nStack grows Upward";
    else
        cout<<"\nStack grows Downward";
}

int main()
{
    chkStackGrowth();
    return 0;
}
