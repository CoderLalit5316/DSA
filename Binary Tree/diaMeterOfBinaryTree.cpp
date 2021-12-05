#include<iostream>
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

int diameter=0;

int checkDiameter(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh=checkDiameter(root->left);
    int rh=checkDiameter(root->right);

    if((lh+rh)>diameter)
    {
      diameter=lh+rh;
    }

    return 1+max(lh,rh);
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

//  preorder(root);

checkDiameter(root);

cout<<"Diameter Of Tree : "<<diameter<<endl;



}