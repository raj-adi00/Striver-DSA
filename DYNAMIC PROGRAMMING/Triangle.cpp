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
// Without memoization: TC:O(2^(1+2+....n))  basically it is (no. of transition^(no. of elements))
                        //SC:O(N)
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;
 vector<vector<int>> v(n,vector<int>(n,INT_MIN));
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<=i;j++)
    cin>>v[i][j];
 }
 vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
 function<int(int,int)>f=[&](int i,int j)->int{
   if(i>=n || j>=n)
   return 0;
   if(v[i][j]==INT_MIN)
   return INT_MAX;
   if(dp[i][j]!=-1)
   return dp[i][j];
   int ans=v[i][j]+f(i+1,j);
   ans=min(ans,v[i][j]+f(i+1,j+1));
   return dp[i][j]=ans;
 };
 cout<<f(0,0)<<endl; //TC:O(N*N) SC:O(N)+O(N*N)



 clear2dDP(dp,n,n);
 dp[0][0]=v[0][0];
 for(int i=1;i<n;i++)
 {
    for(int j=0;j<=i;j++)
    {
        long long ans=INT_MAX;
        if(j!=i)
       ans=dp[i-1][j]+v[i][j];
      if(j>0)
      ans=min(ans,v[i][j]+dp[i-1][j-1]);
      dp[i][j]=ans;
    }
 }
 long long ans=dp[n-1][0];
 for(int i=0;i<n;i++)
 ans=min(ans,dp[n-1][i]);
cout<<ans<<endl;



clear2dDP(dp,n,n);
for(int i=0;i<n;i++)
dp[n-1][i]=v[n-1][i];
for(int i=n-2;i>=0;i--)
{
    for(int j=0;j<=i;j++)
    {
        long long ans;
        ans=dp[i+1][j]+v[i][j];
        ans=min(ans,dp[i+1][j+1]+v[i][j]);
        dp[i][j]=ans;
    }
}
cout<<dp[0][0]<<endl;//TC:O(N*N)  SC:O(N*N)



vector<ll> arr(n);
for(int i=0;i<n;i++)
arr[i]=v[n-1][i];
for(int i=n-2;i>=0;i--)
{
    vector<ll> temp(n);
    for(int j=0;j<=i;j++)
    {
       long long ans=arr[j]+v[i][j];
       ans=min(ans,arr[j+1]+v[i][j]);
       temp[j]=ans;
    }
    arr=temp;
}
cout<<arr[0]<<endl;  //TC:O(N*N)   SC:O(2*N)
}