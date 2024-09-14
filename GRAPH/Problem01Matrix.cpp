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
 int n,m;cin>>n>>m;
vector<vector<int>> v(n,vector<int>(m));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    cin>>v[i][j];
 }
 queue<pair<pii,int>> q;
 vector<vector<int>> res(n,vector<int>(m,-1));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    {
      if(v[i][j]==0){
        res[i][j]=0;
        q.push({{i,j},0});
      }  
    }
 }
  vector<int> row={0,0,1,-1},col={1,-1,0,0};
    while(!q.empty()){
    int r=q.front().first.first;
    int c=q.front().first.second;
    int step=q.front().second;
    q.pop();
    for(int k=0;k<4;k++){
        int nrow=r+row[k];
        int ncol=c+col[k];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && res[nrow][ncol]==-1){
           res[nrow][ncol]=step+1;
           q.push({{nrow,ncol},step+1});
        }
    }
 }
}