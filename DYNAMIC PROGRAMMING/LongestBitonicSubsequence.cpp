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
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;
 vector<int> v(n);
 cin>>v;
 vector<int> dp1(n+1,1),dp2(n+1,1);
 /*
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<i;j++)
    {
        if(v[j]<v[i] && dp1[i]<(1+dp1[j]))
        dp1[i]=1+dp1[j];
    }
 }
 int ans=0;
 for(int i=n-1;i>=0;i--)
 {
    for(int j=n-1;j>i;j--)
    {
        if(v[j]<v[i] && dp2[i]<(1+dp2[j]))
        dp2[i]=1+dp2[j];
    }
 }
 int cnt=0;
 for(int j=n-1;j>=0;j--)
 {
    for(int i=0;i<j;i++)
    {
        if(v[i]<v[j] && dp2[j]!=1){
        ans=max(ans,dp1[i]+dp2[j]);
        }
    }
 }
//  cout<<dp1<<endl<<dp2<<endl;
cout<<ans<<endl;
*/


for(int i=0;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        if(v[i]>v[j] && dp1[i]<(1+dp1[j]))
        dp1[i]=dp1[j]+1;
    }
}
int maxi=0;
for(int i=n-1;i>=0;i--)
{
    for(int j=n-1;j>i;j--)
    {
       if(v[i]>v[j] && dp2[i]<(1+dp2[j]))
       dp2[i]=1+dp2[j];
    }
    maxi=max(maxi,dp1[i]+dp2[i]-1);
}
cout<<maxi<<endl;
}