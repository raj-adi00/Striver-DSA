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
int main()//TC with memoization:O(N*target)    SC after memoization:o(N*target)+o(target)  without memoization: TC>O(2^n)
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,tar;
 cin>>n>>tar;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<vector<int>> dp(n,vector<int> (tar+1,-1));
//  for(int i=0;i<=tar;i++){
//     if(i%v[0]==0)
//     dp[0][i]++;
//  }
//  for(int i=1;i<n;i++){
//    for(int j=0;j<=tar;j++)
//    {
//     dp[i][j]=dp[i-1][j];
//     if(j-v[i]>=0)
//     dp[i][j]+=dp[i][j-v[i]];
//    }
//  }
//  cout<<dp[n-1][tar]<<endl;



function<int(int,int)>f=[&](int i,int j)->int{
    if(i==0)
    {
       if(j%v[i]==0)
       return 1;
       else
       return 0;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int l=f(i-1,j);
    int r=0;
    if(j-v[i]>=0)
    r=f(i,j-v[i]);
    return dp[i][j]=(l+r);
};
cout<<f(n-1,tar);
}