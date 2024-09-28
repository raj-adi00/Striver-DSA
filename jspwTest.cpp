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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
    dp[i][j] = -1
#define clear1dDP(dp, n)        \
    for (int i = 0; i < n; i++) \
    dp[i] = -1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
        out << x << ' ';
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int v;
    vector<int> adj[5];

    queue<int> q;
    vector<int> deg(v, 0);
    vector<int> revAdj[v];
    int i = 0;
    vector<int> res;
    for (auto vec : adj)
    {
        for (auto val : vec)
        {
            revAdj[val].push_back(i);
            deg[i]++;
        }
        if (vec.size() == 0)
            q.push(i);
        deg[i]=vec.size();
        i++;
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        res.push_back(val);
        for (auto value : revAdj[val])
        {
            deg[value]--;
            if (deg[value] == 0)
                q.push(value);
        }
    }
    cout << res << endl;
}