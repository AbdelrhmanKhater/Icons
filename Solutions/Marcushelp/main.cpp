#include <bits/stdc++.h>

using namespace std;
int vis[10][10];
char grid[10][10];
int m, n, t;
int dir[3][2] = { {0, -1}, {0, 1}, {-1, 0} };
pair <int, int> sc;
string s = "IEHOVA#";
void DFS(int x, int y, int pos)
{
    if (x < 0 || y < 0 || x == m || y == n)
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 3; i++)
        if (!vis[x + dir[i][0]][y + dir[i][1]] && pos < 7 && grid[x + dir[i][0]][y + dir[i][1]] == s[pos])
        {
            if (pos)
                putchar(' ');
            if (dir[i][1] == 1)
                cout << "right";
            else if (dir[i][1] == -1)
                cout << "left";
            else
                cout << "forth";
            DFS(x + dir[i][0], y + dir[i][1], pos + 1);
        }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        for (int i = 0; i < n; i++)
            if (grid[m - 1][i] == '@')
                sc = make_pair(m - 1, i);
        DFS(sc.first, sc.second, 0);
        cout << '\n';
    }
    return 0;
}
