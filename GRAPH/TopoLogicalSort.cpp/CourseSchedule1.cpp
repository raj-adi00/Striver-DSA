#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &v)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto pr : v)
        {
            adj[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int x = q.front();
            cnt++;
            q.pop();
            for (auto val : adj[x])
            {
                indegree[val]--;
                if (indegree[val] == 0)
                {
                    q.push(val);
                }
            }
        }
        return (cnt == n);
    }
};