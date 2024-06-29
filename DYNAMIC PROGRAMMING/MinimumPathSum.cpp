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
 vector<vector<int>> dp(n,vector<int>(m,-1));
 function<int(int,int)>DP=[&](int i,int j)->int{
    if(i>=n||j>=m)
    return INT_MAX;
    if(i==n-1 && j==m-1)
    return v[n-1][m-1];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=INT_MAX;
    if(i<n-1)
    ans=min(ans,DP(i+1,j)+v[i][j]);
    if(j<m-1)
    ans=min(ans,DP(i,j+1)+v[i][j]);
    return dp[i][j]=ans;
 };
 cout<<DP(0,0)<<endl;  //TC: O(N*M)  SC:O(N-1+M-1+N*M)



 clear2dDP(dp,n,m);
 function<ll(int i,int j)>f=[&](int i,int j)->ll{
    if(i<0||j<0)
    return INT_MAX;
    if(i==0 && j==0)
    return v[0][0];
    if(dp[i][j]!=-1)
    return dp[i][j];
    long long ans=INT_MAX;
    if(i>0)
    ans=min(ans,f(i-1,j)+v[i][j]);
    if(j>0)
    ans=min(ans,f(i,j-1)+v[i][j]);
    return dp[i][j]=ans;
 };
 cout<<f(n-1,m-1)<<endl;



 clear2dDP(dp,n,m);
 dp[0][0]=v[0][0];
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        if(i==0 && j==0)
        continue;
      ll ans=INT_MAX;
           if(i>0)
          ans=min(dp[i-1][j]+v[i][j]*1LL,ans);     
          if(j>0)
          ans=min(ans,dp[i][j-1]+v[i][j]*1LL);
          dp[i][j]=ans;
    }
 }
 cout<<dp[n-1][m-1]<<endl;  //TC:O(N*M)   SC:O(N*M)



 vector<int> arr(m,0);
 for(int i=0;i<n;i++)
 {
    vector<int> temp(m,0);
    for(int j=0;j<m;j++)
    {
        if(i==0&& j==0)
        {
            temp[j]=v[0][0];
            continue;
        }
        int ans=INT_MAX;
       if(i>0)
        ans=min(v[i][j]+arr[j],ans);
       if(j>0)
       ans=min(v[i][j]+temp[j-1],ans);
       temp[j]=ans;
    }
    for(int j=0;j<m;j++)
    arr[j]=temp[j];
 }
 cout<<arr[m-1]<<endl;
}