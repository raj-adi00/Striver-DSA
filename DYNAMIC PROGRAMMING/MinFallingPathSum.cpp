/*
*      Author: raj_adi
*      HAPPY CODING!!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long,long>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define clear2dDP(dp,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=INT_MIN
#define mod 1000000007
#define MINUS(dp) memset(dp,INT_MIN,sizeof(dp))
#define limit 100005
#define fi0(i,n) for(int i=0;i<n;i++)
#define fi1(i,n) for(int i=1;i<=n;i++)
#define fixed(n)  << setprecision(n)
//Without memoization TC:O(N*(3^N))  SC:O(N)
void solve()
{
for(int i=0;i<1;i++);
int n;
cin>>n;
vector<vector<int>> v(n,vector<int>(n,-1));
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    cin>>v[i][j];
}
vector<vector<int>> dp(n+1,vector<int> (n+1,INT_MIN));
function<int(int,int)>f=[&](int i,int j)->int{
    if(i==n-1)
    return v[i][j];
    if(dp[i][j]!=INT_MIN)
    return dp[i][j];
    int ans=f(i+1,j)+v[i][j];
    if(j>0)
    ans=min(ans,f(i+1,j-1)+v[i][j]);
    if(j<n-1)
    ans=min(ans,f(i+1,j+1)+v[i][j]);
    return dp[i][j]=ans;  
};
int ans=f(0,0);
for(int i=1;i<n;i++)
{
  ans=min(ans,f(0,i));
}
cout<<ans<<endl;




clear2dDP(dp,n,n);
 function<int(int,int)>DP=[&](int i,int j)->int{
    if(i==0)
    return v[i][j];
    if(dp[i][j]!=INT_MIN)
    return dp[i][j];
    int val=DP(i-1,j)+v[i][j];
    if(j>0)
    val=min(val,DP(i-1,j-1)+v[i][j]);
    if(j<n-1)
    val=min(val,DP(i-1,j+1)+v[i][j]);
    return dp[i][j]=val;
};
int res=DP(n-1,0);
for(int i=1;i<n;i++)
res=min(res,DP(n-1,i));
cout<<res<<endl; //TC:o(N*N)  SC:O(N)+O(N*N)



clear2dDP(dp,n,n);
for(int i=0;i<n;i++)
dp[0][i]=v[0][i];
for(int i=1;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
         ans=dp[i-1][j]+v[i][j];
        if(j>0)
        ans=min(ans,dp[i-1][j-1]+v[i][j]);
        if(j<n-1)
        ans=min(ans,dp[i-1][j+1]+v[i][j]);
        dp[i][j]=ans;
    }
}
res=dp[n-1][0];
for(int i=1;i<n;i++)
res=min(res,dp[n-1][i]);
cout<<res<<endl;// TC:O(N*N)+O(N)   SC:O(N*N)


vector<int> arr(all(v[0]));
for(int i=1;i<n;i++)
{
    vector<int> temp(n);
    for(int j=0;j<n;j++)
    {
        ans=arr[j]+v[i][j];
        if(j>0)
        ans=min(ans,arr[j-1]+v[i][j]);
        if(j<n-1)
        ans=min(ans,arr[j+1]+v[i][j]);
       temp[j]=ans;
    }
    arr=temp;
}
cout<<(*min_element(all(arr)));
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
solve();
}

