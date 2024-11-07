#include<bits/stdc++.h>
using namespace std;
class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>> & res,vector<int> &vis,vector<vector<int>>&adj,vector<int>&time,vector<int>&low){
        vis[node]=1;
        time[node]=timer;
        low[node]=min(low[node],timer);
        timer++;
        for(auto it:adj[node]){
            if(it==parent)
            continue;
            else if(vis[it]==1){
              low[node]=min(low[it],low[node]);
            }
            else{
                dfs(it,node,res,vis,adj,time,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>time[node])
                res.push_back({node,it});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> time(n,0),low(n,1e9);
        vector<vector<int>> res;
        dfs(0,-1,res,vis,adj,time,low);
        return res;
    }
};