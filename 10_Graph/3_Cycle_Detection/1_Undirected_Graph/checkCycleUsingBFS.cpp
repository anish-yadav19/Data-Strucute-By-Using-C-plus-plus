

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

    bool checkCycleUsingBFS(int src, unordered_map<int,bool>&visited)
    {
        queue<int>q;
        unordered_map<int,int>parent; 
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr:adj[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[node] = true;
                    parent[nbr]= node;
                }
                else
                {
                    // already visited
                    if(nbr !=parent[node])
                    {
                        //cycle present
                        return true;
                    }
                }
            }
        }
        return false;

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
    g.addEdge(6,4,0);
    g.addEdge(4,7,0);
   
    
    // g.printAdjacentList();
    // cout<<endl;

    bool ans = false;
    
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            ans = g.checkCycleUsingBFS(0,visited);
            if(ans == true)
            {
                break;
            }
        }
    }
    if(ans == true)
    {
        cout<<"Cycle is present"<<endl;
    }
    else
        cout<<"Cycle is not present"<<endl;

    /*
    // for disconnected graph we have to make loop and before call bfs chech it is visited or not
    for(int i = 0;i<=n;i++)
    {
        if(!visited[i])
        {
            g.bfs(i,visited);
        }
    }
    */
    
    return 0;
}
