#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0);
  int n,m;
 cin>>n>>m;
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


 
 function<void()> approach1=[&]()->int{
  function<int(int)> rownumber=[&](int col)->int{
    int prev=-1;
    int row=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i][col]>prev)
        {
          prev=v[i][col];
          row=i;
        }
    }
    return row;
  };
 int low=0,high=m-1;
 while(low<=high)
 {
    int mid=low+(high-low)/2;
    int maxrow=rownumber(mid);
    int left=(mid==0?-1:v[maxrow][mid-1]);
    int right=(mid==m-1?-1:v[maxrow][mid+1]);
    if(v[maxrow][mid]>left && v[maxrow][mid]>right)
    {cout<<maxrow<<" "<<mid;return 0;}
    else if(left>v[maxrow][mid])
    high=mid-1;
    else
    low=mid+1;
 }
 cout<<-1<<" "<<-1<<endl;
 };
//  approach1();




 function<void()> approach2=[&]()->int{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int maxcol=(max_element(all(v[mid]))-v[mid].begin());
        int up=(mid==0?-1:v[mid-1][maxcol]);
        int dow=(mid==n-1?-1:v[mid+1][maxcol]);
        if(v[mid][maxcol]>up&&v[mid][maxcol]>dow)
        {cout<<mid<<" "<<maxcol;return 0;}
        else if(v[mid][maxcol]<up)
        high=mid-1;
        else
        low=mid+1;
    }
    cout<<-1<<" "-1<<endl;
 };
 approach2();
}