#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int partition(vector<int> &v, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = low;
    while (i < j)
    {
        while (v[i] >= v[pivot] && i < high)
            i++;
        while (v[pivot] > v[j] && j > low)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}
void Quick_sort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pos = partition(v, low, high);
        Quick_sort(v, low, pos - 1);
        Quick_sort(v, pos + 1, high);
        // cout<<1<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Quick_sort(v, 0, n - 1);
    for (auto it : v)
        cout << it << " ";
}