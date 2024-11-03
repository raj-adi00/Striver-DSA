#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;

public:
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


    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        unordered_map<string, int> m;
        int n = v.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            auto vec = v[i];
            for (int j = 1; j < vec.size(); j++) {
                auto str = vec[j];
                if (m.find(str) != m.end()) {
                    ds.unionBySize(m[str], i);
                } else
                    m[str] = i;
            }
        }
        vector<vector<string>> res(n);
        for (auto val : m) {
            int ulp = ds.findUltimateParent(val.second);
            res[ulp].push_back(val.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            vector<string> temp;
            if (res[i].size()) {
                sort(res[i].begin(), res[i].end());
                temp.push_back(v[i][0]);
                for (auto val : res[i])
                    temp.push_back(val);
                ans.push_back(temp);
            }
        }
        return ans;
    }






    vector<vector<string>> accountsMerge2(vector<vector<string>>& accounts) {
        vector<pair<int, int>> edges;
        int v = accounts.size();
        for (int i = 0; i < v; i++) {
            string name = accounts[i][0];
            for (int j = i + 1; j < v; j++) {
                int flag=0;
                string nm = accounts[j][0];
                if (nm == name) {
                    for (int k = 1; k < accounts[i].size(); k++) {
                        for (int l = 1; l < accounts[j].size(); l++) {
                            if (accounts[i][k] == accounts[j][l]) {
                                edges.push_back({i, j});
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1)
                        break;
                    }
                }
            }
        }
        DisjointSet ds(v);
        for (auto val : edges) {
            auto u = val.first, v = val.second;
            ds.unionBySize(u, v);
        }
        map<int, set<string>> m;
        for (int i = 0; i < v; i++) {
            int ulp = ds.findUltimateParent(i);
            for(int j=1;j<accounts[i].size();j++){
            m[ulp].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto it : m) {
            auto name = accounts[it.first][0];
            auto st = it.second;
            vector<string> temp;
            temp.push_back(name);
            for (auto val : st)
                temp.push_back(val);
            res.push_back(temp);
        }
        return res;
    }
};