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
    int n, days;
    cin >> n >> days;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto daysneed = [&](int c)
    {
        int cnt = 1;
        int taken = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] + taken > c)
            {
                cnt += 1;
                taken = v[i];
            }
            else
                taken += v[i];
        }
        return cnt;
    };
    int low = *max_element(all(v));
    int high = accumulate(all(v), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = daysneed(mid);
        if (cnt <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
}