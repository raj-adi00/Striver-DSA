#include <bits/stdc++.h>
using namespace std;
#include <string>
#define pii pair<int, int>

class Solution
{
public:
    int ladderLength(string a, string b, vector<string> &v)
    {
        ios_base::sync_with_stdio(0), cin.tie(0);

        // If the end word is not in the word list, return 0 (no possible transformation)
        if (find(v.begin(), v.end(), b) == v.end())
        {
            return 0;
        }

        // Add the start word to the word list
        v.push_back(a);
        int n = v.size();

        // Lambda to check if two words differ by exactly one character
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

        // Find the target index for the end word
        int target = -1;
        vector<vector<int>> adj(n, vector<int>());

        // Build adjacency list for the word graph
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
        }

        // If no valid transformation can be made
        if (target == -1)
            return 0;

        // Perform BFS to find the shortest transformation sequence
        vector<int> dist(n, 1e9);
        queue<int> q;
        q.push(n - 1); // Start from the last word (which is the `beginWord`)
        dist[n - 1] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == 1e9)
                { // If this node hasn't been visited
                    dist[neighbor] = dist[node] + 1;
                    if (neighbor == target)
                    {
                        return dist[neighbor];
                    }
                    q.push(neighbor);
                }
            }
        }

        // If no path was found, return 0
        return 0;
    }
    // approach 2:
    int f(string a, string b, vector<string> &v)
    {
        queue<pair<string, int>> q;
        int l = a.length();
        q.push({a, 1});
        set<string> s(v.begin(), v.end());
        s.erase(a);
        function<int(string, int)> fun = [&](string x, int move) -> int
        {
            for (int i = 0; i < l; i++)
            {
                string p = x;
                for (int j = 97; j <= 122; j++)
                {
                    p[i] = (char)j;
                    if (s.find(p) != s.end())
                    {
                        q.push({p, move + 1});
                        s.erase(p);
                        if (p == b)
                            return move + 1;
                    }
                }
                p[i] = x[i];
            }
            return 0;
        };
        int ans = 0;
        while (!q.empty())
        {
            auto val = q.front();
            q.pop();
            auto str = val.first;
            auto move = val.second;
            ans = fun(str, move);
            if (ans != 0)
                return ans;
        }
        return 0;
    }
};
