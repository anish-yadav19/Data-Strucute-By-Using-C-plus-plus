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
    


void dfs(int src, stack<int>&st,unordered_map<int,bool>&visited)
{
    visited[src] = true;
    for(auto nbr:adj[src])
    {
        if(!visited[nbr])
        {
            dfs(nbr,st,visited);
        }
    }
    st.push(src);
}

void dfs2(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjNew )
{
    visited[src] = true;
    cout<<src<<" ";
    for(auto nbr:adjNew[src])
    {
        if(!visited[nbr])
        {
            dfs2(nbr, visited,adjNew);
        }
    }
}
int countSCC(int n)
{
    stack<int>st;
    unordered_map<int,bool>visited;

    // find topo ordering

    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,st,visited);
        }
    }
    
    // reversal all edges
    unordered_map<int, list<int>>adjNew;
    for(auto t:adj)
    {
        for(auto nbr: t.second)
        {
            int u = t.first;
            int v = nbr;

            adjNew[v].push_back(u);
        }
    }
    int count = 0;
    unordered_map<int,bool>visited2;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
         if(!visited2[node])
        {
            cout<<"Printing "<< count+1<<"th SCC: ";
            dfs2(node,visited2,adjNew);
            cout<<endl;
            
            count++;
        }
        
    }

    return count;

}
   
};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);

    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

   



    

    // g.printAdj();

    
    // cout<<endl;
    
    int ans = g.countSCC(8);
    cout<<ans;

    return 0;
}