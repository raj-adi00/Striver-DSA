#include<bits/stdc++.h>
using namespace std;
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i <= n; i++)
            size[i] = 1;
    }
    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int findNodeIndex(int x, int y, int n) { return x * n + y; }
    bool isValidIndex(int x, int y, int n) {
        if (x >= 0 && x < n && y >= 0 && y < n)
            return true;
        else
            return false;
    }
    int largestIsland(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> row = {1, -1, 0, 0}, col = {0, 0, 1, -1};
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currentInd = findNodeIndex(i, j, n);
                if (v[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + row[k];
                        int ny = j + col[k];
                        if (isValidIndex(nx, ny, n) && v[nx][ny] == 1) {
                            int adjIndex = findNodeIndex(nx, ny, n);
                            ds.unionBySize(adjIndex, currentInd);
                        }
                    }
                }
            }
        }
        map<int, int> m;
        int ans = 0;
        vector<vector<int>> parents(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0)
                    continue;
                int ult = ds.findUltimateParent(findNodeIndex(i, j, n));
                parents[i][j] = ult;
                m[ult]++;
                ans = max(ans, m[ult]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) {
                    int currIndex = findNodeIndex(i, j, n);
                    set<int> temp;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + row[k];
                        int ny = j + col[k];
                        if (isValidIndex(nx, ny, n) && v[nx][ny] == 1)
                            temp.insert(parents[nx][ny]);
                    }
                    int x = 1;
                    for (auto val : temp) {
                        x += m[val];
                    }
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }




    int largestIsland2(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> row = {1, -1, 0, 0}, col = {0, 0, 1, -1};
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currentInd = findNodeIndex(i, j, n);
                if (v[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + row[k];
                        int ny = j + col[k];
                        if (isValidIndex(nx, ny, n) && v[nx][ny] == 1) {
                            int adjIndex = findNodeIndex(nx, ny, n);
                            ds.unionBySize(adjIndex, currentInd);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index = findNodeIndex(i, j, n);
                if (ds.parent[index] == index)
                    ans = max(ans, ds.size[index]);
                if (v[i][j] == 0) {
                    set<int> temp;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + row[k];
                        int ny = j + col[k];
                        int adjNodeIndex = findNodeIndex(nx, ny, n);
                        if (isValidIndex(nx, ny, n) && v[nx][ny] == 1)
                            temp.insert(ds.findUltimateParent(adjNodeIndex));
                    }
                    int x = 1;
                    for (auto val : temp) {
                        x += ds.size[val];
                    }
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
};