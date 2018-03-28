#include <bits/stdc++.h>

using namespace std;
struct Piece
{
    Piece(int i,int j, char k)
    {
        x = i;
        y = j;
        pn = k;
    }
    int x, y;
    char pn;
};
struct Node
{
    char grid[9][9];
    int lvl;
    set<Piece> p;
    set< pair<int,int> > pts;
};
string mov = "QN";
int dir [9][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0} };
int dir1 [8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2} };
int fx, fy, sx, sy;
int x, y;
char grd[9][9];
Node cur, tmp;
queue<Node> g;
set< pair<int,int> > chkpts, thnpts;
set< pair<int,int> >Merge(set< pair<int,int> >pts, set< pair<int,int> > pts1)
{
    set<pair<int,int> >::iterator it;
    for (it = pts.begin(); it != pts.end(); it++)
        pts1.insert(*it);
    return pts1;
}
void Done(Node node)
{
    cout << node.p.size() << "\n";
    set<Piece>::iterator it;
    for (it = node.p.begin(); it != node.p.end(); it++)
        cout << (*it).pn << " " << (*it).x << " " << (*it).y << "\n";
}
set< pair<int,int> > Generate_Pts(int i,int j,int k)
{
    set< pair<int,int> > pts;
    if (k == 0)
    {
        for (int z = 0; z < 8; z++)
            if (z != i)
                pts.insert(make_pair(z, j));
        for (int z = 0; z < 8; z++)
            if (z != j)
                pts.insert(make_pair(i, z));
        int z = i + 1, l = j + 1;
        while (z < 8 && l < 8)
        {
            pts.insert(make_pair(z, l));
            z++;
            l++;
        }
        z = i - 1, l = j - 1;
        while (z < 8 && l < 8)
        {
            pts.insert(make_pair(z, l));
            z--;
            l--;
        }
    }
    else
        for (int z = 0; z < 8; z++)
            pts.insert(make_pair(i + dir1[z][0], j + dir1[z][1]));
    return pts;
}
bool Check(set< pair<int,int> > pts)
{
    set< pair<int,int> >::iterator it;
    for (it = pts.begin(); it != pts.end(); it++)
        if (thnpts.count(*it) != 0)
            return true;
    return false;
}
bool Threaten(set<Piece> p1, set< pair<int,int> > p2)
{
    set< Piece>::iterator it;
    for (it = p1.begin(); it != p1.end(); it++)
        if (thnpts.count(make_pair((*it).x, (*it).y)) != 0 && p2.count(make_pair((*it).x, (*it).y)) == 0)
            return true;
    return false;
}
bool Check_Mate(set< pair<int,int> > pts)
{
    set< pair<int,int> >::iterator it;
    int cnt = 0;
    for (it = thnpts.begin(); it != thnpts.end(); it++)
        if (pts.count(*it) != 0)
            cnt++;
    return cnt == thnpts.size();
}
void BFS()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cur.grid[i][j] = '.';
    cur.grid[fx][fy] = 'K';
    cur.grid[sx][sy] = 'K';
    cur.lvl = 0;
    g.push(cur);
    while (g.size())
    {
        cur = g.front();
        g.pop();
        if (!Threaten(cur.p, cur.pts) && Check_Mate(cur.pts))
        {
            Done(cur);
            return;
        }
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (cur.grid[i][j] != '.')
                {
                    for (int k = 0; k < 2; k++)
                    {
                    chkpts = Generate_Pts(i, j, k);
                    if (Check(chkpts))
                    {
                        tmp = cur;
                        tmp.grid[i][j] = mov[k];
                        tmp.lvl = cur.lvl + 1;
                        tmp.pts = Merge(chkpts, tmp.pts);
                        tmp.p.insert(Piece(i, j, mov[k]));
                        g.push(tmp);
                    }
                    }
                }
    }
}
int main()
{
    cin >> fx >> fy >> sx >> sy;
    for (int i = 0; i < 8; i++)
    {
        x = fx + dir[i][0];
        y = fy + dir[i][1];
        if (x > -1 && x < 8 && y > -1 && y < 8)
            thnpts.insert(make_pair(x, y));
    }
    for (int i = 0; i < 8; i++)
    {
        x = sx + dir[i][0];
        y = sy + dir[i][1];
        if (x > -1 && x < 8 && y > -1 && y < 8)
            thnpts.insert(make_pair(x, y));
    }
    BFS();
    return 0;
}
