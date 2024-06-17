#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std; 

class Graph
{
    public:
    // unordered_map<int,list<int>>adj;

    // void addEdge(int u, int v,bool direction)
    // {
    //     // direction = 0 -> undirected graph
    //     // direction = 1 -> directed grpah
    //     // create an edge from u to v
    //     adj[u].push_back(v);
    //     if(direction == 0)
    //     {
    //         adj[v].push_back(u);
    //     }
    // }
    // void printAdjacentList()
    // {
    //     for(auto node: adj)
    //     {
    //         cout<<node.first<<" -> ";
    //         for(auto neighbour:node.second)
    //         {
    //             cout<<neighbour<<", ";
    //         }
    //         cout<<endl;
        
    //     }
    // }

    // printing edges with its value
    unordered_map<int,list<pair<int,int>>>adj;

    void addEdge(int u, int v,int weight,bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed grpah
        // create an edge from u to v
        adj[u].push_back({v,weight});
        if(direction == 0)
        {
            adj[v].push_back({u,weight});
        }
    }
    void printAdjacentList()
    {
        for(auto node: adj)
        {
            cout<<node.first<<" -> ";
            for(auto neighbour:node.second)
            {
                cout<<"("<<neighbour.first<<","<<neighbour.second<<"),";
            }
            cout<<endl;
        
        }
    }
};

int main()
{
    // int n,m;
    // cout<<"Enter the number of nodes: "<<endl;
    // cin>>n;
    // cout<<"Enter the number of edges: "<<endl;
    // cin>>m;

    // // undirected graph
    
    Graph g;

    // //undirected input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // cout<<endl;
    // g.printAdjacentList();

    // directed input
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    // cout<<endl;
    // g.printAdjacentList();


    // g.addEdge(srcNode, destNode, weight, direction)
    g.addEdge(0,1,8,1);
    g.addEdge(1,2,5,1);
    g.addEdge(0,2,7,1);
    cout<<endl;
    g.printAdjacentList();

    return 0;
}