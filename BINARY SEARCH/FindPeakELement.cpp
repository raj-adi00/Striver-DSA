#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        if(nums[0]>nums[1])
        return 0;
        if(nums[n-1]>nums[n-2])
        return n-1;
        int low=1,high=n-2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            return mid;
            else if(nums[mid]>nums[mid+1])
            high=mid-1;
            else
            low=mid+1;
        }
        return -1;
    }
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << findPeakElement(v);
}