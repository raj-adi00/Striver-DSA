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
 int n,a;
 cin>>n>>a;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
  vector<int> dp(a+1,0);

//   function<int(int)>f=[&](int i)->int{
//     if(i>a)
//     return 1e9;
//     if(i==a)
//     return 0;
//     if(dp[i]!=-1)
//     return dp[i];
//     int ans=1e9;
//     for(int j=0;j<n;j++)
//     {
//      if(v[j]!=0)
//     ans=min(ans,f(i+v[j])+1);
//     }
//     return dp[i]=ans;
//   };
//   if(f(0)!=1e9)
//   cout<<f(0)<<endl;
//   else
//   cout<<-1<<endl;




// dp[0]=0;
// for(int i=0;i<n;i++)
// {
// if(v[i]<=a)
// dp[v[i]]=1;
// }
// for(int i=1;i<=a;i++)
// {
//     int ans=1e9;
//     for(int j=0;j<n;j++)
//     {
//         if(i-v[j]>=0 && v[j]!=0)
//       ans=min(ans,dp[i-v[j]]+1);
//     }
//     if(ans!=1e9)
//     dp[i]=ans;
// }
// cout<<dp[a]<<endl;


vector<vector<int>>rec (n,vector<int>(a+1,0));
// function<int(int,int)>f=[&](int i,int j)->int{
//     if(j==0)
//     return 0;
//     if(i==0)
//     {
//         if(j%v[i]==0)
//         return j/v[i];
//         else
//         return 1e9;
//     }
//     if(rec[i][j]!=-1)
//     return rec[i][j];
//     ll l=f(i-1,j);
//     ll r=1e9;
//     if(j-v[i]>=0)
//     r=f(i,j-v[i])+1;
//     return rec[i][j]=min(l,r);
// };
// cout<<f(n-1,a);


rec[0][0]=0;
for(int i=0;i<=a;i++)
{
    if(i%v[0]==0)
    rec[0][i]=i/v[0];
    else
    rec[0][i]=1e9;
}
for(int i=1;i<n;i++)
{
    for(int j=0;j<=a;j++)
    {
        int ans=rec[i-1][j];
        if(j-v[i]>=0)
        {
        ans=min(ans,rec[i][j-v[i]]+1);
        }
        rec[i][j]=ans;
    }
}
cout<<rec[n-1][a];
}