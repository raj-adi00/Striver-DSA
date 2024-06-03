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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // OPTIMAL
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int longest = 1, count = 0;
    for (auto val : s)
    {
        if (s.find(val - 1) == s.end())
        {
            int x = val;
            count = 0;
            while (s.find(x) != s.end())
            {
                count++;
                x += 1;
            }
            longest = max(longest, count);
        }
    }
    cout << longest << endl;
}