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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(m + 1, -1)));
    //  function<ll(int,int,int)>DP=[&](int i,int j1,int j2)->ll{
    //     if(j1<0 || j1>=m || j2<0 ||j2>=m)
    //     return -1*1e8;
    //    if(i==(n-1))
    //    {
    //     if(j1==j2)
    //     return v[i][j1];
    //     else
    //     return v[i][j1]+v[i][j2];
    //    }
    //    if(dp[i][j1][j2]!=-1)
    //    return dp[i][j1][j2];
    //    ll ans=0;
    //    for(int dj1=-1;dj1<=1;dj1++)
    //    {
    //     for(int dj2=-1;dj2<=1;dj2++)
    //     {
    //         if(j1==j2)
    //        ans=max(ans,DP(i+1,j1+dj1,j2+dj2)+v[i][j1]);
    //        else
    //        ans=max(ans,DP(i+1,j1+dj1,j2+dj2)+v[i][j1]+v[i][j2]);
    //     }
    //    }
    //    return dp[i][j1][j2]=ans;
    //  };
    //  cout<<DP(0,0,m-1)<<endl;


    //

    if (0 == m - 1)
        dp[0][0][m - 1] = v[0][0];
    else
        dp[0][0][m - 1] = v[0][0] + v[0][m - 1];
    for (int i = 1; i < n; i++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                ll ans = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        if ((j1 + dj1) >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            ans = max(ans, dp[i - 1][j1 + dj1][j2 + dj2] + (j1 == j2 ? v[i][j1] : (v[i][j1] + v[i][j2])));
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    ll res = 0;
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
            res = max(res, dp[n - 1][j1][j2]);
    }
    cout << res << endl;







    //

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = v[n - 1][j1];
            else
                dp[n - 1][j1][j2] = v[n - 1][j1] + v[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = v[i][j1];
                        else
                            value = v[i][j1] + v[i][j2];
                        if ((j1 + dj1) >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                            value += -1e8;
                        ans = max(ans, value);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    cout << dp[0][0][m - 1] << endl;




    //
    vector<vector<ll>> arr(m+1,vector<ll>(m+1,-1));
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2)
            arr[j1][j2]=v[n-1][j1];
            else
            arr[j1][j2]=v[n-1][j1]+v[n-1][j2];
        }
    }
     for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<ll>> temp(m+1,vector<ll>(m+1,0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = v[i][j1];
                        else
                            value = v[i][j1] + v[i][j2];
                        if ((j1 + dj1) >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value += arr[j1 + dj1][j2 + dj2];
                        }
                        else
                            value += -1e8;
                        ans = max(ans, value);
                    }
                }
                temp[j1][j2] = ans;
            }
        }
        arr=temp;
    }
    cout<<arr[0][m-1]<<endl;//TC:O(n*m*m*9)  SC:O(m*m)
}