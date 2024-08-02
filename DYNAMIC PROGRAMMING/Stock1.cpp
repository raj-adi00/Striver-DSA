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
 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<int> sell(n),buy(n);
 buy[0]=v[0];
 for(int i=1;i<n;i++)
 buy[i]=min(buy[i-1],v[i]);
 sell[n-1]=v[n-1];
 for(int i=n-2;i>=0;i--)
 sell[i]=max(sell[i+1],v[i]);
 int ans=0;
 for(int i=0;i<n;i++){
 ans=max(ans,sell[i]-buy[i]);
 }
 cout<<ans<<endl;

//approach
 ans=0;
 int x=v[0];
 for(int i=1;i<n;i++)
 {
 ans=max(ans,v[i]-x);
 x=min(x,v[i]);
 }
 cout<<ans<<endl;
}