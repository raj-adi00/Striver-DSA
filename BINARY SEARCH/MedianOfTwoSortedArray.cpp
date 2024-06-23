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
 vector<int> v1(n),v2(m);
 for(int i=0;i<n;i++)
 cin>>v1[i];
 for(int i=0;i<m;i++)
 cin>>v2[i];
int N=n+m;


// *&*& CODE ::::

 auto approach1=[&](){
     int cnt=0;
     int ele1=-1;
     int ele2=-1;
     int i=0,j=0;
     while(i<n&&j<m)
     {
        if(v1[i]<v2[j])
        {
            if(cnt==N/2-1)ele1=v1[i];
            if(cnt==N/2)ele2==v1[i];
            i++;
            cnt++;
        }
        else{
             if(cnt==N/2-1)ele1=v2[j];
             if(cnt==N/2)ele2=v2[j];
             j++;
             cnt++;
        }
     }
     while(i<n){
        if(cnt==N/2-1)ele1=v1[i];
         if(cnt==N/2)ele2==v1[i];
         i++;
        cnt++;
     }
     while(j<m)
     {
         if(cnt==N/2-1)ele1=v2[j];
             if(cnt==N/2)ele2=v2[j];
             j++;
             cnt++;
     }
     if(N%2==1)
     cout<<ele2<<endl;
     else
     cout<<(ele2+ele1)/2.0<<endl;
 };
 approach1();

 
}