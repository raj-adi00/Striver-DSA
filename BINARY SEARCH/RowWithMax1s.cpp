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
 int cntmax=-1;
 int ind=-1;
 for(int i=0;i<n;i++)
 {
    auto it=lower_bound(all(v[i]),1)-v[i].begin();
    if(it==n)
    continue;
    else{
        if(cntmax<(m-it))
        {
            cntmax=m-it;
            ind =i;
        }
    }
 }
 cout<<ind<<endl;
}