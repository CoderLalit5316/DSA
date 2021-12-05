#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool checkBip(int node,vector<int>adj[],int vis[])
{
   if(vis[node]==-1)
   {
       vis[node]=1;
   }
  for(int it : adj[node])
  {
     if(vis[it]==-1)
     {
         vis[it]=1-vis[node];
         if(!checkBip(it,adj,vis))
         {
             return false;
         }
     }
     else if(vis[it]==vis[node])
     {
         return false;
     }
  }

  return true;
}

int main()
{
    int v,e;
    cin>>v>>e;

      int vis[v];
    memset(vis, -1, sizeof vis); 
    
    vector<int> adj[v+1];
     

//    for(int i=1;i<=v;i++)
//    {
//        vis[i]=-1;
//    }


    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }


   
 for(int i=1;i<=v;i++)
 {
     if(vis[i]==-1)
     {
         if(!checkBip(i,adj,vis))
         {
             cout<<"Graph Is Not Bipartite.";
             return 0;
         }
     }
 }

cout<<"Graph is Bipartite.";


    
}