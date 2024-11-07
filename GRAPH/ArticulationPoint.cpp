//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=0;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],vector<int>&time,vector<int>&low,set<int> &res){
        vis[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent)
            continue;
            else if(vis[it]){
                low[node]=min(low[node],time[it]);
            }else{
                dfs(it,node,vis,adj,time,low,res);
                low[node]=min(low[node],low[it]);
                child++;
                if(parent==-1)
                continue;
                if(low[it]>=time[node])
                res.insert(node);
            }
        }
        if(parent==-1 && child>1)
        res.insert(node);
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> low(n),time(n);
        vector<int> vis(n,0);
        set<int> res;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,time,low,res);
            }
        }
        vector<int> v(res.begin(),res.end());
        if(!v.size())
        return {-1};
        return v;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends