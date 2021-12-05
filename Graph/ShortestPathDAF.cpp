#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void solve(int node,vector<pair<int,int> > adj[],int V,stack<int> &st,int vis[])
  {
    vis[node]=1;

    for(auto it : adj[node])
    {
        if(vis[it.first]==0)
        {
            solve(it.first,adj,V,st,vis);
        }
    }
    st.push(node);

  }


void ShortestPath(int node,vector<pair<int,int>> adj[],int V)
{
   int vis[V]={0};
   int path[V];
   for(int i=0;i<V;i++)
   {
       path[i]=INT_MAX;
   }
        stack<int>st;
        solve(node,adj,V,st,vis);
        
        // while(st.size()!=0)
        // {
        //     int n=st.top();
        //     st.pop();
        // }

        path[0]=0;
        int inf=INT_MAX;

        while(st.size()!=0)
        {
            int n=st.top();
            st.pop();
         if(inf!=path[n])
         {
           for(auto it : adj[n])
            {
               if(it.second+path[n]<path[it.first])
               {
                   path[it.first]=it.second+path[n];
               }
            }
         }
            
        }

        for(int i=0;i<V;i++)
        {
            cout<<path[i]<<" ";
        }
}


int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<pair<int,int>> adj[v];
   int vis[v];

//    for(int i=0;i<v;i++)
//    {
//        vis[i]=-1;
//    }
   memset(vis,0,sizeof vis);

    for(int i=0;i<e;i++)
    {
        int v1,v2,p1;
        cin>>v1>>v2>>p1;
        adj[v1].push_back({v2,p1});
        // adj[v2].push_back(v1);
    }

    // ShortestPath(0,adj,v);

    // dfs(0,adj,vis);

    // bfs(0,adj,vis);
  ShortestPath(0,adj,v);
  


    
}