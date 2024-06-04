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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // OPTIMAL
    int prefix = 0, cnt = 0;
    map<int, int> prefisum;
    prefisum[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        int remove = prefix - k;
        cnt += prefisum[remove];
        prefisum[prefix]++;
    }
    cout << cnt << endl;
}