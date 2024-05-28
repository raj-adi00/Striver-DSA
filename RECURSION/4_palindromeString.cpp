#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
bool checkpalindrome(string &s, int l, int n)
{
    if (l > n / 2)
        return true;
    else if (s[l] != s[n - l - 1])
        return false;
    return checkpalindrome(s, l + 1, n);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int l = 0;
    int r = s.size();
    cout << checkpalindrome(s, l, r);
}