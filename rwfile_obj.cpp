// WAP to write and read object using read and write function.

#include<iostream>
#include<fstream>
using namespace std;

class Student
{
    char name[50];
    int rollno;
    float marks;

public:

    void getdata();
    void display();
};

void Student::getdata()
{
    char ch;
    cin.get(ch);
    cout<<"Enter name : ";
    cin.getline(name,50);
    cout<<"Enter roll no. : ";
    cin>>rollno;
    cout<<"Enter marks : ";
    cin>>marks;
    cout<<endl;
}

void Student::display()
{
    cout<<"Name: "<<name<<"\t"<<"Roll No.: "<<rollno<<"\t"<<"Marks: "<<marks<<"\n";
}

int main()
{
    int num;
    cout<<"\nEnter no. of students : ";
    cin>>num;
    Student *s;
    s = new Student[num];

    fstream fileios;
    fileios.open("fileObj.txt" ,ios::in | ios::out);

    cout<<"\nEnter student details \n";
    for(int i=0; i<num; i++)
    {
        s[i].getdata();
        fileios.write((char*)& s[i],sizeof(s[i]));
    }

    fileios.seekg(0);
    cout<<"\nContents of file fileObj.txt are shown below. \n\n";
    for(int i=0; i<num; i++)
    {
        fileios.read((char*)& s[i],sizeof(s[i]));
        s[i].display();
    }

    fileios.close();
    return 0;
}
