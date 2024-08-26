#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define clear2dDP(dp, n, m)     \
  for (int i = 0; i < n; i++)   \
    for (int j = 0; j < m; j++) \
  dp[i][j] = -1
#define clear1dDP(dp, n)      \
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
int main()      //sc:o(n*m)   Tc:O(n*m)
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m, sr, sc, color;
  cin >> n >> m >> sr >> sc >> color;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  int precolor = v[sr][sc];

  vector<vector<int>> vis(n, vector<int>(m, 0));
  function<void(int, int)> DFS = [&](int row, int col) -> void
  {
    vis[row][col] = 1;
    v[row][col] = color;
    for (int delrow = -1; delrow <= 1; delrow++)
    {
      for (int delcol = -1; delcol <= 1; delcol++)
      {
        if (abs(delcol + delrow) == 1)
        {
          int nrow = row + delrow;
          int ncol = col + delcol;
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
          {
            if (v[nrow][ncol] == precolor)
              DFS(nrow, ncol);
            else
              vis[nrow][ncol] = 1;
          }
        }
      }
    }
  };
  DFS(sr, sc);
}