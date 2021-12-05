#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bfs(int node,vector<int> adj[],int v)
{
   int vis[v+1]={0};
  queue<int>q;
  q.push(node);
  vis[node]=1;

  while (q.size()!=0)
  {
      int n=q.front();
      cout<<n<<" ";
      q.pop();
      for(int it:adj[n])
      {
          if(vis[it]==0)
          {
            q.push(it);
            vis[it]=1;
          }
      }

  }
  


}

bool checkCycle(int node,int parent,vector<int> adj[],int v)
{
  queue<pair<int,int>>q;
  q.push({node,parent});
  int vis[v+1]={0};
  vis[node]=1;

  while(q.size()!=0)
  {
    int n=q.front().first;
    parent=q.front().second;
    q.pop();

    for(int it:adj[n])
    {
      if(!vis[it])
      {
        q.push({it,n});
        vis[it]=1;
      }
      else if(parent!=it)
         {
            return true;
         }
      }
    }
  return false;
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];

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


  bfs(1,adj,v);
  if(checkCycle(1,-1,adj,v))
  {
    cout<<"Cycle Present.";
  }
  else{
    cout<<"Cycle Not Present. ";
  }
    
}