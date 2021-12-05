#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> ans;

void topologicalSort(int node,vector<int>adj[],stack<int> &st,vector<int> &vis)
{
        vis[node] = 1; 
        for(auto it: adj[node]) 
        {
          if(vis[it]==0)
          {
              topologicalSort(it,adj,st,vis);
          }    
        }

        st.push(node);
         
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

stack<int>st;    

  for(int i=0;i<v;i++)
  {
      if(vis[i]==0)
      {
          topologicalSort(i,adj,st,vis);
      }
  }

  while(st.size()!=0)
  {
      cout<<st.top()<<" ";
      st.pop();
  }
    
}

