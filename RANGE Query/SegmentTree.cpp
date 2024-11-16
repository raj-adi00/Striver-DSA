#include<bits/stdc++.h>
using namespace std;


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
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r){
    //NO overlap
    if(r<low || high<l)
    return INT_MAX;
    //complete overlap
    if(low>=l && high<=r)
    return seg[ind];
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}

void update(int ind,int low,int high,int index,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
   int mid=(low+high)/2;
   if(index<=mid)
   update(2*ind+1,low,mid,index,val);
   else
   update(2*ind+2,mid+1,high,index,val);
   seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
};


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    SegmentTree segtree(n);
   segtree.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<segtree.query(0,0,n-1,l,r)<<endl;
    }
}

void solve2(){
    int n1,n2;cin>>n1>>n2;
    vector<int> arr1(n1),arr2(n2);
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    SegmentTree sg1(n1),sg2(n2);
    sg1.build(0,0,n1-1,arr1);
    sg2.build(0,0,n2-1,arr2);
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(x==1){
            int l1,l2,r1,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1=sg1.query(0,0,n1-1,l1,r1);
            int min2=sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<endl;
        }else{
            int arrno,index,val;
            cin>>arrno>>index>>val;
            if(arrno==1)
            sg1.update(0,0,n1-1,index,val);
            else
            sg2.update(0,0,n2-1,index,val);
        }
    }
}
int main(){
    solve2();
}