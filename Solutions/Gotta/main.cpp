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
int r, c;
int grid[205][205];
int memo[205][205];
int Rec_Solve(int x, int y)
{
    int ret = 0;
    int ans = 0;
    if(memo[x][y] != -400000000)
        return memo[x][y];

    if (x == r-1 && y == c-1)
        return  ret;
    if (x + 1 < c)
        ret = Rec_Solve(x + 1, y);
    if (y + 1 < r)
        ret = min(ret, Rec_Solve(x, y + 1));
        if (grid[x][y] < 0)
            ans = 1 - grid[x][y];
        else
        {
          if (ret > grid[x][y])
              ret -= grid[x][y];
          else
              ret = 0;
        }

    return memo[x][y] = ans + ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> r >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            memo[i][j]=-400000000;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    int y = Rec_Solve(0, 0);
    if( y == 0)
        cout << "1\n";
    else
        cout << y << "\n";
    return 0;
}
