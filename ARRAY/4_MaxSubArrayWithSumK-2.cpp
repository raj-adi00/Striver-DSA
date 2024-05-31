// This code has optimal solution for the case where all elements are negative or positive
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

    unordered_map<long long, int> m;
    long long sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
            len = max(len, i + 1);
        ll res = sum - k;
        if (m.find(res) != m.end())
        {
            len = max(len, i - m[res]);
        }
        if (m.find(sum) == m.end())
        {
            m[sum] = i;
        }
    }
    cout << len << endl;
}