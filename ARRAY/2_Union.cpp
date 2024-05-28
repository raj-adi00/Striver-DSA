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
    vector<int> unionarr;

    // APPROACH 1:

    /*
     while (i < n1 && j < n2)
     {
         if (a[i] < b[j])
             unionarr.push_back(a[i]);
         else
             unionarr.push_back(b[j]);
         while (unionarr.back() == b[j] && j < n2)
             j++;
         while (unionarr.back() == a[i] && i < n1)
             i++;
     }
     while (j < n2)
     {
         if (unionarr.size() == 0 || unionarr.back() != b[j])
             unionarr.push_back(b[j]);
         j++;
     }
     while (i < n1)
     {
         if (unionarr.size() == 0 || unionarr.back() != a[i])
             unionarr.push_back(a[i]);
         i++;
     }
     */

    // APPROACH 2:

    /*
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionarr.size() == 0 || unionarr.back() != a[i])
                unionarr.push_back(a[i]);
            i++;
        }
        else
        {
            if (unionarr.size() == 0 || unionarr.back() != b[j])
                unionarr.push_back(b[j]);
            j++;
        }
    }
    while (j < n2)
    {
        if (unionarr.size() == 0 || unionarr.back() != b[j])
            unionarr.push_back(b[j]);
        j++;
    }
    while (i < n1)
    {
        if (unionarr.size() == 0 || unionarr.back() != a[i])
            unionarr.push_back(a[i]);
        i++;
    }
    */
    for (auto it : unionarr)
        cout << it << " ";
}