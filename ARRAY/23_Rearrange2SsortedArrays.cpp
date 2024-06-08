#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
void approach1(vector<int> &v1,vector<int> &v2,int n,int m)
{
    int left=n-1;
    int right=0;
    while(left>=0&&right<m)
    {
        if(v1[left]>v2[right])
        {
        swap(v1[left],v2[right]);
         left--;
         right++;
        }
        else
        break;

    }
     sort(all(v1));sort(all(v2));
}



void swapifgreater(vector<int> &v1,vector<int> &v2,int ind1,int ind2)
{
    if(v1[ind1]>v2[ind2])
    swap(v1[ind1],v2[ind2]);
}

void approach2(vector<int> &v1,vector<int>&v2,int n,int m)
{
    int len=m+n;
    int gap=len/2+len%2;
    while(gap>0)
    {
        int left=0;
        int right=gap;
        while(right<len)
        {
            if(left<n&&right>=n)
            swapifgreater(v1,v2,left,right-n);
            else if(left>=n)
             swapifgreater(v2,v2,left-n,right-n);
             else
             swapifgreater(v1,v1,left,right);
             right++;
             left++;
        }
         if(gap==1)break;
         gap=gap/2+gap%2;
    }
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
    
        

        // approach1(v1,v2,n,m);

        approach2(v1,v2,n,m);

      for(auto val:v1)
      cout<<val<<" ";
      cout<<endl;
      for(auto val:v2)
      cout<<val<<" ";
    
}