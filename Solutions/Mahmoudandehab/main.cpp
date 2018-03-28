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
#include <stdio.h>

using namespace std;

int flag[105];
int tmp, n , x;
int GR_solve()
{
    int ret = 0;
    if (flag[x]) ret++;
    for (int i = 0; i < x; i++)
        if (!flag[i]) ret++;
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        flag[tmp] =1;
    }
    cout << GR_solve();
    return 0;
}
