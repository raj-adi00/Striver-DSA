#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int x) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for (auto vec : edges) {
            int u = vec[0], v = vec[1], w = vec[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = -1;
        int numberofcity = 1e8;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= x)
                    temp++;
            }
            if (temp < numberofcity) {
                ans = i;
                numberofcity = temp;
            } else if (temp == numberofcity)
                ans = i;
        }
        return ans;
    }



     int dijkshtra(int src, int n, vector<vector<pair<int, int>>>& adj, int x) {
            ios_base::sync_with_stdio(0), cin.tie(0);
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        set<pair<int, int>> s;
        s.insert({0, src});
        while (!s.empty()) {
            auto it = (*s.begin());
            s.erase(s.begin());
            auto node = it.second;
            auto dis = it.first;
            for (auto val : adj[node]) {
                int adjNode = val.first;
                int edgeW = val.second;
                if (dis + edgeW < dist[adjNode]) {
                    if (dist[adjNode] != 1e8)
                        s.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgeW;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= x)
                temp++;
        }
        return temp;
    }
    int cityCalc(int n, vector<vector<int>>& edges, int x) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto vec : edges) {
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int city = 1e8, ans = -1;
        for (int i = 0; i < n; i++) {
            int temp = dijkshtra(i, n, adj, x);
            if (temp < city) {
                city = temp;
                ans = i;
            } else if (temp == city)
                ans = i;
        }
        return ans;
    }
};