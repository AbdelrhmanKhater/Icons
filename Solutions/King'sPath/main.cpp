#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int x, y;
    int lvl;
};
Node cur, tmp;
map<pair<int, int>, int> lvl;
int dir[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
set<pair<int, int> > state;
queue<Node> g;
int x, y;
int sx, sy, ex, ey;
int n;
int r, a, b;
int BFS()
{
    cur.x = sx;
    cur.y = sy;
    cur.lvl = 0;
    g.push(cur);
    while (g.size())
    {
        cur = g.front();
        g.pop();
        if (state.count(make_pair(cur.x, cur.y)) == 0 || lvl.count(make_pair(cur.x, cur.y)) != 0)
            continue;
        lvl[make_pair(cur.x, cur.y)] = cur.lvl;
        if (cur.x == ex && cur.y == ey)
            return cur.lvl;
        for (int i = 0; i < 8; i++)
        {
            tmp.lvl = cur.lvl + 1;
            tmp.x = cur.x + dir[i][0];
            tmp.y = cur.y + dir[i][1];
            g.push(tmp);
        }
    }
    return -1;
}
int main()
{
    //ios::sync_with_stdio(false);
    cin >> sx >> sy >> ex >> ey >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++)
            state.insert(make_pair(r, j));
    }
    cout << BFS() << "\n";
    return 0;
}
