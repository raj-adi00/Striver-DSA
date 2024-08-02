#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)       \
   for (int i = 0; i < n; i++)    \
      for (int j = 0; j < m; j++) \
   dp[i][j] = -1
#define clear1dDP(dp, n)       \
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
   vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

   /*//approach
   function<bool(int,int)>f=[&](int i,int j)->bool{
      if(j==l2)
      {
         if(i==l1)
         return true;
         else
         return false;
      }
      if(i==l1){
         while(j<l2){
           if(b[j]!='*')
           return false;
           j++;
         }
         return true;
      }
      if(dp[i][j]!=-1)
      return dp[i][j];
      bool ans=false;
      if(b[j]=='*')
      ans=(ans||f(i+1,j)||f(i,j+1));
      else if(b[j]=='?'||b[j]==a[i])
      ans=f(i+1,j+1);
      return dp[i][j]=ans;
   };
  cout<<f(0,0)<<endl;
  */

   /*//approach

   function<bool(int,int)>f=[&](int i,int j)->bool{
      if(j<0){
      if(i<0)
      return true;
      else
      return false;
      }
      if(i<0){
         while(j>=0){
           if(b[j]!='*')
           return false;
           j--;
         }
         return true;
      }
      if(dp[i][j]!=-1)
      return dp[i][j];
      bool ans=false;
      if(a[i]==b[j] || b[j]=='?')
      ans=f(i-1,j-1);
      if(b[j]=='*')
      ans=f(i-1,j)||f(i,j-1);
      return dp[i][j]=ans;
   };
   cout<<f(l1-1,l2-1);
   */

   /*//approach

   function<bool(int,int)>f=[&](int i,int j)->bool{
      if(j==0){
      if(i==0)
      return true;
      else
      return false;
      }
      if(i==0){
         while(j>=1){
           if(b[j-1]!='*')
           return false;
           j--;
         }
         return true;
      }
      if(dp[i][j]!=-1)
      return dp[i][j];
      bool ans=false;
      if(a[i-1]==b[j-1] || b[j-1]=='?')
      ans=f(i-1,j-1);
      if(b[j-1]=='*')
      ans=f(i-1,j)||f(i,j-1);
      return dp[i][j]=ans;
   };
   cout<<f(l1,l2);
   */

   dp[0][0] = true;
   for (int i = 1; i <= l1; i++)
      dp[i][0] = false;
   for (int i = 1; i <= l2; i++)
   {
      // int flag = true;
      // for (int j = 1; j <= i; j++)
      // {
      //    if (b[j - 1] != '*')
      //    {
      //       flag = false;
      //       break;
      //    }
      // }
      // dp[0][i] = flag;

      if(b[i-1]!='*')
      break;
      else
      dp[0][i]=true;
   }
   for (int i = 1; i <= l1; i++)
   {
      for (int j = 1; j <= l2; j++)
      {
         bool ans = false;
         if (a[i - 1] == b[j - 1] || b[j - 1] == '?')
            ans =dp[i-1][j-1];
         if (b[j - 1] == '*')
            ans = dp[i-1][j]||dp[i][j-1];
        dp[i][j]=ans;
      }
   }
   cout<<dp[l1][l2]<<endl;





 vector<bool> arr(l2+1),curr(l2+1);
 arr[0]=true;
   for (int i = 1; i <= l2; i++)
   {
      int flag = true;
      for (int j = 1; j <= i; j++)
      {
         if (b[j - 1] != '*')
         {
            flag = false;
            break;
         }
      }
      arr[i] = flag;
   }
  for (int i = 1; i <= l1; i++)
   {
      curr[0]=false;
      for (int j = 1; j <= l2; j++)
      {
         bool ans = false;
         if (a[i - 1] == b[j - 1] || b[j - 1] == '?')
            ans =arr[j-1];
         if (b[j - 1] == '*')
            ans = arr[j]||curr[j-1];
       curr[j]=ans;
      }
      arr=curr;
   }
   cout<<arr[l2];
}