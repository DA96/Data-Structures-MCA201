//WAP to write and read values using variables in/from file.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fileios;
    fileios.open("file.txt", ios::in | ios::out | ios::app );

    cout<<"\nEnter Roll No. and marks of students \n";

    char cont = 'y';   //continue flag
    int rollno;
    float marks;

    while(cont=='y' || cont=='Y')
    {
        cout<<"\nRoll No. : ";
        cin>>rollno;
        cout<<"\nMarks : ";
        cin>>marks;

        fileios<<"Roll No. : "<<rollno<<"\t"<<"Marks : "<<marks<<"\n";

        cout<<"\nWant to continue? (y/n) ";
        cin>>cont;
    }

    cout<<"\nDisplaying contents of file... \n\n";
    fileios.seekg(0);
    char line[70];
    while(!fileios.eof())   //till end of file is reached
    {
        fileios.getline(line,70);
        cout<<line<<"\n";
    }

    fileios.close();
    return 0;
}
