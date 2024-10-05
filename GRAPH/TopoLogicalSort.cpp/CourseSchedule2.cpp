#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int c, vector<vector<int>> &v)
    {
        ios_base::sync_with_stdio(0), cin.tie(0);
        vector<vector<int>> calc(c);
        int n = v.size();
        vector<int> a(c, 0);
        for (int i = 0; i < n; i++)
        {
            a[v[i][0]]++;
            calc[v[i][1]].push_back(v[i][0]);
        }
        queue<int> q;
        vector<int> res;
        int cnt = 0;
        for (int i = 0; i < c; i++)
        {
            if (a[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int val = q.front();
            res.push_back(val);
            cnt++;
            q.pop();
            for (auto x : calc[val])
            {
                a[x]--;
                if (a[x] == 0)
                    q.push(x);
            }
        }
        if (cnt == c)
            return res;
        res.clear();
        return res;
    }
};