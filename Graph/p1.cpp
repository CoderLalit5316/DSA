#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void ShortestPath(int node,vector<int> adj[],int V)
{
    int path[V];
    for(int i=0;i<V;i++)
    {
        path[i]=INT_MAX;
        // cout<<path[i]<<" ";
    }
    queue<int>q;
    q.push(node);
    path[0]=0;

    while(q.size()!=0)
    {
        int n=q.front();
        q.pop();
        for(int it:adj[n])
        {
            if(path[it]>path[n]+1)
            {
                path[it]=path[n]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        cout<<path[i]<<" ";
    }
    
    }

    void dfs(int node,vector<int> adj[],int vis[])
    {
      cout<<node<<" ";
      vis[node]=1;

      for(int it:adj[node])
      {
          if(vis[it]==0)
          {
              dfs(it,adj,vis);
          }
      }   
    }

    void bfs(int node,vector<int> adj[],int vis[])
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;

        while(q.size()!=0)
        {
            int n=q.front();
            q.pop();
            cout<<n<<" ";

            for(int it : adj[n])
            {
                if(vis[it]!=1)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
 
  void solve(int node,vector<int> adj[],int V,stack<int> &st,int vis[])
  {
    vis[node]=1;

    for(int it : adj[node])
    {
        if(vis[it]==0)
        {
            solve(it,adj,V,st,vis);
        }
    }
    st.push(node);
  }

    void topologicalSort(int node,vector<int> adj[],int V)
    {
        int vis[V]={0};
        stack<int>st;
        solve(node,adj,V,st,vis);

        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
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
   memset(vis,0,sizeof vis);

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        // adj[v2].push_back(v1);
    }

    // ShortestPath(0,adj,v);

    // dfs(0,adj,vis);

    // bfs(0,adj,vis);
  topologicalSort(0,adj,v);
  


    
}