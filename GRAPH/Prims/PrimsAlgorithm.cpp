#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
//OVERALL TC: O(E log E)+O(E log E)
    // Function to find edges of the Minimum Spanning Tree and weight of MST
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // Weight,node,parent
        //SC: O(E)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        //SC O(V)
        vector<int> vis(v, 0);
        vector<pair<int, int>> mst;
        int mstWeight = 0;
        //TC: O(E)
        while (!pq.empty())
        {
            auto it = pq.top();
            //TC: O(log E)
            pq.pop();
            auto weight = it.first;
            auto node = it.second.first;
            auto parent = it.second.second;
            if (vis[node])
                continue;
            mst.push_back({node, parent});
            mstWeight += weight;
            vis[node] = 1;
            //TC: O(E)
            for (auto val : adj[node])
            {
                int adjNode = val[0];
                int adjWeight = val[1];
                if (!vis[adjNode])
                {
                    //Tc:O(log E)
                    pq.push({adjWeight, {adjNode, node}});
                }
            }
        }
        return mstWeight;
    }
};



// We do not need to store parent if we are not finding the edges of MST. so in that case min heap will have pair<int,int> only. Parent is required if we need to find the edges of MST;
int WeightOfSpanningTree(int v, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        pq;

    vector<int> vis(v, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~" << "\n";
    }

    return 0;
}

// } Driver Code Ends