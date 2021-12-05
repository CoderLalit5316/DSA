#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+2;
int vis[N];
int order[N];

bool dfs(int n,vector<int>adj[])
{
    vis[n]=1;
    order[n]=1;

    for(int it : adj[n])
    {
        if(vis[it]!=1)
        {
          if(dfs(it,adj))
          {
              return true;
          }
        }
        else if(order[it])
        {
            return true;
        }
    }
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

int flag=0;
for(int i=1;i<=v;i++)
{
	if(vis[i]==0)
    {
        if(dfs(i,adj))
        {
            // cout<<"Cycle Present.";
            flag=1;
        }
    }
}

if(flag==1)
{
  cout<<"Cycle Present.";
}
else
  {
     cout<<"Cycle Not Present.";
    }
	// for(int i=1;i<=v;i++)
	// {
	// 	cout<<i<<" --> ";
	// 	for(int j=0;j<adj[i].size();j++)
	// 	{
	// 		cout<<adj[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}