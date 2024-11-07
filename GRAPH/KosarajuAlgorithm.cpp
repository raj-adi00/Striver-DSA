#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	stack<int> s;
	void dfs(vector<int>& vis, vector<vector<int>>& adj,int node){
	    vis[node]=1;
	    for(auto val:adj[node]){
	        if(!vis[val])
	        dfs(vis,adj,val);
	    }
	    s.push(node);
	}
	void simpleDFS(vector<int> & vis,vector<vector<int>>& adj,int node,vector<int> &temp){
	    vis[node]=1;
        temp.push_back(node);
	    for(auto val:adj[node]){
	        if(!vis[val])
	        simpleDFS(vis,adj,val,temp);
	    }
	}
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i])
            dfs(vis,adj,i);
        }
        vector<vector<int>> adjacency(v);
        for(int i=0;i<v;i++){
            vis[i]=0;
            for(auto node:adj[i]){
                adjacency[node].push_back(i);
            }
        }
        int ssc=0;
        vector<vector<int>> comp;
        while(!s.empty()){
            auto it=s.top();
            s.pop();
            if(vis[it])
            continue;
            ssc++;
            vector<int> temp;
            simpleDFS(vis,adjacency,it,temp);
            comp.push_back(temp);
        }
        //comp ssc components
        return ssc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends