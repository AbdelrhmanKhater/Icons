#include <bits/stdc++.h>

using namespace std;
int t, n;
char grid[105][105];
int vis[105][105];
int cnt = 0;
int z = 1;
int dir[8][2] = { {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {-1, 0}, {1, 0} };
bool Is_Right(int x, int y)
{
    if (x > -1 && y > -1 && x < n && y < n && grid[x][y] != '.' && !vis[x][y])
        return true;
    return false;
}
void DFS(int x, int y)
{
    if (x < 0 || y < 0 || x == n || y == n)
        return;
    vis[x][y] = 1;
    for (int z = 0; z < 8; z++)
        if (Is_Right(x + dir[z][0], y + dir[z][1]))
            DFS(x + dir[z][0], y + dir[z][1]);
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && grid[i][j] == 'x')
                {
                    DFS(i, j);
                    cnt++;
                }
        cout << "Case " << z++ << ": " << cnt << "\n";
    }
    return 0;
}
