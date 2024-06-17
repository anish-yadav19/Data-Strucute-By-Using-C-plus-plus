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
    void topoSortByUsingBFS(int n,vector<int>&ans)
    {
        
        queue<int>q;
        unordered_map<int,int>indegree;

        // indegree calculation
        for(auto i:adj)
        {
            int src = i.first;
            for(auto nbr:i.second)
            {
                indegree[nbr]++;
            }
        }

        //put all nodes inside queue which has indegree = 0
        for(int i = 0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int fnode = q.front();
            q.pop();
            // cout<<fnode<<", ";
            ans.push_back(fnode);


            for(auto nbr:adj[fnode])
            {
                indegree[nbr]--;
                //chech for zero again
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        

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
     vector<int>ans;
    // for disconnected graph we have to make loop and before call bfs chech it is visited or not
    
    g.topoSortByUsingBFS(n,ans); 
    //cycle detection
    if(ans.size() == n)
    {
        cout<<"cycle not present"<<endl;
    }
    else
    {
        cout<<"Cycle is present"<<endl;
    }
    
    cout<<"Topo Sort: "<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
