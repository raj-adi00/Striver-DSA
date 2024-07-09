/*
 *      Author: raj_adi
 *      HAPPY CODING!!!!!!!
 */
#include <bits/stdc++.h>
using namespace std;
#define pll pair<long, long>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define limit 100005
#define fi0(i, n) for (int i = 0; i < n; i++)
#define fi1(i, n) for (int i = 1; i <= n; i++)
#define fixed(n) << setprecision(n)
// TC without memoization: O(2^N)
void solve()
{
    for (int i = 0; i < 1; i++)
        ;
    int n, tar;
    cin >> n >> tar;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
    // function<int(int, int)> f = [&](int i, long long curr) -> int
    // {
    //     if (i == n - 1)
    //     {
    //         int cnt = 0;
    //         if (curr == tar)
    //             cnt++;
    //         if (curr + v[i] == tar)
    //             cnt++;
    //         return cnt;
    //     }
    //     if (curr > tar)
    //         return 0;
    //     if (dp[i][curr] != -1)
    //         return dp[i][curr];
    //     int ans = f(i + 1, curr);
    //     ans += f(i + 1, curr + v[i]);
    //     return dp[i][curr] = ans;
    // };
    // cout << f(0, 0) << endl;

    // function<int(int, int)> DP = [&](int i, int curr) -> int
    // {
    //     if (i == 0)
    //     {
    //         if (curr == 0 && v[i] == 0)
    //             return 2;
    //         if (curr == 0)
    //             return 1;
    //         if (curr == v[i])
    //             return 1;
    //         else
    //             return 0;
    //     }
    //     if (dp[i][curr] != -1)
    //         return dp[i][curr];
    //     int ans = DP(i - 1, curr);
    //     if (curr - v[i] >= 0)
    //         ans += DP(i - 1, curr - v[i]);
    //     return dp[i][curr] = ans;
    // };
    // cout << DP(n - 1, tar);

    //    dp[0][0]=1;
    //    if(v[0]<=tar)
    //    dp[0][v[0]]+=1;
    //    for(int i=1;i<n;i++)
    //    {
    //     for(int j=0;j<=tar;j++)
    //     {
    //         dp[i][j]=dp[i-1][j];
    //         if(j-v[i]>=0)
    //         dp[i][j]+=dp[i-1][j-v[i]];
    //     }
    //    }
    //    cout<<dp[n-1][tar];

    vector<int> arr(tar + 1, 0);
    arr[0] = 1;
    if (v[0] <= tar)
        arr[v[0]] += 1;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(tar+1,0);
        for (int j = 0; j <= tar; j++)
        {
           temp[j] = arr[j];
            if (j - v[i] >= 0)
                temp[j] += arr[j - v[i]];
        }
        arr=temp;
    }
    cout<<arr[tar]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
}