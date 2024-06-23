#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
        return findMedianSortedArrays( nums2, nums1);
        int left=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=l1;
            int r1=INT_MAX;
            int r2=r1;
            if(mid1<n1)
            r1=nums1[mid1];
            if(mid2<n2)
            r2=nums2[mid2];
            if(mid1>=1)
            l1=nums1[mid1-1];
            if(mid2>=1)
            l2=nums2[mid2-1];
            if(l1<=r2&&l2<=r1)
            {
                if((n1+n2)%2==1)
                return max(l1,l2);
                else
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)
            high=mid1-1;
            else
            low=mid1+1;
        }
        return 0.0;
    }
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,m;
 cin>>n>>m;
 vector<int> v1(n),v2(m);
 for(int i=0;i<n;i++)
    cin>>v1[i];
 for(int i=0;i<m;i++)
    cin>>v2[i];
cout<<findMedianSortedArrays(v1,v2)<<endl;
}