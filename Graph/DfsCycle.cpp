#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool dfsCycle(int node,int parent,vector<int>adj[],vector<int> &vis)
{
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfsCycle(it, node, adj, vis)) 
                    return true; 
            }
            else if(it!=parent) 
                return true; 
        }
        
        return false; 
    }

int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int> adj[v+1];
    vector<int> vis(v+1,0);

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    

    
  for(int i = 1;i<=v;i++) {
	        if(!vis[i]) {
	            if(dfsCycle(i, -1 , adj, vis)) 
              {
                cout<<"Cycle present.";
              }
               else
               {
                 cout<<"Cycle Not Present.";
                }
	        }
  } 
    
}

