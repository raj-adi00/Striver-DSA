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
int n;
cin>>n;
vector<int> height(n);
for(int i=0;i<n;i++)
cin>>height[i];
vector<ll> dp(n+2,-1);
function<ll(int)>f=[&](int i)->int{
    if(i>n)
    return INT_MAX;
    if(i==(n-2))
    return abs(height[n-1]-height[n-2]);
    if(i==n-1)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    ll ans=abs(height[i+1]-height[i])+f(i+1);
    ans=min(ans,abs(height[i+2]-height[i])+f(i+2));
    return dp[i]=ans;
};
cout<<f(0)<<endl;




for(int i=0;i<=n;i++)
dp[i]=0;

dp[n-1]=0;
dp[n-2]=abs(height[n-1]-height[n-2]);
for(int i=n-3;i>=0;i--)
dp[i]=min(dp[i+1]+abs(height[i+1]-height[i]),dp[i+2]+abs(height[i+2]-height[i]));
cout<<dp[0]<<endl;




for(int i=0;i<=n;i++)
dp[i]=0;
dp[0]=0;
dp[1]=abs(height[1]-height[0]);
for(int i=2;i<n;i++)
{
    dp[i]=min(dp[i-1]+abs(height[i-1]-height[i]),dp[i-2]+abs(height[i-2]-height[i]));
}
cout<<dp[n-1]<<endl;


//SPACE OPTIMIZATION:  IT is possible when we have i-1 and i-2 and bottom up....
int prev=0;
int prev2=0,curr=0;
for(int i=1;i<n;i++)
{
    int left=prev+abs(height[i]-height[i-1]);
    int right=INT_MAX;
    if(i>1)
    right=prev2+abs(height[i]-height[i-2]);
    curr=min(left,right);
    prev2=prev;
    prev=curr;
}
cout<<prev<<endl;
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
int t;
cin>>t;
while(t--)
{
solve();
}
}