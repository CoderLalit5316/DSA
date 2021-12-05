#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> g[v+1];

    for(int i=1;i<=e;i++)
    {
       int v1,v2;
       cin>>v1>>v2;
       g[v1].push_back(v2);
       g[v2].push_back(v1);
    }

    for(int i=1;i<=v;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

}