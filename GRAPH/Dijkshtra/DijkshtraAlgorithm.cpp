#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min HEap

        int v = adj.size();
        vector<int> dist(v, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if (edgeWeight + dist[node] < dist[adjNode])
                {
                    dist[adjNode] = edgeWeight + dist[node];
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

vector<int> dijkstraUsingSet(vector<vector<pair<int, int>>> &adj, int src)
{
    // Code here
    set<pair<int, int>> s;
    int v = adj.size();
    vector<int> dist(v, 1e9);
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {
        auto pr = *(s.begin());
        int dis = pr.first;
        int node = pr.second;
        s.erase(pr);
        for (auto it : adj[node])
        {
            int edgeWeight = it.second;
            int adjNode = it.first;
            if (edgeWeight + dist[node] < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    s.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = edgeWeight + dist[node];
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends