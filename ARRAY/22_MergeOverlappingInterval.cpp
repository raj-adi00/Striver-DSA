#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
vector<vector<int>> mergeoverlap(vector<vector<int>> &v,int n)
{
     vector<vector<int>> ans;
     sort(v.begin(),v.end());
     for(int i=0;i<n;i++)
     {
        if(ans.empty() ||v[i][0]>ans.back()[1])
        {
           ans.push_back(v[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],v[i][1]);
        }
     }
     return ans;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    vector<vector<int>> ans=mergeoverlap(v,n);
    
    for(auto vec:ans)
    {
        for(auto val:vec)
        cout<<val<<" ";
        cout<<endl;
    }
}