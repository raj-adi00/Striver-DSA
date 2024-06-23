#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
  int n,m;
 cin>>n>>m;
 vector<vector<int>> v(n);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        int x;
        cin>>x;
        v[i].push_back(x);
    }
 }
int low=INT_MAX,high=0;
 for(int i=0;i<n;i++)
 low=min(v[i][0],low);
 for(int i=0;i<n;i++)
 high=max(high,v[i][m-1]);
//  cout<<low<<" "<<high<<endl;
 function<int(int)> blackbox=[&](int target)->int{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
            cnt+=(upper_bound(all(v[i]),target)-v[i].begin());
    }
    return cnt;
 };
 int req=(m*n)/2;
 while(low<=high)
 {
    int mid=low+(high-low)/2;
    int smallerequal=blackbox(mid);
    if(smallerequal<=req)
    low=mid+1;
    else
    high=mid-1;
 }
 cout<<low<<endl;
}