
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


vector<int> leftView(Node *root)
{
   queue<Node*>q;
   vector<int>v;
   
   if(root==NULL)
   {
       return v;
   }
   vector<int>tmp;
   q.push(root);
   
   while(q.size()!=0)
   {
       int size=q.size();
       
       for(int i=0;i<size;i++)
       {
           Node *temp=q.front();
           q.pop();
           tmp.push_back(temp->data);
           
           if(temp->left)
           {
               q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
       }
       
       v.push_back(tmp[0]);
       tmp.clear();
   }
   return v;
   
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
v=leftView(root);
cout<<"Left View of Binary Tree : ";
 
        for (auto elem: v)
        {
            cout<<elem<<", ";
        }


}

