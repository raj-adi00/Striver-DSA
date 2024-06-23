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

        //*******
    auto approach1=[&](){
    vector<int> howmany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1 ;i++)
    pq.push({v[i+1]-v[i],i});
    for(int i=1;i<=m;i++)
    {
        auto tp=pq.top();pq.pop();
        int ind=tp.second;
        howmany[ind]++;
        long double initdiff=(v[ind+1]-v[ind]);
        long double newdiff=initdiff/((long double)howmany[ind]+1);
        pq.push({newdiff,ind});
    }
    cout<<pq.top().first<<endl;
    };
    approach1();




    //*****
    auto check=[&](double maxdis){
        int allowed=0;
        for(int i=0;i<n-1;i++)
        {
            int possible=(v[i+1]-v[i])/maxdis;
            allowed+=possible;
            if((v[i+1]-v[i])==possible*maxdis)
            allowed--;
        }
       if(allowed>m)
       return false;
       else
       return true;
    };
    auto approach2=[&](){
         double high=0;
         double low=0;
        for(int i=0;i<n-1;i++)
        high=max(1.0*(v[i+1]-v[i]),high);
        double ans=high;
        while(high-low>=1e-6)
        {
            double mid=(low+high)/2;
            auto res=check(mid);
           if(!res)
           low=mid;
           else
           {
            high=mid;
            ans=mid;
           }
        }
        cout<<ans<<endl;
    };
    approach2();
}