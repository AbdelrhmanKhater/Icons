#include <bits/stdc++.h>

using namespace std;
int t;
struct Node
{
    char grid[4][4];
    bool f;
};
Node cur, tmp;
queue<Node> g;
char grid[4][4];
bool Make_Sure(char grid_c[4][4])
{
    for (int i = 0; i < 3; i++)
        if ((grid_c[i][0] != '.' && grid_c[i][0] == grid_c[i][1] && grid_c[i][1] == grid_c[i][2]))
            return true;
    for (int i = 0; i < 3; i++)
        if ((grid_c[0][i] != '.' && grid_c[0][i] == grid_c[1][i] && grid_c[1][i] == grid_c[2][i]))
            return true;
    if ((grid_c[0][0] != '.' && grid_c[0][0] == grid_c[1][1] && grid_c[1][1] == grid_c[2][2]) || (grid_c[0][2] != '.' && grid_c[0][2] == grid_c[1][1] && grid_c[1][1] == grid_c[2][0]))
        return true;
    return false;
}
bool Check(char grid_c[4][4])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid_c[i][j] != grid[i][j])
                return false;
    return true;
}
bool BFS()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cur.grid[i][j] = '.';
    char p;
    cur.f = true;
    g.push(cur);
    while (g.size())
    {
        cur = g.front();
        g.pop();
        if (cur.f)
            p = 'X';
        else
            p = 'O';
        if (Check(cur.grid))
            return true;
        if (Make_Sure(cur.grid)) continue;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (cur.grid[i][j] == '.')
                {
                    if (grid[i][j] == p)
                    {
                        cur.grid[i][j] = p;
                        tmp = cur;
                        tmp.f = !cur.f;
                        g.push(tmp);
                        cur.grid[i][j] = '.';
                    }
                }
    }
    return false;
}
int main()
{
    cin >> t;
    while (t--)
    {
        for(int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> grid[i][j];
        if (BFS())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
