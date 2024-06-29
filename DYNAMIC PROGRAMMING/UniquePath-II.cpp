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
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
  int m,n;
 cin>>n>>m;
 vector<vector<int>> v(n,vector<int> (m,0));
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    cin>>v[i][j];
 }
vector<vector<int>>dp(n,vector<int>(m,-1));
 function<int(int,int)>f=[&](int i,int j)->int{
    if(i>=n || j>=m)
    return 0;
    if(v[i][j]==1)
    return 0;
    if(i==n-1 && j==m-1)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int l=f(i+1,j);
    int r=f(i,j+1);
    return dp[i][j]=(l+r);
 };
 cout<<f(0,0)<<endl;




 clear2dDP(dp,n,m);
 function<int (int i,int j)>DP=[&](int i,int j)->int{
    if(i<0 ||j<0)
    return 0;
    if(v[i][j]==1)
    return 0;
    if(i==0 && j==0)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int l=DP(i-1,j);
    int r=DP(i,j-1);
    return dp[i][j]=(l+r);
 };
 cout<<DP(n-1,m-1)<<endl;




 clear2dDP(dp,n,m);
 if(v[0][0]==0)
 dp[0][0]=1;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(i==0 && j==0)
        continue;
        dp[i][j]=0;
        if(v[i][j]==1)
        continue;
        int up=0,left=0;
        if(j>0)
        left=dp[i][j-1];
        if(i>0)
        up=dp[i-1][j];
        dp[i][j]=up+left;
    }
}
cout<<dp[n-1][m-1]<<endl;
}