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
    int n, threshold;
    cin >> n >> threshold;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int max_possible_answer = accumulate(all(v), 0);
    int min_possible_answer = n;
    if (threshold > max_possible_answer || threshold < n)
    {
        cout << -1 << endl;
        return 0;
    }
    auto sumofD = [&](int d)
    {
        int calc = 0;
        for (int i = 0; i < n; i++)
            calc += ceil(1.0 * v[i] / d);
        return calc;
    };
    int low = 1;
    int high = *max_element(all(v));
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (sumofD(mid) <= threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
}