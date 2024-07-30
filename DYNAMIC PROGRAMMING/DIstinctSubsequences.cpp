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
    string a, b;
    cin >> a >> b;
    int l1 = a.length();
    int l2 = b.length();
    vector<vector<ll>> dp(l1 + 1, vector<ll>(l2 + 1, -1));

    //  cout<<l1<<endl<<l2<<endl;
    /*
    for (int i = 0; i <= l1; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[l1][l2];
*/



/*
    int cnt = 0;
    if (a[0] == b[0])
        dp[0][0] = 1;
    for (int j = 0; j < l1; j++)
    {
        if (a[j] == b[0])
            cnt++;
        dp[j][0] = cnt;
    }

    for (int i = 1; i < l1; i++)
    {
        for (int j = 1; j < l2; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
*/
vector<int> pre(l2+1,0);
// pre[0]=1;
pre[0]=1;
for(int i=1;i<=l1;i++)
{
    vector<int> curr(l2+1,1);
    for(int j=1;j<=l2;j++)
    {
        if(a[i-1]==b[j-1])
        curr[j]=pre[j]+pre[j-1];
        else
        curr[j]=pre[j];
    }
    pre=curr;
}
cout<<pre[l2];




vector<int> v(l2+1,0);
v[0]=1;
for(int i=1;i<=l1;i++)
{
    for(int j=l2;j>=1;j--)
    {
        if(a[i-1]==b[j-1])
        v[j]=v[j]+v[j-1];
        else
        v[j]=v[j];
    }
}
cout<<v[l2];
}