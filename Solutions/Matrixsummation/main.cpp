#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

//int BIT2d[1025][1025], tree[1025][1025];
int n, t, x1, y1, x2, y2, val;
char s[4];
int SEGT2d[4105][4105];
/*void BIT2d_update(int x, int y, int val)
{
    for (int i = x; i <= n; i += (i & -i))
        for (int j = y; j <= n; j += (j & -j))
            BIT2d[i][j] += val - tree[x][y];
    tree[x][y] = val;
}
int BIT2d_solve(int x, int y)
{
    int ret = 0;
    for (int i = x; i; i -= (i & -i))
        for (int j = y; j; j -= (j & -j))
            ret += BIT2d[i][j];
    return ret;
}*/
void SEGT2d_buildy(int vx, int sx, int ex, int vy, int sy, int ey)
{
    if (sy == ey)
        if (sx == ex)
            SEGT2d[vx][vy] = 0;
        else
            SEGT2d[vx][vy] = SEGT2d[vx * 2][vy] + SEGT2d[vx * 2 + 1][vy];
    else
    {
        int mid = (sy + ey) / 2;
        SEGT2d_buildy(vx, sx, ex, 2 * vy, sy, mid);
        SEGT2d_buildy(vx, sx, ex, 2 * vy + 1, mid + 1, ey);
        SEGT2d[vx][vy] = SEGT2d[vx][2 * vy] + SEGT2d[vx][2 * vy + 1];
    }
}
void SEGT2d_buildx(int vx,int sx, int ex)
{
    if(sx != ex)
    {
        int mid = (sx + ex) / 2;
        SEGT2d_buildx(2 * vx, sx, mid);
        SEGT2d_buildx(2 * vx + 1, mid + 1, ex);
    }
    SEGT2d_buildy(vx, sx, ex, 1, 0, n - 1);
}
void SEGT2d_updatey(int vx, int vy, int sx, int ex, int sy, int ey, int x, int y, int val)
{
    if (sy == ey)
        if (sx == ex)
            SEGT2d[vx][vy] = val;
        else
            SEGT2d[vx][vy] = SEGT2d[2 * vx][vy] + SEGT2d[2 * vx + 1][vy];
    else
    {
        int mid = (sy + ey) / 2;
        if (y <= mid)
        SEGT2d_updatey(vx, 2 * vy, sx, ex, sy, mid, x, y, val);
        else
        SEGT2d_updatey(vx, 2 * vy + 1, sx, ex, mid + 1, ey, x, y, val);
        SEGT2d[vx][vy] = SEGT2d[vx][2 * vy] + SEGT2d[vx][2 * vy + 1];
    }
}
void SEGT2d_updatex(int vx, int sx, int ex, int x, int y, int val)
{
    if (sx != ex)
    {
        int mid = (sx + ex) / 2;
        if (x <= mid)
        SEGT2d_updatex(2 * vx, sx, mid, x, y, val);
        else
        SEGT2d_updatex(2 * vx + 1, mid + 1, ex, x, y, val);
    }
    SEGT2d_updatey(vx, 1, sx, ex, 0, n - 1, x, y, val);
}
int SEGT2d_solvey(int vx, int vy, int sy, int ey, int y1, int y2)
{
    if (y1 > ey || y2 < sy) return 0;
    if (sy >= y1&& ey <= y2)
        return SEGT2d[vx][vy];
    int mid = (sy + ey) / 2;
    return SEGT2d_solvey(vx, 2 * vy, sy, mid, y1, y2) + SEGT2d_solvey(vx, 2 * vy + 1, mid + 1,ey, y1, y2);
}
int SEGT2d_solvex(int vx, int sx, int ex, int x1, int x2, int y1, int y2)
{
    if (x1 > ex || x2 < sx) return 0;
    if (sx >= x1 && ex <= x2)
        return SEGT2d_solvey(vx, 1, 0, n - 1, y1, y2);
    int mid = (sx + ex) / 2;
    return SEGT2d_solvex(2 * vx, sx, mid, x1, x2, y1, y2) + SEGT2d_solvex(2 * vx + 1, mid + 1, ex, x1, x2, y1, y2);
}
int main()
{
   /* int res1 , res2;
    bool f = true;
    while (true)
    {
        n = rand() % 1024 + 1;
        printf("%d\n", n);
        int t = 6;
        while (t--)
        {
           if (f)
           {
            x1 = rand() % n;
            y1 = rand() % n;
            val = rand() % 100;
            cout << x1 << " " << y1 << " " << val << "\n";
            SEGT2d_updatex(1, 0, n - 1, x1, y1, val);
            BIT2d_update(x1 + 1, y1 + 1, val);
            f = false;
           }
           else
           {
               x1 = rand() % n;
               y1 = rand() % n;
               x2 = rand() % n;
               y2 = rand() % n;
               if (x1 > x2) swap (x1, x2);
               if (y1 > y2) swap (y1, y2);
               cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
               res1 = SEGT2d_solvex(1, 0, n - 1, x1, x2, y1, y2);
               res2 = BIT2d_solve(x2 + 1, y2 + 1) + BIT2d_solve(x1, y1) - BIT2d_solve(x2 + 1, y1) - BIT2d_solve(x1, y2 + 1);
               if (res1 == res2)
                cout << "Ok\n";
               else
               {
                   cout << res1 << " " << res2 << "\n";
                   return 0;
               }
               f = true;
           }

        }
        SEGT2d_buildx(1, 0, n - 1);
        memset(tree, 0, sizeof tree);
        memset(BIT2d, 0, sizeof BIT2d);
    }*/
    scanf("%d", &t);
    while(t--)
    {
       // memset(BIT2d, 0, sizeof BIT2d);
        //memset(tree, 0, sizeof tree);
        scanf("%d", &n);
        scanf("%s", &s);
        while(s[0] != 'E')
        {
            if (s[1] == 'E')
            {
                scanf("%d %d %d", &x1, &y1, &val);
                //BIT2d_update(x1 + 1, y1 + 1, val);
                SEGT2d_updatex(1, 0, n - 1, x1, y1, val);
            }
            else
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                //printf("%d\n", solve(x2 + 1, y2 + 1) - solve(x1, y2 + 1) - solve (x2 + 1, y1) + solve(x1, y1));
                printf("%d\n", SEGT2d_solvex(1, 0, n - 1, x1, x2, y1, y2));
            }
            scanf("%s", &s);
        }
        SEGT2d_buildx(1, 0, n - 1);
        printf("\n");
    }
    return 0;
}
