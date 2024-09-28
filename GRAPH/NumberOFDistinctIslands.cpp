#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
    dp[i][j] = -1
#define clear1dDP(dp, n)        \
    for (int i = 0; i < n; i++) \
    dp[i] = -1
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
        out << x << ' ';
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
/*       <<<<<CODE HERE>>>>>      */
// TC: O(n*m*4+ n*m*log(n*m))
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    // vector<vector<int>> v;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> row = {0, 0, 1, -1}, col = {1, -1, 0, 0};
    vector<pair<int, int>> temp;
    function<void(int, int, int, int)> DFS = [&](int i, int j, int a, int b) -> void
    {
        vis[i][j] = 1;
        temp.push_back({i - a, j - b});
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k], ncol = j + col[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (!vis[nrow][ncol]) && v[nrow][ncol] == 1)
            {
                DFS(nrow, ncol, a, b);
            }
        }
    };
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1 && !vis[i][j])
            {
                temp.clear();
                DFS(i, j, i, j);
                s.insert(temp);
            }
        }
    }
    cout << s.size() << endl;
}