#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
void sumation(int i, int sum)
{
    if (i == 0)
    {
        cout << sum << endl;
        return;
    }
    sumation(i - 1, i + sum);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    sumation(n, 0);
}