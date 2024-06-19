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
    int n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto counthours = [&](int mid)
    {
        int cnthours = 0;
        for (int i = 0; i < n; i++)
        {
            cnthours += ceil(1.0 * v[i] / mid);
        }
        return cnthours;
    };
    int low = 1, high = accumulate(all(v), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalhrs = counthours(mid);
        if (totalhrs <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
}