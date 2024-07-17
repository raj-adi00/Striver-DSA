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
int main()//SC:O(w)+O(n*w)   TC:O(n*w) recursion with memoization
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,w;
 cin>>n>>w;
 vector<int> v(n),o(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 for(int i=0;i<n;i++)
 cin>>o[i];
//  vector<vector<int>> dp(n,vector<int>(w+1,0));
//  for(int i=0;i<=w;i++)
//  {
//     dp[0][i]=0;
//     if(i>=o[0])
//     dp[0][i]=i/o[0]*v[0];
//  }
//  for(int i=1;i<n;i++)
//  {
//     for(int j=0;j<=w;j++)
//     {
//         int ans=dp[i-1][j];
//         if(j-o[i]>=0)
//         ans=max(ans,dp[i][j-o[i]]+v[i]);
//         dp[i][j]=ans;
//     }
//  }
//  cout<<dp[n-1][w]<<endl;


 vector<int>arr(w+1,0);
 for(int i=0;i<=w;i++)
 {
    if(i>=o[0])
    arr[i]=i/o[0]*v[0];
 }
  for(int i=1;i<n;i++)
 {
    for(int j=0;j<=w;j++)
    {
        int ans=arr[j];
        if(j-o[i]>=0)
        ans=max(ans,arr[j-o[i]]+v[i]);
        arr[j]=ans;
    }
 }
 cout<<arr[w]<<endl;
}