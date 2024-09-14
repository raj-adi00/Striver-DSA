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
 vector<vector<int>> v;
 int n=v.size(),m=v[0].size();

vector<vector<int>> vis(n,vector<int>(m,0));
vector<int> row={-1,1,0,0},col={0,0,1,-1};
int cnt=0;
 function<void(int r,int c)>DFS=[&](int r,int c)->void{
    vis[r][c]=1;
    cnt++;
    for(int k=0;k<4;k++)
    {
        int nrow=r+row[k];
        int ncol=c+col[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]&& v[nrow][ncol]==1)
        DFS(nrow,ncol);
    }
 };
 int tot=0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]==1)
        tot++;
        if(v[i][j]==1 && (i==0||i==(n-1)|| j==0|| j==(m-1)) && !vis[i][j])
        DFS(i,j);
    }
 }
 cout<<tot-cnt<<endl;
}