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
int main()//SC:O(n)+O(n)    TC:O(N)+O(V+2E)
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
    cin >> n;
   vector<vector<int>>adj(n+1,vector<int>(n+1,0));
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    cin>>adj[i][j];
   }
    vector<int> vis(n+1,0);
    function<void(int)>DFS=[&](int node)->void{
        vis[node]=1;
        int c=0;
        for(auto it:adj[node]){
            if(it==1&& !vis[c])
            DFS(c);
            c++;
        }
    };
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            DFS(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}