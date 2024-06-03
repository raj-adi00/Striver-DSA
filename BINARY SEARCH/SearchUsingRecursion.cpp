#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int BinarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    if (arr[(low + high) / 2] == target)
        return (low + high) / 2;
    if (arr[(low + high) / 2] > target)
        return BinarySearch(arr, low, (low + high) / 2 - 1, target);
    else
        return BinarySearch(arr, (low + high) / 2 + 1, high, target);
}
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
    cout << BinarySearch(arr, 0, n - 1, 7);
}