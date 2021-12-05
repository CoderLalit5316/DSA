#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
 node *left;
 node *right;
 int data;

 node(int key)
 {
     data=key;
     left=NULL;
     right=NULL;
 }
};

void inorderTraversal(node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void LevelOrder(node *root)
{
 queue<node*>q;
 q.push(root);

 while (q.size()!=0)
 {
     node *temp=q.front();
     cout<<q.front()->data<<endl;
     q.pop();

     if(temp->left)
     {
         q.push(temp->left);
     }

     if(temp->right)
     {
         q.push(temp->right);
     }
  
 }
 
}

int main()
{
  
  node *root=new node(10);
  node *n1=new node(20);
  node *n2=new node(30);
  node *n3=new node(40);
  node *n4=new node(50);
  node *n5=new node(60);
  node *n6=new node(70);
 

  root->left=n1;
  root->right=n2;
  n1->left=n3;
  n1->right=n4;
  n2->left=n5;
  n2->right=n6;
//   inorderTraversal(root);

LevelOrder(root);

}