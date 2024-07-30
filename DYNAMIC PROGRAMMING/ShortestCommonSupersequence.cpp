#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
    dp[i][j] = -1
#define clear1dDP(dp, n)        \
    for (int i = 0; i < n; i++) \
    dp[i] = -1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int l1, l2;
    cin >> l1 >> l2;
    string a, b;
    cin >> a >> b;

    /* //approach 1
    vector<vector<int>> dp(l1, vector<int>(l2, 0));
    int cnt = 0;
    for (int i = 0; i < l2; i++)
    {
        if (a[0] == b[i])
            cnt = 1;
        dp[0][i] = (i + 1 + 1) - cnt;
    }
    for (int i = 1; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            if (a[i] == b[j])
            {
                if(j>0)
                dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                dp[i][j]=i+1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + 1;
                if (j > 0)
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
    }
    cout << dp[l1 - 1][l2 - 1]<<endl;
    int i = l1 - 1, j = l2 - 1;
    string s(dp[l1 - 1][l2 - 1], ' ');
    int ind = s.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j] && i>0 && j>0)
        {
            s[ind] = a[i];
            ind--;
            i--;
            j--;
        }
        else
        {
            if (i == 0)
            {
                if (dp[i][j] != j + 1)
                {
                    s[ind--] = a[i--];
                }
                while (j >= 0)
                {
                    s[ind--] = b[j--];
                }
            }
            else if (j == 0)
            {
                if (dp[i][j] != i + 1)
                    s[ind--] = b[j--];
                while (i >= 0)
                    s[ind--] = a[i--];
            }
            else if (dp[i][j] == dp[i - 1][j] + 1)
                s[ind--] = a[i--];
            else
                s[ind--] = b[j--];
        }
    }
    cout << s << endl;
   */


/* //approach 2
   vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
   
   int cnt=0;
   for(int i=0;i<l2;i++)
   {
    if(a[0]==b[i])
    cnt=1;
    dp[1][i+1]=cnt;
   }
   for(int i=2;i<=l1;i++)
   {
    for(int j=1;j<=l2;j++)
    {
        if(a[i-1]==b[j-1])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }else{
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
   }
   cout<<dp[l1][l2]<<endl;

   int i=l1,j=l2;
   string s(l1+l2-dp[l1][l2],' ');
   int ind=s.size()-1;
   while(i>0 && j>0){
      if(a[i-1]==b[j-1])
      {
        s[ind--]=a[i-1];
        i--;
        j--;
      }else{
        if(dp[i][j]==dp[i-1][j])
       {s[ind--]=a[i-1];i--;}
        else
        {s[ind--]=b[j-1];j--;}
      }
   }
   while(i>0)  
   {
    s[ind--]=a[i-1];
    i--;
   }
   while(j>0)
   {
    s[ind--]=b[j-1];
    j--;
   }
   cout<<s<<endl;
*/


}