/*
*      Author: raj_adi
*      HAPPY CODING!!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long,long>
#define ll long long
#define int long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define MINUS(dp) memset(dp,-1,sizeof(dp))
#define limit 100005
#define fixed(n)  << setprecision(n)
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }


class SegmentTree{
    public:
    vector<int> seg;
    SegmentTree(int n){
        seg.resize(4*n+1);
    }
void build(int ind,int low,int high,vector<int>& arr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r){
    //NO overlap
    if(r<low || high<l)
    return 0;
    //complete overlap
    if(low>=l && high<=r)
    return seg[ind];
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return left+right;
}

void update(int ind,int low,int high,int index){
    if(low==high){
        seg[ind]=0;
        return;
    }
   int mid=(low+high)/2;
   if(index<=mid)
   update(2*ind+1,low,mid,index);
   else
   update(2*ind+2,mid+1,high,index);
   seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
};


void solve()
{
int n;cin>>n;vector<int> v(n);cin>>v;
vector<int> freq(1e7+1);
for(int i=0;i<n;i++)
freq[v[i]]++;
int ans=0;
SegmentTree st(1e7+1);
st.build(0,0,1e7,freq);
for(int i=0;i<n;i++){
  st.update(0,0,1e7,v[i]);
  ans=ans+st.query(0,0,1e7,0,v[i]-1);
}
cout<<ans<<endl;
}
signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
int t;
cin>>t;
while(t--)
{
solve();
}
}