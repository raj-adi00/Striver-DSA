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
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 vector<vector<int>> v={};int c=2;


 vector<vector<int>> calc(c,vector<int>());
 int n=v.size();
 vector<int> a(c,0);
 for(int i=0;i<n;i++){
    a[v[i][0]]++;
    calc[v[i][1]].push_back(v[i][0]);
 }
 queue<int> q;
 vector<int> res;
 int cnt=0;
 for(int i=0;i<c;i++){
    if(a[i]==0){
        q.push(i);
    }
 }
//  cout<<q.front();
//  q.pop();
//  cout<<q.front();
 while(!q.empty()){
   int val=q.front();
   res.push_back(val);
   cnt++;
   q.pop();
   for(auto x:calc[val]){
    a[x]--;
    if(a[x]==0)
    q.push(x);
   }
 }
 if(cnt==c)
 cout<<res<<endl;
 else
 cout<<" "<<endl;
}