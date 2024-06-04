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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            mat[i].push_back(x);
        }
    }

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }

    for (auto val : ans)
        cout << val << " ";
}