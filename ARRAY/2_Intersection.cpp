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
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    for (int j = 0; j < n2; j++)
        cin >> b[j];
    int i = 0, j = 0;
    vector<int> intersection;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }
    for (auto it : intersection)
        cout << it << " ";
}