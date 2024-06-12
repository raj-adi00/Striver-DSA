#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
vector<int> approach1(vector<int> &v,int n)
{
    ll s=0,sn=0,s2=0,s2n=0;
    sn=(n*(n+1))/2;
    s2n=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++)
    {s+=v[i];s2+=v[i]*v[i];}
    ll val1=s-sn,val2=s2-s2n;
    val2=val2/val1;
    int repeating=(val1+val2)/2;
    int missing=repeating-val1;
    return {repeating,missing};
}

vector<int> approach2(vector<int>&v,int n)
{
    int xr=0;
    for(int i=0;i<n;i++)
    xr=xr^v[i]^(i+1);
    int bitno=0;
    while(1)
    {
       if((xr&(1<<bitno))!=0)
       break;
       bitno++;
    }
    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {if((v[i]&(1<<bitno))!=0)one=one^v[i];
    else zero=zero^v[i];
    if(((i+1)&(1<<bitno))!=0)one=one^(i+1);
    else zero=zero^(i+1);}

    int cnt=0;
    for(int i=0;i<n;i++)
    (v[i]==zero)?cnt++:0;

    vector<int> temp;
    if(cnt==0)
    temp={one,zero};
    else
    temp={zero,one};
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

        // Approach 1
    // vector<int> ans=approach1(v,n);

    // Approach 2
     vector<int> ans=approach2(v,n);
    cout<<ans[0]<<endl<<ans[1];

}