#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
// approach 1    TC: O(N) SC:O(N)    one variable
// void revers(int arr[], int n, int i)
// {
//     if (i > n / 2)
//         return;
//     swap(arr[i], arr[n - i - 1]);
//     revers(arr, n, i + 1);
// }
// int main()
// {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     revers(arr, n, 0);
//     cout << endl;
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }



// approach 2    TC: O(N) SC:O(N)  two pointer variable
void recursion(int arr[],int l,int r)
{
    if(l>=r)
    return;
    swap(arr[l],arr[r]);
    recursion(arr,l+1,r-1);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        // cout<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        // cout<<1;
        cout << arr[i] << " ";
    }
    recursion(arr,0,n-1);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}