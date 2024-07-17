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
{//TC without memoization:>O(2^n) because it is staying at same index after taking. It is not changing its index. Better to say it exponentiation
//SC: without memoization:O(N)
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//  function<int(int,int)>f=[&](int i,int l)->int{
//     if(l>n)
//     return 0;
//   if(i==n-1)
//   {
//     return (n-l)/n*v[i];
//   }
//   if(dp[i][l]!=-1)
//   return dp[i][l];
//   int lo=0;
//   if(l+i+1<=n)
//   lo=f(i,l+i+1)+v[i];
//   int r=f(i+1,l);
//   return dp[i][l]=max(lo,r);
//  };
//  cout<<f(0,0)<<endl;


dp[0][0]=0;
 for(int i=0;i<=n;i++)
 {
    if(i>=1)
    dp[0][i]=i*v[0];
 }
for(int i=1;i<n;i++)
{
    for(int j=0;j<=n;j++)
    {
        int a=dp[i-1][j];
        int b=0;
        if(j-(i+1)>=0)
        b=dp[i][j-i-1]+v[i];
        dp[i][j]=max(a,b);
    }
}
cout<<dp[n-1][n];



vector<int> arr(n+1,0);
for(int i=0;i<=n;i++)
{
    if(i>=1)
    arr[i]=i*v[0];
}
for(int i=1;i<n;i++)
{
    for(int j=0;j<=n;j++)
    {
        int a=arr[j];
        int b=0;
        if(j-(i+1)>=0)
        b=arr[j-i-1]+v[i];
        arr[j]=max(a,b);
    }
}
cout<<arr[n];
}