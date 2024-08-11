#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1
#define clear1dDP(dp,n) for(int i=0;i<n;i++) dp[i]=-1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define mod 1000000007
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
 int n;
 cin>>n;
 vector<int> v(n);
 cin>>v;
        sort(v.begin(), v.end());
        vector<int> dp(n + 2, 1);
        vector<int> hash(n + 3);
        for (int i = 0; i < n; i++)
            hash[i] = i;
        int maxi = 0, lastind = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((v[i] % v[j] == 0)) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                lastind = i;
            }
        }
        int ind = maxi - 1;
        vector<int> lds(maxi);
        lds[ind--] = v[lastind];
        lastind = hash[lastind];
        maxi--;
        while (maxi--) {
            lds[ind--] = v[lastind];
            lastind = hash[lastind];
        }
        cout<<lds<<endl;
}