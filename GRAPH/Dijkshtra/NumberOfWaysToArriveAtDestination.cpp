#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& v) {
        if(n==1)
        return 1;
        vector<vector<pair<long long,long long>>> adj(n);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        for(auto vec:v){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }
        vector<long long> time(n,1e13);
        vector<vector<long long>> parent(n);
        time[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            auto currentTime=it.first;
            auto node=it.second;
            for(auto val:adj[node]){
                auto adjNode=val.first;
                auto edgeW=val.second;
                if(edgeW+currentTime<time[adjNode]){
                    time[adjNode]=currentTime+edgeW;
                    pq.push({time[adjNode],adjNode});
                   parent[adjNode].clear();
                   parent[adjNode].push_back(node);
                }else if(edgeW+currentTime==time[adjNode]){
                    parent[adjNode].push_back(node);
                }
            }
        }
        vector<int> dp(n,-1);
       function<int(int)>f=[&](int node)->int{
         if(node==0)
         return 1;
         if(dp[node]!=-1)
         return dp[node];
         int ans=0;
         for(auto val:parent[node]){
            ans=(ans+f(val)%mod)%mod;
         }
      return dp[node]=ans;
       };
       if(parent[n-1].size()==0)
       return -1;
       else
       return f(n-1);
    }
};


    int PathCount(int n, vector<vector<int>>& v) {
        if(n==1)
        return 1;
        vector<vector<pair<long long,long long>>> adj(n);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        for(auto vec:v){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }
        vector<long long> time(n,1e13);
        vector<long long> ways(n,0);
        time[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            auto currentTime=it.first;
            auto node=it.second;
            for(auto val:adj[node]){
                auto adjNode=val.first;
                auto edgeW=val.second;
                if(edgeW+currentTime<time[adjNode]){
                    time[adjNode]=currentTime+edgeW;
                    pq.push({time[adjNode],adjNode});
                   ways[adjNode]=ways[node];
                }else if(edgeW+currentTime==time[adjNode]){
                   ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
      if(ways[n-1]==0)
      return -1;
      else return ways[n-1];
       
    }
int main() {
    int n=7;

    vector<vector<int>> edges={
    {0, 6, 7},
    {0, 1, 2},
    {1, 2, 3},
    {1, 3, 3},
    {6, 3, 3},
    {3, 5, 1},
    {6, 5, 1},
    {2, 5, 1},
    {0, 4, 5},
    {4, 6, 2}
};
    Solution solution;
    int result = solution.countPaths(n, edges);

    if(result == -1) {
        cout << "No path exists from node 0 to node " << n-1 << ".\n";
    } else {
        cout << "The number of distinct shortest paths from node 0 to node " << n-1 << " is: " << result << endl;
    }

    return 0;
}
