//  WAP to demonstrate example of tellg() , tellp() , seekp() and seekg() function.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fileios;
    fileios.open("seekTell_sample.txt",ios::in | ios::out);

    fileios.seekg(2);
    cout<<"\nGet pointer position : "<<fileios.tellg();

    fileios.seekp(0,ios::end);
    cout<<"\nPut pointer position : "<<fileios.tellp();

    return 0;
}
