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
 int n,w;
 cin>>n>>w;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<int>weight(n);
 for(int i=0;i<n;i++)
 cin>>weight[i];
 vector<vector<int>> dp(n,vector<int>(1001,-1));
//  for(int i=0;i<=w;i++)
//  {
//     if(i>=weight[0])
//     dp[0][i]=v[0];
//  }
//  for(int i=1;i<n;i++)
//  {
//     for(int j=0;j<=w;j++){
//        int l=dp[i-1][j];
//        int r=0;
//        if(j-weight[i]>=0)
//         r=dp[i-1][j-weight[i]]+v[i];
//        dp[i][j]=max(l,r);
//     }
//  }
//  cout<<dp[n-1][w];


//  function<int(int,int)>f=[&](int i,int j)->int{
//     if(j<0)
//     return 0;
//     if(i==0)
//     {
//         if(j<weight[i])
//         return 0;
//         else
//         return v[i];
//     }
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int l=f(i-1,j);
//     int r=0;
//      if(j-weight[i]>=0)
//     r=f(i-1,j-weight[i])+v[i];
//     return dp[i][j]=max(l,r);
//  };
//  cout<<f(n-1,w);

vector<int> arr(w+1,0);
 for(int i=0;i<=w;i++)
 {
    if(i>=weight[0])
    arr[i]=v[0];
 }
 for(int i=1;i<n;i++)
 {
    for(int j=w;j>=0;j--){
       int l=arr[j];
       int r=0;
       if(j-weight[i]>=0)
        r=arr[j-weight[i]]+v[i];
        arr[j]=max(l,r);
    }
 }
 cout<<arr[w];
}