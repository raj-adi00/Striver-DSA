#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> res;
    function<void()> print = [&]() -> void
    {
        if (res.size() == 0)
            cout << "{}";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    };
    function<void(int)> f = [&](int i) -> void
    {
        if (i == n)
        {
            print();
            return;
        }
        res.push_back(v[i]);
        f(i + 1);
        res.pop_back();
        f(i + 1);
    };
    f(0);

    //TC: O(2^N)
    //SC: O(N)
}