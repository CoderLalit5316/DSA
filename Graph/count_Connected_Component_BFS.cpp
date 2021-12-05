#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=10e5+10;
vector<int> g[N];
int vis[N];


void DFS(int node)
{
    cout<<node<<" ";
    vis[node]=1;

    for(int it:g[node])
    {
        if(vis[it]!=1)
        {
            DFS(it);
        }
    } 
}

int main()
{
 int n,m;
 cin>>n>>m;

 for(int i=0;i<m;i++)
 {
     int v1,v2;
     cin>>v1>>v2;
     g[v1].push_back(v2);
     g[v2].push_back(v1);
 }

int count=0;

for(int i=1;i<=n;i++)
{
 if(vis[i]==1)
 {
     continue;
 }
 else
 {
   count++;
   DFS(i);
 }
}

cout<<"Connected Component Is : "<<count;

}