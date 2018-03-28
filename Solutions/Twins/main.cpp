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


int n;
int coins[105];
int memo[105][10005];
int total;
int DP_Solve(int idx, int value)
{
    int ret = 0;
    if ((value > (total / 2)) || (value == total))
        return ret;
    if (idx == n)
        return 100000000;
    if (memo[idx][value] != -1)
        return memo[idx][value];
    ret = 1 + DP_Solve(idx + 1, value + coins[idx]);
    ret = min(ret, DP_Solve(idx + 1, value));
    return  memo[idx][value] = ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(memo, -1, sizeof memo);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    total = 0;
    for (int i = 0; i < n; i++)
        total += coins[i];
    cout << DP_Solve(0, 0) << "\n";
    return 0;
}
