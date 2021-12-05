  #include<iostream>
  #include<bits/stdc++.h>

  using namespace std;
  
  bool check(int node,vector<int> adj[],vector<int> &vis,vector<int> &path)
  {
      vis[node]=1;
      path[node]=1;
      
      for(int it:adj[node])
      {
          if(vis[it]==0)
          {
              if(check(it,adj,vis,path))
                {
                    return true;
                }
          }
          else if(path[it]==1)
          {
              return true;
          }
      }
      path[node]=0;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V,0);
        vector<int> path(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(check(i,adj,vis,path))
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
	}

if(isCyclic(v,adj))
{
    cout<<"Cycle Present.";
    return 0;
}

cout<<"Cycle Not Present.";
return 0;

}