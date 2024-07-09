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
//TC:O(n*sum + n)
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
  int s=accumulate(all(v),0);
  if(s%2==1)
  {
    cout<<false<<endl;
    return 0;
  }
 vector<vector<int>> dp(n+1,vector<int>(1e5,-1));
 function<bool(int,int)>f=[&](int i,int curr)->bool{
    if(curr==s-curr)
    return dp[i][curr]=true;
    if(i==n-1)
    {
        return (curr==(s-curr));
    }
    if(dp[i][curr]!=-1)
    return dp[i][curr];
    bool ans=f(i+1,curr+v[i]);
    ans=ans || f(i+1,curr);
    return dp[i][curr]=ans;
 };
 cout<<f(0,0)<<endl;





 vector<bool> arr(s/2+1);
 arr[0]=true;
 if(v[0]<=s)
 arr[v[0]]=true;
 for(int i=1;i<n;i++)
 {
    vector<bool> temp(s+1);
    for(int j=0;j<=s/2;j++)
    {
        bool ans=arr[j];
        if(j-v[i]>=0)
        ans=ans || arr[j-v[i]]; 
        temp[j]=ans;
    }
    arr=temp;
 }
 if(arr[s/2])
 cout<<true<<endl;
 else
 cout<<false<<endl;
}