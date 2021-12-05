#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int> adj[],vector<int> &vis,int v)
{
  cout<<node<<" ";
  vis[node]=1;

  for(int it:adj[node])
  {
      if(vis[it]!=1)
      {
          dfs(it,adj,vis,v);
      }
  }
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];
    vector<int> vis{v+1,0};

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    

    // for(int i=1;i<=v;i++)
    // {
    //     cout<<i<<" --> ";
    //     for(int it:adj[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

  dfs(1,adj,vis,v);
    
}