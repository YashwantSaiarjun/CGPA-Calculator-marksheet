#include<iostream>
#include<stdio.h>
using namespace std;
void calculate(int n,int credits[],int marks[]);

void calculate(int n,int credits[],int marks[])
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
        total = total + (credits[i]*gp[i]);
        total_credits = total_credits + credits[i];
    }

    cgpa = total/total_credits;

    cout<<"\nCGPA : "<<cgpa;
}

int main()
{ 
    int n,credit[15],marks[15],temp=0;
    cout<<"\nENTER THE NUMBER OF SUBJECTS : ";
    cin>>n;
    cout<<"\nENTER THE MARKS FOR EAH SUBJECT  :\n ";
    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------------------------------------";
        cout<<"\n\t\t\t\tSUBJECT "<<i+1;
        cout<<"\nMARKS : ";
        cin>>marks[i];
        cout<<"\nCREDIT : ";
        cin>>credit[i];
        if(marks[i]<=49)
            temp=1;
    }

    if(temp==1)
    {
        cout<<"\nSorry you are not elgible to calculate cgpa"; 
    }
    else
    {
        calculate(n,credit,marks);   
    }
    return 0;
}
