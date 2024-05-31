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

    // MOORE's VOTING ALGORITHM
    int count = 0, ele = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            ele = arr[i];
        if (ele == arr[i])
            count++;
        else
            count--;
    }
    if (count == 0)
    {
        cout << -2 << endl;
        cout << "predicteed majority element exist n/2 times" << endl;
        return 0;
    }
    // IF majority element exist then it is ele but we have to check it once again whether it exist. If it is sure that majority element exist then no need to proceed further ele is the answer
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            cnt++;
    }
    if (cnt > n / 2)
        cout << ele;
    else
        cout << -1;
}