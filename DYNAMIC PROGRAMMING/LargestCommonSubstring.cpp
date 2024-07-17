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
{//TC without memoization:O(2^N * 2^M)   with memoization:O(N*M)
// SC without memoization:O(N+M)          with memoization:O(N*M)+O(N+M) when none elements are equal
 ios_base::sync_with_stdio(0), cin.tie(0);
 string a,b;
 cin>>a>>b;
 int l1=a.length();
 int l2=b.length();
 vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

//  function<int(int,int)>f=[&](int i,int j)->int{
//     if(i==0)
//     {
//         while(j>=0)
//         {
//             if(a[i]==b[j])
//             return 1;
//            j--;
//         }
//         return 0;
//     }
//     if(j==0)
//     {
//         while(i>=0)
//         {
//             if(a[i]==b[j])
//             return 1;
//             i--;
//         }
//         return 0;
//     }
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int ans;
//     if(a[i]==b[j])
//     ans=f(i-1,j-1)+1;
//     else{
//         int c1=f(i-1,j);
//         int c2=f(i,j-1);
//         ans=max(c1,c2);
//     }
//     return dp[i][j]=ans;
//  };
//  cout<<f(l1-1,l2-1);


// function<int(int,int)>f=[&](int i,int j)->int{
//     if(i==l1-1)
//     {
//      while(j<l2)
//      {
//         if(a[i]==b[j])
//         return 1;
//         j++;
//      }
//      return 0;
//     }
//     if(j==l2-1)
//     {
//         while(i<l1)
//         {
//             if(a[i]==b[j])
//             return 1;
//             i++;
//         }
//         return 0;
//     }
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int ans;
//     if(a[i]==b[j])
//     ans=f(i+1,j+1)+1;
//     else{
//         int c1=f(i+1,j);
//         int c2=f(i,j+1);
//         ans=max(c1,c2);
//     }
//     return dp[i][j]=ans;
// };
// cout<<f(0,0)<<endl;


// int cnt=0;
// for(int i=0;i<l2;i++)
// {
//     if(a[0]==b[i])
//     cnt=1;
//     dp[0][i]=cnt;
// }
// for(int i=1;i<l1;i++)
// {
//     for(int j=0;j<l2;j++)
//     {
//         if(a[i]!=b[j])
//         {
//         dp[i][j]=dp[i-1][j];
//         if(j>0)
//         dp[i][j]=max(dp[i][j],dp[i][j-1]);
//         }
//         else{
//         if(j>0)
//         dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
//         else
//         dp[i][j]=1;
//         }
//     }
// }
// cout<<dp[l1-1][l2-1];



//shifting of index

// for(int i=0;i<=l2;i++)
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
// cout<<dp[l1][l2]<<endl;



vector<int> arr(l2+1,0);
for(int i=1;i<=l1;i++)
{
    vector<int> temp(l2+1,0);
    for(int j=1;j<=l2;j++)
    {
        int ans;
         if(a[i-1]!=b[j-1])
        {
         ans=arr[j];
        ans=max(ans,temp[j-1]);
        }
        else{
        ans=arr[j-1]+1;
        }
        temp[j]=ans;
    }
    arr=temp;
}
cout<<arr[l2]<<endl;
}