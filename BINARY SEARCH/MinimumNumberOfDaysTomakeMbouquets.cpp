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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> bloomDay(n);
    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];
    if (m * k > n)
    {
        cout << -1 << endl;
        return 0;
    }
    auto possible = [&](ll day)
    {
        int count = 0;
        int check = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
                count++;
            else
            {
                check += count / k;
                count = 0;
            }
        }
        check += count / k;
        if (check >= m)
            return true;
        else
            return false;
    };
    ll low = *min_element(all(bloomDay));
    ll high = *max_element(all(bloomDay));
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (possible(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
}