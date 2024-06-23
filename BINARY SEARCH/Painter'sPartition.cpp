#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if(m>n)
    {cout<<-1<<endl;return 0;}
    int low=*max_element(all(v));
    int high=accumulate(all(v),0*1LL);
    auto calcpainter=[&](int maxcap){
        int painter=1,currentdone=0;
        for(int i=0;i<n;i++)
        {
           if(currentdone+v[i]>maxcap)
           {
            painter++;
            currentdone=v[i];
           }
           else
           currentdone+=v[i];
        }
        if(painter<=m)
        return true;
        else
        return false;
    };
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(calcpainter(mid))
        high=mid-1;
        else{
        low=mid+1;
    //   cout<<1<<endl;
        }
    }
    cout<<low<<endl;
}