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
    map<int, int> m;
    // unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    
    // Display the map
    for(auto it:m)
    cout<<it.first<<"->"<<it.second<<endl;

    
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << m[x] << endl;
    }
}