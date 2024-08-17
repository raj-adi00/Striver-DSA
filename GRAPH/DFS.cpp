#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1
#define clear1dDP(dp,n) for(int i=0;i<n;i++) dp[i]=-1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define mod 1000000007
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
/*       <<<<<CODE HERE>>>>>      */
void DFS(int node,vector<int> & vis,vector<vector<int>> & adj,vector<int> &dfs){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it:adj[node])
    {
       if(!vis[it])
       DFS(it,vis,adj,dfs);
    }
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n, m,starting;
    cin >> n >> m>>starting;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+2,0),dfs;
    DFS(starting,vis,adj,dfs);
    cout<<dfs<<endl;
}