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

int n, k, m;
int nums[100005];
int ans[100005];
int tmp[100005];
int Greedy_Solve()
{
    bool f = false;
    int res;
    for (int i = 0; i < n; i++)
        tmp[i] = nums[i] % m;
    for (int i = 0; i < n; i++)
        ans[tmp[i]]++;
    for (int i = 0; i < m; i++)
        if (ans[i] >= k)
            {
                f = true;
                res = i;
            }
    if (f)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
            {
                if (res == tmp[i])
                {
                    cout << nums[i] << " ";
                    k--;
                    if (!k)
                    {
                        cout << "\n";
                        break;
                    }
                }
            }
    }
    else
        cout << "No\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Greedy_Solve();
    return 0;
}
