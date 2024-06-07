#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
             if(i>0&&nums[i]==nums[i-1])continue;
             for(int j=i+1;j<n;j++)
             {
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum>target)
                    l--;
                    else if(sum<target)
                    k++;
                    else{
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l&&nums[k]==nums[k-1]) k++;
                        while(k<l&&nums[l]==nums[l+1])l--;
                    }
                }
             }
        }
        return ans;
    }
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,target;
 cin>>n>>target;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];

 vector<vector<int>> ans=fourSum(v,target);
 for(auto vec:ans)
 {
    for(auto val:vec)
    cout<<val<<" ";
cout<<endl;
 }
}