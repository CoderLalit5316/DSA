#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool checkBip(int node,vector<int> adj[],int vis[])
{
 queue<int>q;
 q.push(node);
 vis[node]=0;
 int flag=true;

 while (q.size()!=0)
 {
   int n=q.front();
   q.pop();

   for(int it : adj[n])
   {
       if(vis[it]==-1)
       {
         if(vis[n]==0)
         {
             vis[it]=1;
             q.push(it);
         }
         else{
             vis[it]=0;
             q.push(it);
         }
       }
       else if(vis[n]==vis[it])
       {
        //    cout<<"No Bipartite.\n";
        //    return;
            return false;
       }
   }
 }
 return true;
//  cout<<"Yes Bipartite.";
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];
   int vis[v+1];

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

    bool flag=true;
  
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