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

    int dp[50];
    MINUS(dp);
    function<int(int)> f = [&](int x) -> int
    {
        if (x == n)
            return 1;
        if (x > n)
            return 0;
        if (dp[x] != -1)
            return dp[x];
        dp[x] = (f(x + 1) + f(x + 2));
        return dp[x];
    };
    cout << f(0)<<endl;



   MINUS(dp);
    function<int(int)>F=[&](int x)->int{
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=x;i++)
        dp[i]=dp[i-1]+dp[i-2];
    };
    F(n);
    cout<<dp[n]<<endl;




    MINUS(dp);
    function<int(int)>DP=[&](int x)->int{
        if(x==2)
        return 2;
        if(x==1)
        return 1;
        if(dp[x]!=-1)
        return dp[x];
        dp[x]=(DP(x-1)+DP(x-2));
        return dp[x];
    };
    cout<<DP(n);
}