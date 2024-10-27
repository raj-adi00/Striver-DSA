//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        map<pair<int,int>,int> mp;
        for(auto vec:edges){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
            mp[{vec[0],vec[1]}]=vec[2];
            mp[{vec[1],vec[0]}]=vec[1];
        }
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        set<pair<int,int>> s;
        s.insert({0,1});
        vector<int> parents(n+1,-1);
        while(!s.empty()){
            auto it=*(s.begin());
            s.erase(s.begin());
            auto dis=it.first;
            auto node=it.second;
            for(auto pr:adj[node]){
                int edgeWt=pr.second;
                int adjNode=pr.first;
                if(dis+edgeWt<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        s.erase({dist[adjNode],adjNode});
                    }
                     dist[adjNode]=dis+edgeWt;
                     s.insert({dist[adjNode],adjNode});
                     parents[adjNode]=node;
                }
            }
        }
        vector<int> res;
        int val=n;
        if(parents[n]==-1)
        {
            res.push_back(-1);
            return res;
        }
        res.push_back(n);
        while(val!=1){
            res.push_back(parents[val]);
            val=parents[val];
        }
        res.push_back(dist[n]);
        reverse(res.begin(),res.end());
        for(auto val:res)
        cout<<val<<" ";
        cout<<endl;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends