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
    
void bellManFordAlgo(int n, int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    for(int i = 0;i<n-1;i++)
    {
        // n-1 relaxation step
        for(auto t:adj)
        {
            for(auto nbr:t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    //to check for negative cycle
    bool negativecycle = false;
    for(auto t:adj)
        {
            for(auto nbr:t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    negativecycle = true;
                    break;
                }
            }
        }
        if(negativecycle == true)
        {
            cout<<"-ve cycle present"<<endl;
        }
        else
        {
            cout<<"-ve cycle not present"<<endl;
        }

    cout<<"Printing dist arr: "<<endl;;
    for(auto i: dist)
    {
        cout<<i<<" ";
    }

}

void floydWarshall(int n)
{
    vector<vector<int>>dist(n,vector<int>(n,100000)); // don't use INT_MAX 
    for(int i = 0;i<n;i++)
    {
        dist[i][i] = 0;  // diagonal element = 0

    }

    for(auto t:adj)
    {
        for(auto nbr: t.second)
        {
            int u = t.first;
            int v = nbr.first;
            int wt = nbr.second;

            dist[u][v] = wt;
        }
    }

    for(int helper = 0;helper<n;helper++)
    {
        for(int src = 0;src<n;src++)
        {
            for(int dest = 0;dest<n;dest++)
            {
                dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
            }
        }
    }

    cout<<"Printing distance array:"<<endl;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
   
   
};

int main()
{
    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);

    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);

   



    

    g.printAdj();

    
    cout<<endl;
   g.floydWarshall(4);

    return 0;
}