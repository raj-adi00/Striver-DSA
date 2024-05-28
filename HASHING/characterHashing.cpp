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
    string s;
    cin >> s;
    int hash[256] = {0};
    int hashh[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        int x = s[i];
        hash[x]++;
        hashh[s[i]-'a']++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char x;
        cin >> x;
        cout << hash[(int)x]<<" "<<hashh[x-'a'] << endl;
    }
}