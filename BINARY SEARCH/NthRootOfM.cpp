#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int f(long long mid,int n,int m)
	{
	    long long res=1;
	    for(int i=1;i<=n;i++)
	    {
	        res=res*mid;
	        if(res>m)
	        return 2;
	    }
	    if(res==m)
	    return 1;
	    else
	    return 0;
	}
int checkpow(long long mid,int n,int m)
{
    ll res=1;
    while(n)
    {
        if(n%2==0)
        {
            mid*=mid;
            n/=2;
            if(mid>m)
            return 2;
        }
        else{
            n--;
            res*=mid;
            if(res>m)
            return 2;
        }
    }
    if(res==m)
    return 1;
    else if(res<m)
    return 0;
    else
    return 2;
}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long low=1;
	    long long high=m;
	    long long ans=1;
	    while(low<=high)
	    {
	        long long mid=(low+high)/2;
	        int getpowres=checkpow(mid,n,m);
	        if(getpowres==1)
	        return mid;
	        else if(getpowres==2)
	        high=mid-1;
	        else
	        low=mid+1;
	    }
	    return -1;
	}  
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,m;
 cin>>n>>m;
 cout<<NthRoot(n,m);
}