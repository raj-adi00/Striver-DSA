#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
 vector<int> dp(n+1,-1);
        function<int(int)> DP=[&](int i)->int{
         if(i>=n)
         return 0;
         if(dp[i]!=-1)
         return dp[i];
         int ans=DP(i+2)+v[i];
         ans=max(ans,DP(i+1));
         return dp[i]=ans;
        };
    cout<<DP(0);





     vector<vector<int>> dp1(n+1);
        for(int i=0;i<=n;i++)
        {
            dp1[i].push_back(-1);
             dp1[i].push_back(-1);
        }
        function<int(int,int)> D=[&](int i,int j)->int{
         if(i>=n)
         return 0;
         if(dp1[i][j]!=-1)
         return dp1[i][j];
         int ans;
         if(j==0)
         ans=max(D(i+1,1)+v[i],D(i+1,0));
         if(j==1)
         ans=D(i+1,0);
         return dp1[i][j]=ans;
        };
        cout<<D(0,0);



    for(int i=0;i<=n;i++)
    dp[i]=-1;
    function<int(int)>f=[&](int i)->int{
    if(i<0)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int ans=v[i]+f(i-2);
    ans=max(ans,f(i-1));
    return dp[i]=ans;
    };
    cout<<f(n-1);

    
    for(int i=0;i<n;i++)
    dp[i]=0;
    for(int i=0;i<n;i++)
    {
        if(i-2>=0)
        dp[i]=v[i]+dp[i-2];
        else
        dp[i]=v[i];
        if(i-1>=0)
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n-1]<<endl;

   //TC: O(N) SC:O(N)
    for(int i=0;i<n;i++)
    dp[i]=0;
    dp[0]=v[0];
    int neg=0;
    for(int i=1;i<n;i++)
    {
        int taken=v[i];
        if(i>1)taken+=dp[i-2];
        int nontaken=dp[i-1];
        dp[i]=max(taken,nontaken);
    }
    cout<<dp[n-1];


    //SPACE OPTIMIZATION
    int minus1=v[0],minus2=0;
    int curr=0;
    for(int i=1;i<n;i++)
    {
     curr=max(minus1,minus2+v[i]);
     minus2=minus1;
     minus1=curr;
    }
    cout<<minus1<<endl;
}