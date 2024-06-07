#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int subarraywithxork(vector<int> & v,int n,int target)
{
   int xr=0,cnt=0;
   map<int,int> m;
   m[xr]++;
   for(int i=0;i<n;i++)
   {
    xr=xr^v[i];
    int required=xr^target;
    cnt+=m[required];
    m[xr]++;
   }
   return cnt;
}
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,target;
 cin>>n>>target;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];

 int cnt=subarraywithxork(v,n,target);
 cout<<cnt<<endl;
}