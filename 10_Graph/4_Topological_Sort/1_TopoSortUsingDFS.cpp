#include<bits/stdc++.h>
using namespace std;
// template<typename T>

class Graph
{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u, int v,bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed grpah
        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjacentList()
    {
        for(auto node: adj)
        {
            cout<<node.first<<" -> ";
            for(auto neighbour:node.second)
            {
                cout<<neighbour<<", ";
            }
            cout<<endl;
        
        }
    }
    void topoSort(int src,unordered_map<int,bool>&visited,stack<int>&ans)
    {
        // cout<<src<<" ";
        visited[src] = true;

            for(auto nbr:adj[src])
            {
                if(!visited[nbr])
                {
                    topoSort(nbr,visited,ans);
                }
            }
            ans.push(src);
        

    }
};

int main()
{

    Graph g;
    int n = 8;
   
    //undirected input
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    
   
    // cout<<endl;
    // g.printAdjacentList();
    // cout<<endl;
     unordered_map<int,bool>visited;
     stack<int>ans;
    // for disconnected graph we have to make loop and before call bfs chech it is visited or not
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            g.topoSort(i,visited,ans);
        }
    }
    cout<<"Topo Sort: "<<endl;
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
    return 0;
}
