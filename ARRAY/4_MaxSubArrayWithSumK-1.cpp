// This code has optimal solution for the case where all elements are 0 or positive
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // APPROACH 1
    // /*
    int sum = 0, len = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum < k)
            continue;
        else if (sum > k)
        {
            while (sum > k && j <= i)
            {
                sum -= v[j];
                j++;
            }
        }
        if (sum == k)
            len = max(len, i - j + 1);
    }
    cout << len << endl;
    // */


    // APPROACH 2:
    /*
    int left = 0, right = 0;
    int sum = v[0];
    int len = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= v[left];
            left++;
        }
        if (sum == k)
            len = max(len, right - left + 1);
        right++;
        if (right < n)
            sum += v[right];
    }
    cout << len << endl;
    */
}