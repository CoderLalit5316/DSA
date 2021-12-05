#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void topologySort(vector<int>adj[],int indegree[],int v)
{
    queue<int>q;
  for(int i=0;i<v;i++)
  {
    if(indegree[i]==0)
    {
        q.push(i);
    }
  }
   
   while(q.size()!=0)
   {
       int node=q.front();
       q.pop();
       cout<<node<<" ";
       for(int it:adj[node])
       {
           indegree[it]--;
           if(indegree[it]==0)
           {
               q.push(it);
           }
       }

   }
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];
    vector<int>vis(v,0);

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }

  int indegree[v]={0};

  for(int i=0;i<v;i++)
  {
      for(int it:adj[i])
      {
          indegree[it]++;
      }
  }

//    for(int i=0;i<v;i++)
//   {
//       cout<<indegree[i]<<" ";
//   }

  topologySort(adj,indegree,v);

  
}

