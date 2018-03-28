#include <bits/stdc++.h>

using namespace std;
struct Node
{
    char grid[5][5];
};
char grid[5][5];
int siz = 0, lev = 0;
Node cur, tmp;
queue<Node> g;
bool Make_Sure(int x, int y)
{
        bool cond1, cond2, cond3, cond4;
        cond1 = grid[x][y] == grid[x][y + 1] && grid[x][y] == grid[x + 1][y];
        cond2 = grid[x + 1][y + 1] == grid[x][y + 1] && grid[x + 1][y + 1] == grid[x + 1][y];
        cond3 = grid[x][y] == grid[x + 1][y + 1] && grid[x][y] == grid[x + 1][y];
        cond4 = grid[x][y] == grid[x + 1][y + 1] && grid[x][y] == grid[x][y + 1];
        return cond1 || cond2 || cond3 || cond4;
}
bool Check(Node node)
{
    bool cond;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            cond = node.grid[i][j] == node.grid[i + 1][j] && node.grid[i][j] == node.grid[i][j + 1] && node.grid[i][j] == node.grid[i + 1][j + 1];
            if (cond)
                return true;
        }
    return false;
}
bool BFS()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cur.grid[i][j] = grid[i][j];
    g.push(cur);
    while (g.size())
    {
        siz = g.size();
        while (siz--)
        {
            cur = g.front();
            g.pop();
            if (lev == 2)
                return false;
            if (Check(cur))
                return true;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                {
                    tmp = cur;
                    if (cur.grid[i][j] == '#')
                        tmp.grid[i][j] = '.';
                    else
                        tmp.grid[i][j] = '#';
                    g.push(tmp);
                }
        }
        lev++;
    }
}
int main()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> grid[i][j];
    /*if (BFS())
        cout << "YES\n";
    else
        cout << "NO\n";*/
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (Make_Sure(i, j))
            {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}
