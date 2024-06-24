#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;

int dp[n+1];



memset(dp,-1,sizeof(dp));
function<int(int)> memoization=[&](int x)->int{
    if(x<=1)
    return x;
    if(dp[x]!=-1)
    return dp[x];
    return dp[x]=(memoization(x-1)+memoization(x-2));
};

 cout<<memoization(n)<<endl;



 memset(dp,0,sizeof(dp));
 function<int(int)> tabulation=[&](int x)->int{
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=x;i++)
  dp[i]=dp[i-1]+dp[i-2];
  return dp[n];
};

cout<<tabulation(n)<<endl;




 function<int(int)> tabulation_space_optimization=[&](int x)->int{
  int a=0,b=1;int c;
  for(int i=2;i<=x;i++)
 {
    c=b+a;
    a=b;
    b=c;
 }
  return b;
};

cout<<tabulation_space_optimization(n);
}