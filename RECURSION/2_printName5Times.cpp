#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
// TC: O(n)  SC:O(n)
void print(int n)
{
    if (n == 0)
        return;
    cout << "Aditya ";
    n--;
    print(n);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin>>n;
    print(n);
}