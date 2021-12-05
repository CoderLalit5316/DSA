#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void ShortestPath(int node,vector<int> adj[],int V)
{
  queue<pair<int,int>> q;
  int path[V];
  for(int i=0;i<=V;i++)
  {
    path[i]=INT_MAX;
    // cout<<path[i]<<" ";
  }
  q.push({0,0});
  path[node]=0;

  while(q.size()!=0)
  {
      int n=q.front().first;
      int distance=q.front().second;
      q.pop();
      for(auto it : adj[n])
      {
          if(path[it]>distance+1)
          {
              path[it]=distance+1;
              q.push({it,distance+1});
          }
      }
  }

  for(int i=1;i<=V;i++)
  {
    cout<<path[i]<<" ";
  }




}

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v];
   int vis[v];

//    for(int i=0;i<v;i++)
//    {
//        vis[i]=-1;
//    }
   memset(vis,-1,sizeof vis);

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    // for(int i=0;i<v;i++)
    // {
    //     cout<<i<<" --> ";
    //     for(int it : adj[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    ShortestPath(1,adj,v);


    
}