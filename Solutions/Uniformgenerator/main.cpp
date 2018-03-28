#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int dp[100005],step, m, n;
bool flag;

/*void REC_solve(int n, int step, int mod)
{
    if (memo[n])
        return;
    memo[n] = 1;
    REC_solve((n + step) % m, step, mod);
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    while (cin >> step >> m)
    {
        flag = true;
        n = 0;
        memset(dp, 0, sizeof dp);
        while (!(dp[(step + n) % m]))
    {
        dp[(step + n) % m] = 1;
        n = (step + n) % m;
    }
    for (int i = 0; i < m; i++)
        if(!dp[i])
        {
            flag = false;
        }

        cout.width(10);
        cout << step;
        cout.width(10);
        cout << m;
        cout.width(0);
    if (flag) cout << "    Good Choice\n\n";
    else cout << "    Bad Choice\n\n";
    }
    return 0;
}
