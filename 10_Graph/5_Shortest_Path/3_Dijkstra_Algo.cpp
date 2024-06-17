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
    

   
    void shortestDistDijkstra(int src, int n)
    {
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty())
        {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDist = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for(auto nbr: adj[node])
            {
                if(nodeDist + nbr.second < dist[nbr.first])
                {
                    // find entry in set
                    auto result = st.find(make_pair(dist[nbr.first],nbr.first));
                    // if found
                    if(result != st.end())
                    {
                        st.erase(result);
                    }

                    //update in dist array and set
                    dist[nbr.first] = nodeDist + nbr.second;
                    st.insert(make_pair(dist[nbr.first],nbr.first));
                }
            }


        }
        cout<<"printing ans: "<<endl;
        for(int i = 0;i<n;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(6,5,9,0);

    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,15,0);
    g.addEdge(2,3,10,0);


    g.addEdge(3,4,11,0);
    g.addEdge(5,4,6,0);
    

    g.printAdj();

    int src = 6;
    int dst = 4;
    

    g.shortestDistDijkstra(src,7);

    return 0;
}