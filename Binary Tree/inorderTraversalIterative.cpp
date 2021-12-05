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

// void iterativeInorder(Node *root,vector<int> &v)
// {
//   stack<Node*>s;
//   Node *temp=root;
//   while(true)
//   {
//       while(temp)
//       {
//           s.push(temp);
//           temp=temp->left;
//       }

//       if(s.size()==0)
//       {
//           break;
//       }

//       temp=s.top();
//       s.pop();
//       v.push_back(temp->data);
//       temp=temp->right;
   
    
//   }

void iterativeInorder(Node *root,vector<int> &v)
{
    stack<Node*>s;
    Node *temp=root;
    while(true)
    {
      while(temp)
      {
          s.push(temp);
          temp=temp->left;
      }

      if(s.size()==0)
      {
          break;
      }

      temp=s.top();
      s.pop();
      v.push_back(temp->data);

      temp=temp->right;
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

 root->left=n1;
 root->right=n2;
 n1->left=n3;
 n1->right=n4;
 n2->left=n5;
 n2->right=n6;


//  inorderTraverse(root);
//  cout<<endl;
//  preorderTraverse(root);

vector<int>v;
iterativeInorder(root,v);

for(int ele : v)
{
    cout<<ele<<" ";
}


}