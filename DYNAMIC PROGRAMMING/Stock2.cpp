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
    //   int ans=0;
    //   for(int i=0;i<n-1;i++){
    //     if(v[i]<v[i+1])
    //     ans+=v[i+1]-v[i];
    //   }


    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // function<int(int ,int )>f=[&](int i,int j)->int{
    //     if(i==n)
    //     return 0;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int a=0;
    //     if(j==0)
    //     a=max(v[i]+f(i+1,1),f(i+1,0));
    //     else
    //     a=max(-1*v[i]+f(i+1,0),f(i+1,1));
    //     return dp[i][j]=a;
    // };
    // //   cout<<ans<<endl;
    // cout<<f(0,1)<<endl;




    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         int a=0;
    //             if(j==0)
    //             a=max(v[i]+dp[i+1][1],dp[i+1][0]);
    //             else
    //             a=max(-1*v[i]+dp[i+1][0],dp[i+1][1]);
    //         dp[i][j]=a;
    //     }
    // }
    // cout<<dp[0][1]<<endl;



// int a=0,b=0;
// for(int i=n-1;i>=0;i--){
//     for(int j=0;j<2;j++){
//         if(j==0)
//          b=max(v[i]+a,b);
//          else
//          a=max(-1*v[i]+b,a);
//     }
// }
// cout<<a<<endl;
}