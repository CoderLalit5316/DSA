#include<iostream>
using namespace std;

void swap(int a,int b)
{
  
    int temp=a;
    a=b;
    b=temp;

    cout<<a<<" "<<b<<endl;
}

void sqr(int x)
{
  int ans=x*x;
  cout<<ans<<endl;
}

int main()
{
  
//    swap(10,20);
//    swap(15,16);

sqr(5);
sqr(6);
}