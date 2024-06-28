#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i].push_back(-1);
        dp[i].push_back(-1);
    }
    function<int(int, int)> DP = [&](int i, int j) -> int
    {
        if (i >= n)
            return 0;
        if (i == n - 1 && j == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans;
        if (i == 0)
            ans = DP(i + 2, 1) + v[i];
        else
            ans = DP(i + 2, j) + v[i];
        ans = max(ans, DP(i + 1, j));
        return dp[i][j] = ans;
    };
    cout << DP(0, 0) << endl;





    if (n == 1)
        {
            cout<<v[0];
            return 0;
        }
    vector<int> dp1(n + 1, -1);
    int s;
    function<int(int)> D = [&](int i) -> int
    {
        if (i >= n)
            return 0;
        if (s == 0 && i == n - 1)
            return 0;
        if (dp1[i] != -1)
            return dp1[i];
        int ans = D(i + 2) + v[i];
        ans = max(ans, D(i + 1));
        return dp1[i] = ans;
    };
    s = 0;
    int res = D(0);
    s = 1;
    for (int i = 0; i < n; i++)
        dp1[i] = -1;
    res = max(res, D(1));
    cout<< res;
}