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

    // KANDANE's ALGORITHM
/*
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << maxi << endl;
*/

    // FOR SUBARRAY INDEX: KANDANE's ALGORITHM
    int start = 0, end = 0;
    int check = 0;
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (maxi < sum)
        {
            maxi = sum;
            end = i;
            start = check;
        }
        if (sum < 0)
        {
            sum = 0;
            check = i + 1;
        }
    }
    cout << start << " " << end << endl;
}