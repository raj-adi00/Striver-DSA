// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;
// class Solution {
//   public:
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // Reverse the graph
//         vector<vector<int>> revAdj(V);
//         vector<int> outDegree(V, 0);

//         for (int i = 0; i < V; i++) {
//             for (int neighbor : adj[i]) {
//                 revAdj[neighbor].push_back(i);
//             }
//             outDegree[i] = adj[i].size();
//         }

//         queue<int> q;
//         vector<int> safeNodes;

//         // Terminal nodes (outDegree 0) are definitely safe
//         for (int i = 0; i < V; i++) {
//             if (outDegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         // Process nodes in reverse topological order
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             safeNodes.push_back(node);

//             for (int neighbor : revAdj[node]) {
//                 outDegree[neighbor]--;
//                 if (outDegree[neighbor] == 0) {
//                     q.push(neighbor);
//                 }
//             }
//         }

//         // Sort the safe nodes in ascending order
//         sort(safeNodes.begin(), safeNodes.end());

//         return safeNodes;
//     }
// };

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> eventualSafeNodes(int v, vector<int> adj[])
//     {
//         queue<int> q;
//         vector<int> deg(v, 0);
//         vector<vector<int>> revAdj(v);
//         vector<int> res;
//         for (int i = 0; i < v; i++)
//         {
//             for (auto val : adj[i])
//             {
//                 revAdj[val].push_back(i);
//             }
//             if (adj[i].size() == 0)
//                 q.push(i);
//             deg[i] = adj[i].size();
//         }

//         while (!q.empty())
//         {
//             int val = q.front();
//             q.pop();
//             res.push_back(val);
//             for (auto value : revAdj[val])
//             {
//                 deg[value]--;
//                 if (deg[value] == 0)
//                     q.push(value);
//             }
//         }
//         sort(res.begin(), res.end());
//         return res;
//     }
// };


#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int v;
    vector<vector<int>> adj;

    vector<int> vis(v, 0), pathVis(v, 0);
    vector<int> calc(v, 0);
    function<bool(int)> DFS = [&](int i) -> bool
    {
        vis[i] = 1;
        pathVis[i] = 1;
        bool check = false;
        for (auto val : adj[i])
        {
            if (!vis[val])
                check = check || DFS(val);
            else
            {
                if (pathVis[val] == 1)
                    return true;
            }
        }
        if (check == true)
        {
            calc[i] = 0;
            return check;
        }
        pathVis[i] = 0;
        calc[i] = 1;
        return check;
    };
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    vector<int> res;
    for (int i = 0; i < v; i++)
    {
        if (calc[i] == 1)
            res.push_back(i);
    }
}