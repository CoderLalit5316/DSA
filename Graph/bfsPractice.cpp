#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+2;
int vis[N];


void bfs(int n,vector<int>adj[])
{
	
	queue<int>q;
	q.push(n);
	vis[n]=1;
	
	while(q.size()!=0)
	{
       int node=q.front();
	   q.pop();
	   cout<<node<<" ";
	   for(auto it : adj[node])
	   {
		   if(vis[it]==0)
		   {
			   q.push(it);
		       vis[it]=1;
		   }
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


for(int i=1;i<=v;i++)
{
	if(vis[i]==0)
	{
		bfs(i,adj);
	}
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