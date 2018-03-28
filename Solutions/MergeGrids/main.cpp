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
char grid1[3][3];
char grid2[3][3];
char ans[3][3];
void Greedy_Solve()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            {
                if (grid1[i][j] == grid2[i][j])
                    ans[i][j] = grid1[i][j];
                else if (grid1[i][j] == '.')
                    ans[i][j] = grid2[i][j];
                else if (grid1[i][j] == '\\')
                    if(grid2[i][j] == '.')
                        ans[i][j] = '\\';
                    else
                        ans[i][j] = 'X';
                else if(grid1[i][j] == '/')
                    if (grid2[i][j] == '.')
                        ans[i][j] = '/';
                    else
                        ans[i][j] = 'X';
            }
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
                cout << ans[i][j];
            cout << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid1[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid2[i][j];
    Greedy_Solve();
    return 0;
}
