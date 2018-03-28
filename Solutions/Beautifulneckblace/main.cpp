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
string necks[55];
int ans[55];
void Greedy_Solve()
{
    for (int i = 0; i < n; i++)
    {
        char bead = necks[i][0];
        bool f = true;
        int cnt = 1;
        for (int j = 1; j < necks[i].size(); j++)
        {
            if (necks[i][j] != necks[i][j - 1])
            {
                f = false;
                break;
            }
            cnt++;
        }
        if (f)
            ans[i] = cnt;
    }
    int res = ans[0];
    for (int i = 1; i < n; i++)
        if (ans[i] > res)
            res = ans[i];
    if (res == -1)
        cout << "0\n";
    else
        cout << res << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(ans, -1, sizeof ans);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> necks[i];
    Greedy_Solve();
    return 0;
}
