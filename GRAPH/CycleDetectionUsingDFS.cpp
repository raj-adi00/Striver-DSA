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
bool DFS(int node,int parent,vector<int> adj[],vector<int> & vis){
    vis[node]=1;
    for(auto val:adj[node]){
        if(vis[val]==0){
        if(DFS(val,node,adj,vis))
        return true;
        }
        else if(val!=parent)
        return true;
    }
    return false;
}
bool findCycle(int V,vector<int> adj[]){
vector<int> vis(V,0);
for(int i=0;i<V;i++){
    if(!vis[i])
    if(DFS(i,-1,adj,vis))return true;
}
return false;
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
}