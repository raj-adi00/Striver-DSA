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
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }



    // TYPE 1
    /*
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            cout << "YES" << endl;
            return 0;
        }
        else if (arr[left] + arr[right] < target)
            left++;
        else
            right--;
    }
    cout << "NO" << endl;
   */


    // TYPE 2
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = target - a;
        if (m.find(more) != m.end())
        {
            cout << i << " " << (m.find(more)->second) << endl;
            return 0;
        }
        m[a] = i;
    }
}