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
struct bag
{
    int w, p;
};
int t, w, n;
int memo[205][505];
bag bags[205];
int Rec_Solve(int idx, int c)
{
    int ret = 0;
    if (idx == n)
        return ret;
    if (memo[idx][c] != -1)
        return memo[idx][c];
    if(c + bags[idx].w <= w)
        ret = bags[idx].p + Rec_Solve(idx + 1, c + bags[idx].w);
        ret = max(ret, Rec_Solve(idx + 1, c));
    return memo[idx][c] = ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(memo, -1, sizeof memo);
        cin >> w >> n;
        for (int i = 0; i < n; i++)
            cin >> bags[i].w >> bags[i].p;
        cout << Rec_Solve(0, 0) << "\n";
    }

    return 0;
}
