#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void ShortestPath(int node,vector<int> adj[],int V)
  {
      queue<int>q;
   int path[V+1];
   for(int i=0;i<=V;i++)
   {
     path[i]=INT_MAX;
    //  cout<<path[i]<<" ";
   }
   q.push(node);
   path[node]=0;

  
    //  int n=q.front();
    //  q.pop();

    //  for(auto it : adj[n])
    //  {
        
    //        if(path[it.first]>path[n]+it.second)
    //        {
    //            path[it.first]=path[n]+it.second;
    //            q.push(it.first);
    //        }  
           
         
    //  }
     while(q.size()!=0)
     {
        int n = q.front(); 
		q.pop();

        for(auto it:adj[n])
        {
            if(path[it]>path[n]+1)
            {
                path[it]=path[n]+1;
                q.push(it);
            }
        }
    } 
		 
   

   for(int i=1;i<=V;i++)
   {
       cout<<i<<" Distance ";
       cout<<path[i]<<" \n";
   }

  }


int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];

//    for(int i=0;i<v;i++)
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

    // ShortestPath(0,adj,v);

    // dfs(0,adj,vis);

    // bfs(0,adj,vis);
  ShortestPath(1,adj,v);
  


    
}
