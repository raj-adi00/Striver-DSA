/*
*      Author: raj_adi
*      HAPPY CODING!!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long,long>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define limit 100005
#define fi0(i,n) for(int i=0;i<n;i++)
#define fi1(i,n) for(int i=1;i<=n;i++)
void solve()
{
int n,k;
cin>>n>>k;
vector<int> height(n+1);
for(int i=1;i<=n;i++)
   cin>>height[i];
   vector<ll> dp(n+2,-1);
function<ll(int)>f=[&](int i)->ll{
    if(i>n)
    return INT_MAX;
    if(i==n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    ll ans=f(i+1)+abs(height[i+1]-height[i]);
    for(int j=2;j<=k;j++)
    {
      ans=min(ans,f(i+j)+abs(height[i]-height[i+j]));
    }
   return dp[i]=ans;
};
cout<<f(1)<<endl;//SC: O(N)+O(N)



for(int i=0;i<=n;i++)
dp[i]=0;
dp[n]=0;
for(int i=n-1;i>=1;i--)
{
ll ans=INT_MAX;
   for(int j=1;j<=k;j++)
   {
    if(i+j<=n)
   ans=min(ans,dp[i+j]+abs(height[i]-height[i+j]));
   }
   dp[i]=ans;
}
cout<<dp[1]<<endl; //SC: O(N)    can be optimized to O(K)



for(int i=0;i<=n;i++)
dp[i]=0;
dp[1]=0;
for(int i=2;i<=n;i++)
{
   ll ans=INT_MAX;
   for(int j=1;j<=k;j++)
   {
   if(i-j>=1)
   ans=min(ans,dp[i-j]+abs(height[i]-height[i-j]));
   }
   dp[i]=ans;
}
cout<<dp[n]<<endl;


vector<int> kvariable(k+1,0);
for(int i=2;i<=n;i++)
{
ll ans=INT_MAX;
for(int j=1;j<=k;j++)
{
   if(i-j>=1)
   ans=min(ans,1LL*kvariable[k-j+1]+abs(height[i]-height[i-j]));
}
for(int j=1;j<k;j++)
kvariable[j]=kvariable[j+1];
kvariable[k]=ans;
}
cout<<kvariable[k]<<endl;
}
//TC :O(N*K)   O(State*number of transition)
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
solve();

}