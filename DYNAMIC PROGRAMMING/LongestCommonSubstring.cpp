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
 string a,b;
 cin>>a>>b;
 int l1=a.length();
 int l2=b.length();
// vector<vector<int>> dp(l1,vector<int>(l2,0));
// for(int i=0;i<l1;i++)
// {
//     for(int j=0;j<l2;j++)
//     {
//         if(a[i]==b[j])
//         {
//             if(i>0&&j>0)
//             dp[i][j]=dp[i-1][j-1]+1;
//             else
//             dp[i][j]=1;
//         }
//     }
// }
// int mx=0;
// for(int i=0;i<l1;i++)
// {
//     mx=max(mx,*max_element(all(dp[i])));
// }
// cout<<mx<<endl;

vector<int> arr(l2,0);
int cnt=0;
for(int i=0;i<l2;i++)
{
    if(a[0]==b[i])
    {
    arr[i]++;
    cnt=1;
    }
}
for(int i=1;i<l1;i++)
{
    vector<int> curr(l2,0);
    for(int j=0;j<l2;j++)
    {
       if(a[i]==b[j])
       {
        if(j!=0)
        {
        curr[j]=arr[j-1]+1;
         cnt=max(cnt,curr[j]);
        }else
        {
        curr[j]=1;
        cnt=max(cnt,1);
        }
       }
    }
    arr=curr;
}
cout<<cnt<<endl;
}