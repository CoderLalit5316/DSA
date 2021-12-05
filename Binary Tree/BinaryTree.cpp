#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
     Node(int x)
     {
       data=x;
       right=NULL;
       left=NULL;
     }
};


int main()
{
   Node *n1=new Node{10};
   Node *n2=new Node(11);
   Node *n3=new Node(12);

   n1->left=n2;
   n1->right=n3;

   cout<<n1->data<<endl;
   cout<<n2->data<<endl;
   cout<<n3->data<<endl;
}