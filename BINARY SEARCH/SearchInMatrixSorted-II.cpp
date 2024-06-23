#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
 vector<int> searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=matrix[0].size()-1;
        while(col>=0&&row<matrix.size())
        {
            if(matrix[row][col]==target)
            return {row,col};
            else if(matrix[row][col]<target)
            row++;
            else
            col--;
        }
        return {-1,-1};
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
vector<int> res=searchMatrix(v,target);
for(auto val:res)
cout<<val<<" ";
}