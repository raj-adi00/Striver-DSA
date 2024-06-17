#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
 long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int ans=1;
        long long int low=1;
        long long int high=x-1;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            if(mid*mid<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 long long int  x;
 cin>>x;
 cout<<floorSqrt(x);
}