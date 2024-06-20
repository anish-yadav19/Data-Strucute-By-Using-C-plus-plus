#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>>adj;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> directed graph
        // direction = 0 -> undirected graph
        adj[u].push_back({v,wt});
        if(direction == 0)
        {
            adj[v].push_back({u,wt});
        }
    }

    void printAdj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    void shortestPathDirectedDFS( int dst,stack<int>&topoOrder,int n)
    {
        vector<int>dist(n,INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        for(auto nbr: adj[src])
        {
            if(dist[src] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[src] + nbr.second;
            }
        }

        while(!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX)
            {
                for(auto nbr: adj[topElement])
                {
                    if(dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }
        cout<<"Printing Ans: "<<endl;
        for(int i = 0;i<n;i++)
        {
            cout<<i<<"-> "<<dist[i]<<endl;
        }

    }

    void topoSort(int src,unordered_map<int,bool>&visited,stack<int>&ans)
    {
        // cout<<src<<" ";
        visited[src] = true;

            for(auto nbr:adj[src])
            {
                if(!visited[nbr.first])
                {
                    topoSort(nbr.first,visited,ans);
                }
            }
            ans.push(src);
        

    } 
};

int main()
{
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);

    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);

    g.addEdge(4,3,1,1);
    

    g.printAdj();

    int src = 0;
    int dst = 4;
    stack<int>topoOrder;
    unordered_map<int,bool>visited;

    g.topoSort(src,visited,topoOrder);

    g.shortestPathDirectedDFS(dst,topoOrder,5);

    return 0;
}