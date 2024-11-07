//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i <= n; i++)
            size[i] = 1;
    }
    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> v(n,vector<int>(m,0));
        int cnt=0;
        vector<int> res;
        vector<int> row={-1,1,0,0},col={0,0,-1,1};
        for(auto it:op){
            if(vis[it[0]][it[1]]==1){
 res.push_back(cnt);
            continue;
            }
            int x=it[0],y=it[1];
            vis[x][y]=1;
            v[x][y]=1;
            int flag=0;
             set<int>  temp;
            for(int k=0;k<4;k++){
                int nx=x+row[k];
                int ny=y+col[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(v[nx][ny]==1){
                    int ulp=ds.findUltimateParent(nx*m+ny);
                    temp.insert(ulp);
                    }
                }
            }
            int currind=x*m+y;
            while(temp.size()){
                ds.unionBySize(currind,(*temp.begin()));
                temp.erase(temp.begin());
                cnt--;
            }
            cnt++;
           res.push_back(cnt);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends