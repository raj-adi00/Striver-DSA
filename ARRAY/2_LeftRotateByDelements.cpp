#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
void rev(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // OPTIMAL O(2*n)TC   O(1)SC
    d = d % n;
    // reverse(arr, arr + d);
    // reverse(arr + d, arr + n);
    // reverse(arr, arr + n);

    rev(arr, 0, d - 1);
    rev(arr, d, n - 1);
    rev(arr, 0, n - 1);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}