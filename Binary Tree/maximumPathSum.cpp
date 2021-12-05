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
int mx=0;

int checkSum(Node *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }

    
    int left=checkSum(root->left,ans);

    if(left<0)
    {
        left=0;
    }
    int right=checkSum(root->right,ans);
    if(right<0)
    {
        right=0;
    }
  
  ans=max(ans,left+right+root->data);
  return max(left,right)+root->data;
  
}

int main()
{
    
 Node *root=new Node(-50);
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
 
 

 /*
          -50
         /    \
       12      13
      /  \    /  \
     14  15  16   17
                    
 */

//  preorder(root);

int ans=INT_MIN;

checkSum(root,ans);

cout<<"Maximum Path Sum : "<<ans<<endl;



}