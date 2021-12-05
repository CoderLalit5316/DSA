#include<iostream>
using namespace std;

int main()
{
    int n,wt[10],capacity=55;
    float profit[10],ratio[10];
    
    cout<<"Enter Number : ";
    cin>>n;

    cout<<"\nEnter Weight  And profit : ";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>profit[i];

        ratio[i]=profit[i]/wt[i];
    }

     cout<<"Ratio : ";
    for(int i=0;i<n;i++)
    {
        cout<<ratio[i]<<" ,";
    }

}