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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // OPTIMAL
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            x = i;
            break;
        }
    }
    if (x == -1)
        return 0;
    for (int i = x, j = x + 1; j < n; j++)
    {
        if (v[j] != 0)
        {
            swap(v[j], v[i]);
            i++;
        }
    }
    for (auto val : v)
        cout << val << " ";
}