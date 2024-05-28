#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int did_swap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                did_swap++;
            }
        }
        if (did_swap == 0)
            return;
    }
}
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
    for (auto val : arr)
        cout << val << " ";
    cout << endl;

    // Bubble Sort
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n - 1 - i; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             int t = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = t;
    //         }
    //     }
    // }

    bubbleSort(arr, n);

    // Display the sorted array
    for (auto val : arr)
        cout << val << " ";
    cout << endl;
}