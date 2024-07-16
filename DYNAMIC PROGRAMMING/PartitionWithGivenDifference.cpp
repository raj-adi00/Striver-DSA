#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
    dp[i][j] = -1
#define clear1dDP(dp, n)        \
    for (int i = 0; i < n; i++) \
    dp[i] = -1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(2501, 0));
    int s = accumulate(all(v), 0);

    // function<int(int, int)> f = [&](int i, int j) -> int
    // {
    //     if (i == 0)
    //     {
    //         int cnt = 0;
    //         int s1 = j + v[i];
    //         int s2 = s - s1;
    //         if (s1 - s2 == d)
    //             cnt++;
    //         if (j - (s - j) == d)
    //             cnt++;
    //         return cnt;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     ll l = f(i - 1, j) % mod;
    //     ll r = f(i - 1, j + v[i]) % mod;
    //     return dp[i][j] = (l + r) % mod;
    // };
    // cout << f(n - 1, 0);

    // function<int(int, int)> DP = [&](int i, int j) -> int
    // {
    //     if (i == 0)
    //     {
    //         int cnt = 0;
    //         int s1 = j - v[i];
    //         int s2 = s - s1;
    //         if (s1 - s2 == d)
    //             cnt++;
    //         if (2 * j - s == d)
    //             cnt++;
    //         return cnt;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     ll l = DP(i - 1, j) % mod;
    //     ll r = 0;
    //     if (j - v[i] >= 0)
    //         r = DP(i - 1, j - v[i]) % mod;
    //     return dp[i][j] = (l + r) % mod;
    // };
    // cout << DP(n - 1, s);

    if((d+s)%2==1)
    {
        cout<<0<<endl;
    }
    ll tar=(d+s)/2;
    dp[0][0]=1;
    dp[0][v[0]]+=1; 
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-v[i]>=0)
            dp[i][j]=(dp[i][j]+dp[i-1][j-v[i]])%mod;
        }
    }
    cout<<dp[n-1][tar];
}