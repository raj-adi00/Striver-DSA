#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */

int singleNonDuplicate(vector<int> &arr)
{
    // code here
    int n = arr.size();
    if (n == 1)
        return arr[0];
    else if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    else if (arr[0] != arr[1])
        return arr[0];
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];
        if ((mid % 2 == 0 && arr[mid] == arr[mid - 1]) || (mid % 2 == 1 && arr[mid] == arr[mid + 1]))
            high = mid - 1;
        else
            low = mid + 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << singleNonDuplicate(v);
}