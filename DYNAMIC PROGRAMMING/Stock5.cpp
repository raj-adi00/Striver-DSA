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
    cin >> n;
    vector<int> v(n);
    cin >> v;
    vector<vector<int>> dp(n+3,vector<int>(4,0));
    // for(int i=n-1;i>=0;i--)
    // {
    //     for(int j=2;j>=0;j--)
    //     {
    //         if(j==0)
    //         dp[i][j]=max(v[i]+dp[i+1][2],dp[i+1][0]);
    //         else if(j==1)
    //         dp[i][j]=max(-v[i]+dp[i+1][0],dp[i+1][1]);
    //         else
    //         dp[i][j]=dp[i+1][1];
    //     }
    // }
    // cout<<dp[0][1]<<endl;




    // for (int i = n - 1; i >= 0; i--)
    // {
    //             dp[i][0]=max(v[i]+dp[i+2][1],dp[i+1][0]);
    //             dp[i][1]=max(-1*v[i]+dp[i+1][0],dp[i+1][1]);
    // }
    // cout<<dp[0][1]<<endl;



    vector<int> t1(4,0),t2(4,0),t3(4,0);
    for (int i = n - 1; i >= 0; i--)
    {
                t1[0]=max(v[i]+t3[1],t2[0]);
                t1[1]=max(-1*v[i]+t2[0],t2[1]);
                t3=t2;
                t2=t1;
    }
    cout<<t1[1]<<endl;
}