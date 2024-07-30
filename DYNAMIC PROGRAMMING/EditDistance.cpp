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
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int l1,l2;
 string a,b;
 cin>>a>>b;
 l1=a.length();
 l2=b.length();
 vector<vector<int>> dp(l1,vector<int>(l2,0));
 if(a[0]==b[0])
 dp[0][0]=0;
 else
 dp[0][0]=1;
  int cnt=dp[0][0];
 if(dp[0][0]==0)
 cnt=1;
 else
 cnt=0;
 for(int i=1;i<l2;i++)
 {
    if(b[i]==a[0])
    cnt=1;
    dp[0][i]=(i+1-cnt);
 }
 for(int i=1;i<l1;i++)
 {
    for(int j=0;j<l2;j++)
    {
        if(a[i]==b[j]){
        if(j>0)
        dp[i][j]=dp[i-1][j-1];
        else
        dp[i][j]=i;
        }
        else{
            dp[i][j]=dp[i-1][j]+1;
            if(j>0)
            dp[i][j]=min({dp[i][j],dp[i-1][j-1]+1,dp[i][j-1]+1});
        }
    }
 }
 cout<<dp[l1-1][l2-1];
 for(auto vec:dp)
 {
    for(auto val:vec)
    cout<<val<<" ";
    cout<<endl;
 }
}