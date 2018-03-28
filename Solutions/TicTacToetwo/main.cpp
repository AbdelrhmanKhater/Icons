#include <bits/stdc++.h>

using namespace std;
struct Node
{
    string grid;
    int lvl;
    bool flag;
};
string grid;
Node cur, tmp;
queue<Node> g;
bool Check(Node node)
{
    bool col_c = (node.grid[0] != '.' && node.grid[0] == node.grid[3] && node.grid[3] == node.grid[6])
                || (node.grid[1] != '.' && node.grid[1] == node.grid[4] && node.grid[4] == node.grid[7])
                || (node.grid[2] != '.' && node.grid[2] == node.grid[5] && node.grid[5] == node.grid[8]);
    bool row_c = (node.grid[0] != '.' && node.grid[0] == node.grid[1] && node.grid[1] == node.grid[2])
                || (node.grid[3] != '.' && node.grid[3] == node.grid[4] && node.grid[4] == node.grid[5])
                || (node.grid[6] != '.' && node.grid[6] == node.grid[7] && node.grid[7] == node.grid[8]);
    bool dia_c = (node.grid[0] != '.' && node.grid[0] == node.grid[4] && node.grid[4] == node.grid[8])
                || (node.grid[2] != '.' && node.grid[2] == node.grid[4] && node.grid[4] == node.grid[6]);
    return col_c || row_c || dia_c || (node.lvl == 9);
}
bool Make_Sure(Node node)
{
    bool col_c = (node.grid[0] != '.' && node.grid[0] == node.grid[3] && node.grid[3] == node.grid[6])
                || (node.grid[1] != '.' && node.grid[1] == node.grid[4] && node.grid[4] == node.grid[7])
                || (node.grid[2] != '.' && node.grid[2] == node.grid[5] && node.grid[5] == node.grid[8]);
    bool row_c = (node.grid[0] != '.' && node.grid[0] == node.grid[1] && node.grid[1] == node.grid[2])
                || (node.grid[3] != '.' && node.grid[3] == node.grid[4] && node.grid[4] == node.grid[5])
                || (node.grid[6] != '.' && node.grid[6] == node.grid[7] && node.grid[7] == node.grid[8]);
    bool dia_c = (node.grid[0] != '.' && node.grid[0] == node.grid[4] && node.grid[4] == node.grid[8])
                || (node.grid[2] != '.' && node.grid[2] == node.grid[4] && node.grid[4] == node.grid[6]);
    return col_c || row_c || dia_c;
}
bool BFS()
{
    char r;
    cur.grid = ".........";
    cur.flag = true;
    cur.lvl = 0;
    g.push(cur);
    while (g.size())
    {
        cur = g.front();
        g.pop();
        if (cur.grid == grid)
            return Check(cur);
        if (Make_Sure(cur))
            continue;
        if (cur.flag)
            r = 'X';
        else
            r = 'O';
        for (int i = 0; i < 9; i++)
            if (cur.grid[i] == '.')
                if (r == grid[i])
                {
                    cur.grid[i] = r;
                    tmp.grid = cur.grid;
                    tmp.flag = !cur.flag;
                    tmp.lvl = cur.lvl + 1;
                    g.push(tmp);
                    cur.grid[i] = '.';
                }
    }
    return false;
}
int main()
{
    while (cin >> grid && grid != "end")
    {
        while (g.size())
            g.pop();
        if (BFS())
            cout << "valid\n";
        else
            cout << "invalid\n";
    }
    return 0;
}
