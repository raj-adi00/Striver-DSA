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
 vector<vector<int>> v={{0,0,0},{1,1,0},{1,1,0}};
 int n=v.size();
 int m=v[0].size();
 vector<vector<int>> vis(n,vector<int>(m,0));
 if(v[0][0]==1)
 return -1;
 queue<pair<int,pii>> q;
 q.push({1,{0,0}});
 vis[0][0]=1;
 while(!q.empty()){
    auto pr=q.front();
    q.pop();
    int move=pr.first;
    int x=pr.second.first;
    int y=pr.second.second;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nx=x+i;
            int ny=y+j;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && v[nx][ny]==0){
            vis[nx][ny]=move+1;
            q.push({move+1,{nx,ny}});
            if(nx==n-1 && ny==n-1)
            return move+1;
            }
        }
    }
 }
 if(vis[n-1][m-1])
 return vis[n-1][m-1];
return -1;
}