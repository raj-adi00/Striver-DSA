#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define pii pair<int, int>
class Solution
{
public:
    bool isBipartiteusingBFS(vector<vector<int>> &v)
    {
        int n = v.size();
        int m = v[0].size();
        vector<int> vis(n, -1);
        queue<pii> q;
        function<bool(int)> BFS = [&](int i) -> bool
        {
            q.push({i, -1});
            vis[i] = 0;
            while (!q.empty())
            {
                auto pr = q.front();
                q.pop();
                for (auto val : v[pr.first])
                {
                    if (vis[val] == -1)
                    {
                        q.push({val, pr.first});
                        vis[val] = 1 - vis[pr.first];
                    }
                    else
                    {

                        if (vis[val] == vis[pr.first])
                            return false;
                    }
                }
            }
            return true;
        };
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
                if (BFS(i) == false)
                    return false;
        }
        return true;
    }
    bool isBipartiteusingDFS(vector<vector<int>> &v)
    {
        int n = v.size();
        int m = v[0].size();
        vector<int> vis(n, -1);
        int flag = 0;
        function<void(int)> DFS = [&](int i) -> void
        {
            if (vis[i] == -1)
                vis[i] = 1;
            for (auto val : v[i])
            {
                if (vis[val] == -1)
                {
                    vis[val] = 1 - vis[i];
                    DFS(val);
                }
                else
                {
                    if (vis[val] == vis[i])
                    {
                        flag = 1;
                        return;
                    }
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                DFS(i);
                if(flag==1)
                cout<<"NO";
            }
        }
        cout<<"YES";
    }
};