

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
    void bfs(T src,unordered_map<T,bool>&visited)
    {
        queue<T>q;
        // unordered_map<T,bool>visited;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout<<node<<" ";

            for(auto i:adj[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

    }
};

int main()
{

    Graph<int> g;
    int n = 8;
    unordered_map<int,bool>visited;
    //undirected input
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
   
    cout<<endl;
    // g.printAdjacentList();
    cout<<endl;

    // for disconnected graph we have to make loop and before call bfs chech it is visited or not
    for(int i = 0;i<=n;i++)
    {
        if(!visited[i])
        {
            g.bfs(i,visited);
        }
    }
    
    return 0;
}
