#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - mid - 1;
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + k;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findKthPositive(v, k) << endl;
}