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
 int n,m;
 cin>>n>>m;
 int cnt=0;
  /*
   vector<vector<pair<char,int>>> v(n,vector<pair<char,int>>(m));
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        cin>>v[i][j].first;
        if(v[i][j].first=='1'){
            v[i][j].second=(cnt++);
        }
    }
 }
 vector<vector<int>> adj(n*m+2);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        if(v[i][j].first=='1')
        {
            if(i>0)
            {
                 if(j>0){
                    if(v[i-1][j-1].first=='1')
                    {
                        adj[v[i][j].second].push_back(v[i-1][j-1].second);
                        adj[v[i-1][j-1].second].push_back(v[i][j].second);
                    }
                 }
                 if(v[i-1][j].first=='1')
                 {
                    adj[v[i][j].second].push_back(v[i-1][j].second);
                    adj[v[i-1][j].second].push_back(v[i][j].second);
                 }
                 if(j<m-1 && v[i-1][j+1].first=='1')
                 {
                    adj[v[i][j].second].push_back(v[i-1][j+1].second);
                    adj[v[i-1][j+1].second].push_back(v[i][j].second);
                 }
            }
            if(j>0){
             if(v[i][j-1].first=='1'){
                adj[v[i][j-1].second].push_back(v[i][j].second);
                adj[v[i][j].second].push_back(v[i][j-1].second);
             }   
            }
            if(j<m-1){
                if(v[i][j+1].first=='1'){
                    adj[v[i][j].second].push_back(v[i][j+1].second);
                    adj[v[i][j+1].second].push_back(v[i][j].second);
                }
            }
            if(i<n-1){
                if(j>0 && v[i+1][j-1].first=='1'){
                    adj[v[i][j].second].push_back(v[i+1][j-1].second);
                    adj[v[i+1][j-1].second].push_back(v[i][j].second);
                }
                if(v[i+1][j].first=='1')
                {
                    adj[v[i][j].second].push_back(v[i+1][j].second);
                    adj[v[i+1][j].second].push_back(v[i][j].second);
                }
                if(j<m-1 && v[i+1][j+1].first=='1')
                {
                    adj[v[i][j].second].push_back(v[i+1][j+1].second);
                    adj[v[i+1][j+1].second].push_back(v[i][j].second);
                }
            }
        }
    }
 }

  int ans=0;
  int node=cnt-1;

  vector<int> vis(node+2,0);
  function<void(int)>DFS=[&](int nd)->void{
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(!vis[it])
         DFS(it);
    }
  };
  for(int i=0;i<=node;i++)
  {
    if(!vis[i])
    {
        DFS(i);
        ans++;
    }
  }
  cout<<ans<<endl;
*/

//SC: O(N*M)+O(N*M)     TC:O(n*m)
vector<vector<char>> v(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    cin>>v[i][j];
}
vector<vector<int>> vis(n,vector<int>(m,0));
queue<pii> q;
function<void(int,int)>BFS=[&](int a,int b)->void{
q.push({a,b});
vis[a][b]=1;
while(!q.empty()){
   int row=q.front().first;
   int col=q.front().second;
    q.pop();
    for(int deltarow=-1;deltarow<=1;deltarow++){
        for(int deltacol=-1;deltacol<=1;deltacol++)
        {
            int neighbourrow=row+deltarow;
            int neigbourcol=col+deltacol;
            if(neighbourrow>=0 && neighbourrow<n && neigbourcol>=0 && neigbourcol<m && v[neighbourrow][neigbourcol]=='1' && !vis[neighbourrow][neigbourcol])
            {
                vis[neighbourrow][neigbourcol]=1;
               q.push({neighbourrow,neigbourcol});
            }
        }
    }
}
};
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        if(v[i][j]=='1'&&!vis[i][j])
        {
           BFS(i,j);
           cnt++;
        }
    }
  }
  cout<<cnt<<endl;
}