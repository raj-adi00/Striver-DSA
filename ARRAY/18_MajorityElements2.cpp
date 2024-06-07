#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int el1 = INT_MIN, el2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != el2)
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != el1)
        {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
            cnt1++;
        else if (el2 == arr[i])
            cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    if(cnt1==0&&cnt2==0)
    cout<<"NO answer";
    else{
        vector<int> ans;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==el1)
            cnt1++;
            if(arr[i]==el2)
            cnt2++;
        }
        if(cnt1>n/3)
        ans.push_back(el1);
        if(cnt2>n/3)
        ans.push_back(el2);
        for(auto val:ans)
        cout<<val<<" ";
    }
}