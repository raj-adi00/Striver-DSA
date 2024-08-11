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
 vector<int> dp(n+1,1),cnt(n+1,1);
 int maxi=0;
 int ans=0;
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<i;j++)
    {
        if(v[i]>v[j]&& dp[i]<1+dp[j])
        {
            dp[i]=1+dp[j];
            cnt[i]=cnt[j];
        }
        else if(v[i]>v[j]&& dp[j]+1==dp[i])
        {
            cnt[i]+=cnt[j];
        }
    }
     maxi=max(maxi,dp[i]);
 }
 for(int i=0;i<n;i++)
 {
    if(dp[i]==maxi)
    ans+=cnt[i];
 }
 cout<<ans<<endl;
}