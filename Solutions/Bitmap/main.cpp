#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;
struct node
{
    int x, y, dis;
};
int t;
queue<node> Q;
int n, m;
string grid[187];
int ans[187][187];
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
node cur, tmp;
void BFS_Solve()
{
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            tmp.x = cur.x + dirX[i];
            tmp.y = cur.y + dirY[i];
            tmp.dis = cur.dis + 1;
            if (tmp.x == n || tmp.y == m || tmp.x < 0 || tmp.y < 0)
                continue;
            if (ans[tmp.x][tmp.y] != -1) continue;
            ans[tmp.x][tmp.y] = tmp.dis;
            Q.push(tmp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(ans, -1, sizeof ans);
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            {
                cin >> grid[i];
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        cur.x = i;
                        cur.y = j;
                        cur.dis = 0;
                        ans[cur.x][cur.y] = 0;
                        Q.push(cur);
                    }
                }
            }
        BFS_Solve();
    }
    return 0;
}
