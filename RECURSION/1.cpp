#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
// int count = 0;
void recursion(int n, int count)
{
    if (n == count)
        return;
    cout << count << " ";
    count++;
    recursion(n, count);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    recursion(n, 0);
}