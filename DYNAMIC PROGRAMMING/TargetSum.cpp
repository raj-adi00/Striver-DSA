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
{//MEMOIZATION TECHNIQUE FOR NEGATIVE NUMBER HAS BEEN DEALT HERE........
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, tar;
    cin >> n >> tar;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int s = accumulate(v.begin(), v.end(), 0);
    if ((s + tar) % 2 != 0)
    {
        // cout<<0<<endl;
        return 0;
    }
    tar = (s + tar) / 2;
    map<pair<int, int>, int> m;
    m[{0, 0}] = 1;
    m[{0, v[0]}] += 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            m[{i, j}] = m[{i - 1, j}];
            if (j - v[i] >= 0)
                m[{i, j}] += m[{i - 1, j - v[i]}];
        }
    }
    return m[{n - 1, tar}];
}