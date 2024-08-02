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
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
        out << x << ' ';
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    // vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(2, vector<int>(3, 0)));
    //  function<int(int,int,int)>f=[&](int i,int j,int k)->int{
    //     if(i==n)
    //     return 0;
    //     if(k==2)
    //     return 0;
    //     if(dp[i][j][k]!=-1)
    //     return dp[i][j][k];
    //     int a=0;
    //     if(j==0)
    //     a=max(v[i]+f(i+1,1,k+1),f(i+1,0,k));
    //     else
    //     a=max(-1*v[i]+f(i+1,0,k),f(i+1,1,k));
    //     return dp[i][j][k]=a;
    //  };
    //  cout<<f(0,1,0)<<endl;



    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j <=1; j++)
    //     {
    //         for (int k = 1; k <=2; k++)
    //         {
    //             if (j == 1)
    //                 dp[i][j][k] = max(-v[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
    //             else
    //                 dp[i][j][k] = max(v[i] + dp[i + 1][1][k-1], dp[i + 1][0][k]);
    //         }
    //     }
    // }
    // cout << dp[0][1][2];



    // for(int i=n-1;i>=0;i--)
    // {
    //     for(int j=0;j<=1;j++){
    //         for(int k=1;k>=0;k--){
    //             if(j==0)
    //             dp[i][j][k]=max(v[i]+dp[i+1][1][k+1],dp[i+1][0][k]);
    //             else
    //             dp[i][j][k]=max(-v[i]+dp[i+1][0][k],dp[i+1][1][k]);
    //         }
    //     }
    // }
    // cout<<dp[0][1][0];



    // vector<vector<int>> curr(3,vector<int>(3,0)),temp(3,vector<int>(3,0));
    // for(int i=n-1;i>=0;i--)
    // {
    //     for(int j=0;j<=1;j++){
    //         for(int k=1;k>=0;k--){
    //             if(j==0)
    //             temp[j][k]=max(v[i]+curr[1][k+1],curr[0][k]);
    //             else
    //             temp[j][k]=max(-v[i]+curr[0][k],curr[1][k]);
    //         }
    //         curr=temp;
    //     }
    // }
    // cout<<curr[1][0];



    vector<vector<int>> dp(n+2,vector<int>(5,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
          if(j%2==1)  
          dp[i][j]=max(dp[i+1][j+1]+v[i],dp[i+1][j]);
          else
          dp[i][j]=max(-v[i]+dp[i+1][j+1],dp[i+1][j]);
        }
    }
   cout<<dp[0][0]<<endl;
}