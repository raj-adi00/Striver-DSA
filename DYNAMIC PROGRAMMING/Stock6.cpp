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
    int n,fee;
    cin >> n>>fee;
    vector<int> v(n);
    cin >> v;
    vector<vector<int>> dp(n+3,vector<int>(4,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(j==0)
            dp[i][j]=max(dp[i+1][0],dp[i+1][1]+v[i]-fee);
            else
            dp[i][j]=max(dp[i+1][1],dp[i+1][0]-v[i]);
        }
    }
    cout<<dp[0][1];
}