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
 int n;
 cin>>n;
 vector<int> v(n);
 cin>>v;
 vector<vector<int>> dp(n+1,vector<int>(n+3,0));
//  function<int(int,int)>f=[&](int i,int j)->int{
//     if(i==n-1)
//     {
//         if(j==-1)
//         return 1;
//         if(v[i]>v[j])
//         return 1;
//         else
//         return 0;
//     }
//     if(dp[i][j+1]!=INT_MIN)
//     return dp[i][j+1];
//     int a=f(i+1,j);
//     if(j==-1||v[i]>v[j])
//     a=max(a,f(i+1,i)+1);
//     return dp[i][j+1]=a;
//  };
//  cout<<f(0,-1);



// vector<vector<int>> dp(n+2,vector<int>(n+2,INT_MIN));
//  function<int(int,int)>f=[&](int i,int j)->int{
//    if(i==n-1)
//     {
//         if(j==0)
//         return 1;
//         if(v[i]>v[j-1])
//         return 1;
//         else
//         return 0;
//     }
//     if(dp[i][j]!=INT_MIN)
//     return dp[i][j];
//     int a=f(i+1,j);
//     if(j==0||v[i]>v[j-1])
//     a=max(a,f(i+1,i+1)+1);
//     return dp[i][j]=a;
//  };
//  return f(0,0);



// dp[n-1][0]=1;
// for(int i=1;i<=n-1;i++)
// {
//     if(v[i-1]<v[n-1])
//     dp[n-1][i]=1;
//     else
//     dp[n-1][i]=0;
// }
// for(int i=n-2;i>=0;i--)
// {
//     for(int j=n-1;j>=0;j--)
//     {
//         int a=dp[i+1][j];
//         if(j==0||v[i]>v[j-1])
//         a=max(a,dp[i+1][i+1]+1);
//         dp[i][j]=a;
//     }
// }
// cout<<dp[0][0];



// vector<int> curr(n+4),temp(n+4);
// curr[0]=1;
// for(int i=1;i<=n;i++)
// {
//     if(v[i-1]<v[n-1])
//     curr[i]=1;
//     else
//     curr[i]=0;
// }
// for(int i=n-2;i>=0;i--)
// {
//     for(int j=n-1;j>=0;j--)
//     {
//         int a=curr[j];
//         if(j==0 || v[i]>v[j-1])
//         a=max(a,curr[i+1]+1);
//         temp[j]=a;
//     }
//     curr=temp;
// }
// cout<<curr[0];



vector<int> arr(n,1),hashing(n);
//hashing helps to store the elements of longest increasing subsequence
int maxi=0;
int lastindex=-1;
for(int i=0;i<n;i++)
hashing[i]=i;
for(int i=0;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        if(v[j]<v[i])
        {
            if(arr[i]<1+arr[j])
            {
                arr[i]=1+arr[j];
                hashing[i]=j;
            }
        }
    }
    if(arr[i]>maxi)
    {
       lastindex=i;
       maxi=arr[i];
    }
}

vector<int> lis(maxi);
lis[maxi-1]=v[lastindex];
int ind=maxi-2;
cout<<maxi<<endl;

//DISPLAY THE LIS
while(hashing[lastindex]!=lastindex)
{
    lastindex=hashing[lastindex];
    lis[ind--]=v[lastindex];
}
cout<<lis;





//LIS using Binary search
vector<int> res;
res.push_back(v[0]);
for(int i=1;i<n;i++)
{
    if(v[i]>res.back())
    res.push_back(v[i]);
    else{
        auto it=lower_bound(all(res),v[i])-res.begin();
        res[it]=v[i];
    }
}
cout<<res.size();
}