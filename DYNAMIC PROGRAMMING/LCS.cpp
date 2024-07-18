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
 vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

//  for(int i=0;i<=l2;i++)
// dp[0][i]=0;
// for(int j=0;j<=l1;j++)
// dp[j][0]=0;
// for(int i=1;i<=l1;i++)
// {
//     for(int j=1;j<=l2;j++)
//     {
//          if(a[i-1]!=b[j-1])
//         {
//         dp[i][j]=dp[i-1][j];
//         dp[i][j]=max(dp[i][j],dp[i][j-1]);
//         }
//         else{
//         dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
//         }
//     }
// }
// // cout<<dp[l1][l2]<<endl;
//  string s;
//  int i=l1,j=l2;
//  while(i>0&&j>0)
//  {
//    if(a[i-1]==b[j-1])
//    {
//     s=a[i-1]+s;
//     i--;
//     j--;
//    }else{
//     if(dp[i][j]==dp[i-1][j])
//     i--;
//     else
//     j--;
//    }
//  }
//  cout<<s<<endl;



int cnt=0;
for(int i=0;i<l2;i++)
{
    if(a[0]==b[i])
    cnt=1;
    dp[0][i]=cnt;
}
for(int i=1;i<l1;i++)
{
    for(int j=0;j<l2;j++)
    {
        if(a[i]!=b[j])
        {
        dp[i][j]=dp[i-1][j];
        if(j>0)
        dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
        else{
        if(j>0)
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        else
        dp[i][j]=1;
        }
    }
}
string s(dp[l1-1][l2-1],' ');
int ind=s.length()-1;
int i=l1-1,j=l2-1;
while(i>=0 && j>=0)
{
    if(a[i]==b[j])
    {
       s[ind]=a[i];
       ind--;
        i--;
        j--;
    }
    else if(i==0 && j==0)
    break;
    else{
        if(i>0 && dp[i][j]==dp[i-1][j])
        i--;
        else
        j--;
    }
}
cout<<s<<endl;
}