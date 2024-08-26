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
 int n,m;
 cin>>m>>n;
 vector<vector<int>>v (m,vector<int>(n,0));
 for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>v[i][j];
 vector<vector<int>> vis(m,vector<int>(n,0));
 queue<pii> q;
 for(int i=0;i<m;i++)for(int j=0;j<n;j++){v[i][j]==1?vis[i][j]=0:vis[i][j]=1;if(v[i][j]==2)q.push({i,j});}
 int ans=0;

 int flag=0;
 vector<int> row={0,0,1,-1},col={1,-1,0,0};
int sz=q.size();
// for(auto vec:vis)
// cout<<vec<<endl;
 function<int()>f=[&]()->int{
    flag=0;
    for(int i=0;i<sz;i++){
         int r=(q.front().first);
         int c=q.front().second;
         q.pop();
   for(int k=0;k<4;k++){
    int nrow=r+row[k];
    int ncol=c+col[k];
    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && v[nrow][ncol]==1 && !vis[nrow][ncol]){
    flag=1;
    q.push({nrow,ncol});
    vis[nrow][ncol]=1;
    }
  }
    }
    if(flag==1)
    return 1;
    return 0;
 };
//  int p=0;
while(!q.empty()){
    sz=q.size();
    ans+=f();
  // if(p==0)
  // {
  //   for(auto vec:vis)
  //   cout<<vec<<endl;
  //   p++;
  // }
}
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
{
    if(vis[i][j]!=1)
    ans=-1;
}
cout<<ans<<endl;
}