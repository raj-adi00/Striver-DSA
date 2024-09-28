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
//TC: V+E

//Using only one array v
int main(){
     int v;vector<vector<int>> adj;
 vector<int> vis(v,0);
 
 function<bool(int)>DFS=[&](int i)->bool{
    vis[i]=1;
    bool check=false;
    for(auto val:adj[i]){
        if(vis[val]==0)
        check=check || DFS(val);
         else{
            if(vis[val]==1)
            return true;
         }
    }
    vis[i]=2;
    return check;
 };
 bool  res=false;
for(int i=0;i<v;i++){
    if(!vis[i])
    res=res || DFS(i);
}
if(res)
cout<<true<<endl;
else
cout<<false<<endl;
}

//USing two array 2*v
// int main()
// {
//  ios_base::sync_with_stdio(0), cin.tie(0);
//  int v;vector<vector<int>> adj;
//  vector<int> vis(v,0),pathVis(v,0);
//  function<bool(int)>DFS=[&](int i)->bool{
//     vis[i]=1;
//     pathVis[i]=1;
//     bool check=false;
//     for(auto val:adj[i]){
//         if(!vis[val])
//         check=check || DFS(val);
//          else{
//             if(pathVis[val]==1)
//             return true;
//          }
//     }
//     pathVis[i]=0;
//     return check;
//  };
//  bool  res=false;
// for(int i=0;i<v;i++){
//     if(!vis[i])
//     res=res || DFS(i);
// }
// if(res)
// cout<<true<<endl;
// else
// cout<<false<<endl;
// }