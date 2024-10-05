//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> indegree(v);
        for (int i = 0; i < v; i++)
        {
            for (auto val : adj[i])
                indegree[val]++;
        }
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cnt++;
            for (auto val : adj[x])
            {
                indegree[val]--;
                if (indegree[val] == 0)
                    q.push(val);
            }
        }
        return (cnt != v);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends