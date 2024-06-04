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
    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            mat[i].push_back(x);
        }
    }

    //  TRANSPOSE
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);
    }

    // Reverse
    for (int i = 0; i < n; i++)
    {
        reverse(all(mat[i]));
    }
    
    for (auto val : mat)
    {
        for (auto y : val)
            cout << y << " ";
        cout << endl;
    }
}