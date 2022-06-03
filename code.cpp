#include<iostream>
#include<stdio.h>
using namespace std;
float calculate(int n,int credits[],int marks[]);
void marksheet(int n,float cgpa,int marks[],int total);

float calculate(int n,int credit[],int marks[])
{
    int gp[n];
    float cgpa,total=0,total_credits=0;
    for(int i=0;i<n;i++)
    {
        if(marks[i]>=90)
            gp[i]=10;
        else if(marks[i]>=80)
            gp[i]=9;
        else if(marks[i]>=70)
            gp[i]=8;
        else if(marks[i]>=60)
            gp[i]=7;
        else
            gp[i]=6;                
    }
    
    for(int i=0;i<n;i++)
    {
        total = total + (credit[i]*gp[i]);
        total_credits = total_credits + credit[i];
    } 

    cgpa = total/total_credits;

    cout<<"\nCGPA : "<<cgpa;
    cout<<"\n---------------------------------------------------------------------------";
    cout<<"\n---------------------------------------------------------------------------";
    return cgpa;
}


void marksheet(int n,float cgpa,int marks[])
{
    
    int rollno;
    char name[20];
    int total_marks=0;
    for(int i=0;i<n;i++)
    {
        total_marks = total_marks + marks[i];
    }
    cout<<"\nENTER NAME : ";
    cin>>name;
    cout<<"\nENTER ROLLNO : ";
    cin>>rollno;
    
    cout<<"\n---------------------------------------------------------------------------";
    cout<<"\n---------------------------------------------------------------------------";
    cout<<"\n|"<<" NAME : "<<name<<"               "<<"ROLLNO : "<<rollno<<"                                   |";
    cout<<"\n----------------------------------------------------------------------------";
    cout<<"\n|                                       |                                  |";
    cout<<"\n|               SUBJECT                 |              MARKS               |";
    cout<<"\n|                                       |                                  |";
    cout<<"\n----------------------------------------------------------------------------"; 
    for(int i=0;i<n;i++)
    {
        cout<<"\n|               SUBJECT "<<i+1<<"               |              "<<marks[i]<<"                  |";
    }
    cout<<"\n----------------------------------------------------------------------------"; 
    cout<<"\n|               TOTAL                   |              "<<total_marks<<"                 |";
    cout<<"\n----------------------------------------------------------------------------";    
}

int main()
{ 
    int n,credit[15],marks[15],temp=0,total;
    float cgpa;
    cout<<"\n---------------------------------------------------------------------------";
    cout<<"\n\t\t\tGPA / CGPA CALCULATOR ";
    cout<<"\n---------------------------------------------------------------------------";
    cout<<"\nENTER THE NUMBER OF SUBJECTS : ";
    cin>>n;
    cout<<"\nENTER THE MARKS FOR EACH SUBJECT  \n ";
    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------------------------------------";
        cout<<"\n\t\t\t\tSUBJECT "<<i+1;
        cout<<"\nMARKS : ";
        cin>>marks[i];
        cout<<"CREDIT : ";
        cin>>credit[i];
        if(marks[i]<=49)
            temp=1;
    }
    if(temp==1)
    {
        cout<<"\nSorry you are not elgible to calculate cgpa"; 
        cout<<"\nReason: You may have scored marks <=49 in any subject/subjects ";
    }
    else
    {
        cgpa,total = calculate(n,credit,marks);   
    }
    char ch;
    cout<<"\nDO WANT THE MARKSHEET (y/n) : ";
    cin>>ch;
    if(ch=='y')
    {
        marksheet(n,cgpa,marks);
    }


    return 0;
}
