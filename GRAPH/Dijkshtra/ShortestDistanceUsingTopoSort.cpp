#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    vector<vector<int>> v;
    int src = 0;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        adj[v[i][0]].push_back({v[i][1], v[i][2]});
    }

    stack<int> s;
    vector<int> vis(n);
    // V+E
    function<void(int)> DFS = [&](int node) -> void
    {
        vis[node] = 1;
        for (auto val : adj[node])
        {
            if (!vis[val.first])
                DFS(val.first);
        }
        s.push(node);
    };
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    vector<int> dis(n, mod);
    dis[src] = 0;
    // V+E
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        for (auto x : adj[val])
        {
            dis[x.first] = min(dis[val] + x.second, dis[x.first]);
        }
    }
    for (auto &val : dis)
    {
        if (val == mod)
            val = -1;
    }
}
// TC:(V+E)DFS and Stack(V+E)