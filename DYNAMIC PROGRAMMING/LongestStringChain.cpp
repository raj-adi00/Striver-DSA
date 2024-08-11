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
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
/*       <<<<<CODE HERE>>>>>      */
bool cmp(string a,string b){
    if(a.length()<b.length())
    return true;
    else
    return false;
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 function<bool(string,string)>f=[&](string a,string b)->bool{
  int cnt=0;
  if(a.length()+1!=b.length())
  return false;
  int i=0,j=0;
  while(i<a.length()&& j<b.length())
  {
    if(a[i]==b[j]){i++;j++;}
    else{j++;cnt++;}
  }
  if(cnt==1||i==a.length())
  return true;
  else
  return false;
 };
 int n;
 cin>>n;
 vector<string> v(n);
 cin>>v;
 sort(all(v),cmp);
//  cout<<v<<endl;
 vector<int> dp(n+1,1);
 for(int i=1;i<n;i++)
 {
    for(int j=0;j<i;j++)
    {
      if((f(v[j],v[i]))&&(dp[j]+1>dp[i]))
      dp[i]=dp[j]+1;
    }
 }
//  cout<<dp<<endl;
 cout<<(*max_element(all(dp)));
}