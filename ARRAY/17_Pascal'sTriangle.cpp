#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
vector<int> generateRow(int row)
{
    vector<int> temp;
    temp.push_back(1);
    for (int i = 1; i < row; i++)
    {
        int val = temp.back() * (row - i) / i;
        temp.push_back(val);
    }
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<vector<int>> ans;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    for (auto arr : ans)
    {
        for (auto val : arr)
            cout << val << " ";
        cout << endl;
    }
}