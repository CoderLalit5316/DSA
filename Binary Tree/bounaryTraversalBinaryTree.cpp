
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

   public : 
int data;
Node *left;
Node *right;

Node(int x)
{
    data=x;
    left=NULL;
    right=NULL;
}
};

void BoundaryLeft(Node *root,vector<int> &v)
{
  if(root==NULL)
  {
      return;
  }

  if(root->left)
  {
      v.push_back(root->data);
      BoundaryLeft(root->left,v);
  }
  else if(root->right)
  {
      v.push_back(root->data);
      BoundaryLeft(root->right,v);
  }
}

void BoundaryLeaf(Node *root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
BoundaryLeaf(root->left,v);
if(root->left==NULL && root->right==NULL)
{
    v.push_back(root->data);
}

BoundaryLeaf(root->right,v);


}

void BoundaryRight(Node *root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }

    if(root->right)
    {
        BoundaryRight(root->right,v);
        v.push_back(root->data);
    }
    else if(root->left)
    {
        BoundaryRight(root->left,v);
        v.push_back(root->data);
    }
}

int main()
{
    
 Node *root=new Node(11);
 Node *n1=new Node(12);
 Node *n2=new Node(13);
 Node *n3=new Node(14);
 Node *n4=new Node(15);
 Node *n5=new Node(16);
 Node *n6=new Node(17);
 Node *n7=new Node(19);
 Node *n8=new Node(20);

 root->left=n1;
 root->right=n2;
 n1->left=n3;
 n1->right=n4;
 n2->left=n5;
 n2->right=n6;
 n6->right=n7;
 n7->left=n8;

 /*
          11
         /    \
       12      13
      /  \    /  \
     14  15  16   17
                    \
                    19
                    /
                   20
 */

vector<int>v;
v.push_back(root->data);
BoundaryLeft(root->left,v);
BoundaryLeaf(root,v);
BoundaryRight(root->right,v);

for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}


}

