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
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 //UNDIRECTED GRAPH
 //UNWEIGHTED

 //M_1 ADJACENCY MATRIX;0
 
 /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1,vector<int>(n+1,0));
 for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
 }
 */



 //M_2 ADJACENCY LIST

 /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1);
 for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
 }
 */


 //WEIGHTED

  //M_1 ADJACENCY MATRIX;

  /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1,vector<int>(n+1,0));
 for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u][v]=w;
    adj[v][u]=w;
 }
*/


 //M_2 ADJACENCY LIST

 /*
 int n,m;
 cin>>n>>m;
 vector<vector<pii>>adj(n+1);
 for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
 }
 */


//DIRECTED GRAPH
//UNWEIGHTED

 //M_1 ADJACENCY MATRIX;
 /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1,vector<int>(n+1,0));
 for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u][v]=1;
 }
*/


//M_2 ADJACENCY LIST

 /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1);
 for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
 }
 */

//WEIGHTED

  //M_1 ADJACENCY MATRIX;

  /*
 int n,m;
 cin>>n>>m;
 vector<vector<int>>adj(n+1,vector<int>(n+1,0));
 for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u][v]=w;
 }
*/


 //M_2 ADJACENCY LIST

 /*
 int n,m;
 cin>>n>>m;
 vector<vector<pii>>adj(n+1);
 for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
 }
 */

}