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
bool FindCycle(int V,vector<vector<int>>& adj){
   vector<int> vis(V, 0);
queue<pii> q;

for (int i = 0; i < V; i++) {
    if (!vis[i]) {
        q.push({i, -1});
        vis[i] = 1; 
        
        while (!q.empty()) {
            int ele = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto val : adj[ele]) {
                if (!vis[val]) {
                    q.push({val, ele});
                    vis[val] = 1; 
                } else if (val != parent) {
                    return true;
                }
            }
        }
    }
}
return false;

}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);

}