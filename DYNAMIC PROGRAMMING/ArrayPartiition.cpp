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
#define limit 10000000
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int s = accumulate(v.begin(), v.end(), 0);
    //     vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    //     for (int i = 0; i < n; i++)
    //         dp[i][0] = true;
    //        dp[0][v[0]] = true;
    //     for (int i = 1; i < n; i++)
    //     {
    //         for (int j = 1; j <= s; j++)
    //         {
    //             bool ans = false;
    //             ans = ans || dp[i - 1][j];
    //             ans = ans || dp[i - 1][j - v[i]];
    //             dp[i][j] = ans;
    //         }
    //     }
    //     int res = 1e9;
    //     for (int i = 0; i <= s; i++)
    //     {
    //         if (dp[n - 1][i])
    //             res = min(res, abs(s - 2 * i));
    //     }
    //    cout<<res<<endl;





    // vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    // function<int(int, int)> f = [&](int i, int curr) -> int
    // {
    //     if (i == n - 1)
    //     {
    //         return min(abs(s - 2 * curr), abs(s - 2 * curr - 2 * v[i]));
    //     }
    //     if (dp[i][curr] != -1)
    //         return dp[i][curr];
    //     int ans = min(f(i + 1, curr), f(i + 1, curr + v[i]));
    //     return dp[i][curr] = ans;
    // };
    // cout << f(0, 0) << endl;
}