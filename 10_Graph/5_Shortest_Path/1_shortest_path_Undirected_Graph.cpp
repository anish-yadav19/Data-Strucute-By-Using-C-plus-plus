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
    void shortestPathBFS(int src, int dst)
    {
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int, int>parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int fnode = q.front();
            q.pop();
            for(auto nbr : adj[fnode])
            {
                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fnode;
                }
            }

        }

        vector<int>ans;
        int node = dst;
        while(node!= -1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(), ans.end());

        cout<<endl;
        cout<<"Printing shortest path: "<<endl;
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(1,2,1,0);
    g.addEdge(2,3,1,0);

    g.addEdge(3,4,1,0);
    g.addEdge(0,5,1,0);
    g.addEdge(5,4,1,0);

    g.addEdge(0,6,1,0);
    g.addEdge(6,7,1,0);
    g.addEdge(7,8,1,0);
    g.addEdge(8,4,1,0);

    g.printAdj();

    int src = 0;
    int dst = 4;

    g.shortestPathBFS(src,dst);

    return 0;
}