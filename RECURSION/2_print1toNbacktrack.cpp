#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
// TC: O(n)  SC:O(n)
void print(int i)
{
    if (i < 1)
        return;
    print(i - 1);     // i is not updated for this function instead new copy is created for new funtion
    cout << i << " "; // backtrack...first the base condition is evaluated then print is executed in the reverse fashion
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    print(n);
}