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
//Without memoization: TC:O(2^N)  SC:O(N)
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,s;
 cin>>n>>s;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<vector<int>>dp(n+1,vector<int>(s+1,0));
//  function<bool(int,int)>DP=[&](int i,ll j)->bool{
//      if(j==0)
//     return true;
//     if(i==n)
//     return 0;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     bool ans=DP(i+1,j);
//     if(j-v[i]>=0)
//     ans=ans || DP(i+1,j-v[i]);
//     return dp[i][j]=ans;
//  };
//  if(DP(0,s))
//  cout<<true<<endl;
//  else
// cout<<false<<endl;



// clear2dDP(dp,n,s);
// function<bool(int,int)>f=[&](int i,int j)->bool{
//     if(j==0)
//     return true;
//     if(i==0)
//     return v[0]==j;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     bool ans=f(i-1,j);
//     if(j-v[i]>=0)
//     ans=ans || f(i-1,j-v[i]);
//     return dp[i][j]=ans;
// };
// if(f(n,s))
// cout<<true<<endl;
// else
// cout<<false<<endl; //TC:O(N*S) SC:O(N*S)+O(N)


// dp[0][0]=1;
// if(v[0]<=s)
// dp[0][v[0]]=1;
// for(int i=1;i<n;i++)
// {
//     for(int j=0;j<=s;j++)
//     {
//        bool ans=dp[i-1][j];
//        if(j-v[i]>=0)
//        ans=ans+dp[i-1][j-v[i]];
//        dp[i][j]=ans;
//     }
// }
// if(dp[n-1][s])
// cout<<true;
// else
// cout<<false;


//  vector<vector<bool>>res(n+1,vector<bool>(s+1,0));
//  res[0][0]=true;
//  if(v[0]<=s)
//  res[0][v[0]]=true;
//  for(int i=1;i<n;i++)
//  {
//     for(int j=0;j<=s;j++)
//     {
//         bool ans=res[i-1][j];
//         if(j-v[i]>=0)
//         ans=ans||res[i-1][j-v[i]];
//         res[i][j]=ans;
//     }
//  }
//  if(res[n-1][s])
//  cout<<true;
//  else
//  cout<<false;



 vector<bool> arr(s+1);
 arr[0]=true;
 if(v[0]<=s)
 arr[v[0]]=true;
 for(int i=1;i<n;i++)
 {
    vector<bool> temp(s+1);
    for(int j=0;j<=s;j++)
    {
        bool ans=arr[j];
        if(j-v[i]>=0)
        ans=ans || arr[j-v[i]];
        temp[j]=ans;
    }
    arr=temp;
 }
 if(arr[s])
 cout<<true<<endl;
 else
 cout<<false<<endl;
}