#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>>adj(n,vector<int>(n,0));

    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}