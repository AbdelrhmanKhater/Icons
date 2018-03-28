#include <bits/stdc++.h>

using namespace std;
queue<pair<int, int> > g;
pair<int, int> cur, tmp, des;
int lvl[15][15];
string s, e;
int dir[8][2] = { {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
bool Check(pair<int, int> node)
{
    return node.first < 0 || node.second < 0 || node.first > 7 || node.second > 7;
}
int BFS()
{
    cur.first = s[0] - 'a';
    cur.second = s[1] - '1';
    des.first = e[0] - 'a';
    des.second = e[1] - '1';
    g.push(cur);
    int mov = 0, siz;
    while (g.size())
    {
        siz = g.size();
        while (siz--)
        {
            cur = g.front();
            g.pop();
            if (Check(cur) || lvl[cur.first][cur.second] != -1)
                continue;
            lvl[cur.first][cur.second] = mov;
            if (cur == des)
                return lvl[cur.first][cur.second];
            for (int i = 0; i < 8; i++)
            {
                tmp.first = cur.first + dir[i][0];
                tmp.second = cur.second + dir[i][1];
                g.push(tmp);
            }
        }
        mov++;
    }
}
int main()
{
    while (cin >> s >> e)
    {
        memset(lvl, -1, sizeof lvl);
        int sig = g.size();
        while (g.size())
            g.pop();
        cout << "To get from " << s << " to " << e << " takes " << BFS() << " knight moves.\n";
    }
    return 0;
}
