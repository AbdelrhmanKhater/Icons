#include <bits/stdc++.h>

using namespace std;
char grid[30][30];
int vis[30][30];
int n;
int k = 0;
int dir[8][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1} };
void DFS(int x, int y)
{
    if (x == -1 || y == -1 || x == n || y == n || (grid[x][y] == '0'))
        return;
    vis[x][y] = 1;
    for (int z = 0; z < 8; z++)
        if (!vis[x + dir[z][0]][y + dir[z][1]])
            DFS(x + dir[z][0], y + dir[z][1]);
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && (grid[i][j] == '1'))
                {
                    cnt++;
                    DFS(i, j);
                }
        cout << "Image number " << ++k << " contains " << cnt <<  " war eagles.\n";
    }

    return 0;
}
