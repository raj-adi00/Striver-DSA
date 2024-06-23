#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
            return true;
            else if(matrix[row][col]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return false;
    }
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
 int n,m,target;
 cin>>n>>m>>target;
 vector<vector<int>> v(n);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        int x;
        cin>>x;
        v[i].push_back(x);
    }
 }
 cout<<searchMatrix(v,target)<<endl;
}