#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define fi0(i,n) for(int i=0;i<n;i++)
#define fi1(i,n) for(int i=1;i<=n;i++)
void solve()
{
  int n,c;
  cin>>n>>c;
  vector<int> v(n);
  fi0(i,n)cin>>v[i];
  sort(all(v));
  int low=1;
  int high=v[n-1]-v[0];
  auto ispossible=[&](int mindis){
      int ncows=1,coord=v[0];
      for(int i=1;i<n;i++)
       {
        if(v[i]-coord>=mindis)
        {
            ncows++;
            coord=v[i];
            if(ncows>=c)
            return true;
        }
       }
       return false;
  };
  while(low<=high)
  {
      int mid=low+(high-low)/2;
      if(ispossible(mid))
      low=mid+1;
      else
      high=mid-1;
  }
  cout<<high<<endl;
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
int t;
cin>>t;
while(t--)
{
solve();
}
}