

 #include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 1 -> directed graph
        // direction = 0 -> undirected graph
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<"("<<j<<", "<<"), ";
            }
            cout<<endl;
        }
    }
    



// By usign Tarjan's Algorithm

void findBridge(int src, int parent, int&timer, vector<int>&tin, vector<int>&low, unordered_map<int,bool>&visited)
{
    visited[src] = true;
    tin[src] = timer;
    low[src] = timer;
    timer++;
    int children = 0;
    
    for(auto nbr: adj[src])
    {
        if(nbr == parent)
        {
            continue;;
        }
        if(!visited[nbr])
        {
            findBridge(nbr,src,timer,tin,low,visited);

            // low update
            low[src] = min(low[src], low[nbr]);
            // check for bridge
            if(parent !=-1 && tin[src] <= low[nbr])
            {
                cout<<src<<" is an AP"<<endl;
            }
            children++;
        }
        else
        {
            // node is visited and not a parent
            // low update
            low[src] = min(low[src], low[nbr]);
        }
    }
    if(parent == -1 && children>1)
    {
        cout<<src<<" is an AP"<<endl;
    }
}
   
};

int main()
{
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(2,1,0);
    g.addEdge(0,3,0);
    g.addEdge(3,4,0);

    int n = 5;
    int timer = 0;
    vector<int>tin(n);
    vector<int>low(n);
    unordered_map<int,bool>visited;
   g.findBridge(0,-1,timer,tin,low,visited);
    

    return 0;
}