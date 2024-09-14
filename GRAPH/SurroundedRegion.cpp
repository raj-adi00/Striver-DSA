#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
void BFS(int i, int j, vector<vector<int>> &v, vector<vector<char>> &board, int n, int m)
{
    queue<pair<int, int>> q;
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};
    q.push({i, j});
    v[i][j] = 1; 
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nrow = r + row[k];
            int ncol = c + col[k];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && v[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
            {
                q.push({nrow, ncol});
                v[nrow][ncol] = 1;
            }
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    if (n == 0)
        return;
    int m = board[0].size();
    vector<vector<int>> v(n, vector<int>(m, 0)); // Visited matrix

    // Start BFS from the border 'O's
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O' && v[i][0] == 0)
            BFS(i, 0, v, board, n, m);
        if (board[i][m - 1] == 'O' && v[i][m - 1] == 0)
            BFS(i, m - 1, v, board, n, m);
    }
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O' && v[0][i] == 0)
            BFS(0, i, v, board, n, m);
        if (board[n - 1][i] == 'O' && v[n - 1][i] == 0)
            BFS(n - 1, i, v, board, n, m);
    }

    // Mark all 'O's that are not visited as 'X'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && v[i][j] == 0)
                board[i][j] = 'X';
        }
    }
}