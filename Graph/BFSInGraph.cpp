#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int vis[N]={0};
vector<int> g[N];


void bfs(int node)
{
   queue<int>q;
   q.push(node);
     vis[node]=1;

  while(q.size()!=0)
  {
    int temp=q.front();
    cout<<temp<<" ";
    q.pop();
     
     vector<int>::iterator it;  
     
     for(it=g[temp].begin();it!=g[temp].end();it++)
     {
       if(!vis[*it])
       {
         q.push(*it);
         vis[*it]=1;
       }
     }
     

  }
}
     
  

int main()
{
 int n,m;
 cin>>n>>m;

 for(int i=0;i<=n;i++)
 {
   vis[i]=0;
 }

 for(int i=0;i<m;i++)
 {
   int v1,v2;
   cin>>v1>>v2;
   g[v1].push_back(v2);
   g[v2].push_back(v1);
 }
 bfs(1);
 
 
}