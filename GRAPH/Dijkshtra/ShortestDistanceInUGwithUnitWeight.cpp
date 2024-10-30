/*
*      Author: raj_adi
*      HAPPY CODING!!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long,long>
#define ll long long
#define int long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define limit 100005
#define fixed(n)  << setprecision(n)
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
void solve()
{
for(int i=0;i<1;i++);
int n,m;vector<vector<int>> v;int src;
vector<vector<int>> adj(n);
for(int i=0;i<m;i++){
    adj[v[i][0]].push_back(v[i][1]);
    adj[v[i][1]].push_back(v[i][0]);
}
vector<int> dis(n,mod);
dis[src]=0;
queue<pii> q;
q.push({src,0});
while(!q.empty()){
    auto val=q.front();
    int node=val.first;
    int dist=val.second;
    q.pop();
    for(auto x:adj[node]){
      if(dis[x]==mod){
        dis[x]=dist+1;
        q.push({x,dis[x]});
      }
    }
}
for(auto & x:dis){
    if(x==mod)
    x=-1;
}
}
signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
int t;
cin>>t;
while(t--)
{
solve();
}
}