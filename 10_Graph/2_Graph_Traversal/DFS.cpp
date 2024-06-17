

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph
{
    public:
    unordered_map<int,list<T>>adj;

    void addEdge(T u, T v,bool direction)
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
    void dfs(T src,unordered_map<T,bool>&visited)
    {
        cout<<src<<" ";
        visited[src] = true;

            for(auto i:adj[src])
            {
                if(!visited[i])
                {
                    dfs(i,visited);
                }
            }
        

    }
};

int main()
{

    Graph<int> g;
    int n = 5;
    unordered_map<int,bool>visited;
    //undirected input
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    g.addEdge(2,4,0);
    // g.addEdge(7,4,0);
   
    cout<<endl;
    // g.printAdjacentList();
    cout<<endl;

    // for disconnected graph we have to make loop and before call bfs chech it is visited or not
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited);
        }
    }
    
    return 0;
}
