#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */

int Merge(vector<int> &v, int n, int low, int mid, int high) // TC of this function O(2*N)
{
    int coun = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }
    left = low;
    right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (v[left] > 2 * v[right])
        {
            coun += mid - left + 1;
            right++;
        }
        else
        {
            left++;
        }
    }
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];
    return coun;
}
void MergeSort(vector<int> &v, int n, int low, int high, int &coun) // TC of this function: O(log N)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(v, n, low, mid, coun);
    MergeSort(v, n, mid + 1, high, coun);
    coun += Merge(v, n, low, mid, high);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    MergeSort(arr, n, 0, n - 1, ans);
    cout << ans << endl;
}