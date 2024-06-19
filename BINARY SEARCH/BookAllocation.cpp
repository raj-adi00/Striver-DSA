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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n < m)
    {
        cout << -1;
        return 0;
    }
    ll low = *max_element(all(v));
    ll high = accumulate(all(v), 0 * 1LL);
    auto countst = [&](ll c)
    {
        int st = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (pages + v[i] > c)
            {
                pages = v[i];
                st++;
            }
            else
                pages += v[i];
        }
        return st;
    };
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll stu = countst(mid);
        if (stu > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << low << endl;
}