#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string a, string b, vector<string> &v)
    {
        ios_base::sync_with_stdio(0), cin.tie(0);
        v.push_back(a);
        int n = v.size();
        int target = -1;
        vector<vector<int>> adj(n, vector<int>());

        function<bool(string, string)> f = [&](string x, string y) -> bool
        {
            int cnt = 0;
            for (int i = 0; i < x.length(); i++)
            {
                if (x[i] != y[i])
                    cnt++;
                if (cnt > 1)
                    return false;
            }
            return cnt == 1;
        };
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (f(v[i], v[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if (v[i] == b)
                target = i;
            if (v[i] == a)
                start = i;
        }
        vector<vector<string>> res;
        if (target == -1)
            return res;
        vector<vector<int>> parents(n, vector<int>());
        vector<string> temp;
        queue<pair<int, int>> q;
        q.push({start, 1});
        vector<int> vis(n, INT_MAX);
        vis[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int move = q.front().second;
            q.pop();
            for (auto val : adj[node])
            {
                if (vis[val] > move + 1)
                {
                    parents[val] = {node};
                    vis[val] = move + 1;
                    q.push({val, move + 1});
                }
                else if (vis[val] == move + 1)
                {
                    parents[val].push_back(node);
                }
            }
        }
        vector<vector<string>> o;
        function<void(int)> Backtraking = [&](int node) -> void
        {
            temp.push_back(v[node]);
            if (start == node)
            {
                vector<string> o = temp;
                reverse(o.begin(), o.end());
                res.push_back(o);
            }
            for (auto parent : parents[node])
            {
                Backtraking(parent);
            }
            temp.pop_back();
        };
        if (vis[target] != INT_MAX)
        {
            Backtraking(target);
        }
        return res;
    }
}; 