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

pair<long long, long long> SEGT[270000];
int t, n, x, y, val, f, r;
//int tree[100005];
void SEGT_update(int idx, int s, int e, int x, int y, int val)
{
    if (y < s || x > e) return;
    if (s >= x && e <= y)
    {
        SEGT[idx].first += (long long) val * (e - s + 1);
        SEGT[idx].second += val;
        return;
    }
    int mid = (s + e) / 2;
    SEGT_update(2 * idx, s, mid, x, y, val);
    SEGT_update(2 * idx + 1, mid + 1, e, x, y, val);
    SEGT[idx].first = SEGT[2 * idx].first + SEGT[2 * idx + 1].first + (e - s + 1) * SEGT[idx].second;
}
long long SEGT_solve(int idx, int s, int e, int x, int y)
{
    if (y < s|| x > e) return 0;
    if (s >= x && e <= y)
        return SEGT[idx].first;
    int mid = (s + e) / 2;
    return SEGT_solve(2 * idx, s, mid, x, y) + SEGT_solve(2 * idx + 1, mid + 1, e, x, y) + (min(y, e) - max(x, s) + 1) * SEGT[idx].second;
}
/*void BF_update(int s, int e, int val)
{
    for (int i = s; i <= e; i++)
        tree[i] += val;
}
int BF_solve(int s, int e)
{
    int sum = 0;
    for (int i = s; i <= e; i++)
        sum += tree[i];
    return sum;
}*/

int main()
{
    std::ios::sync_with_stdio(false);
    /*int res1, res2;
    f = 1;
    while (true)
    {
        memset(SEGT, 0, sizeof SEGT);
        memset(tree, 0, sizeof tree);
        n = rand() % 100 + 1;
        r = rand() % 100 + 1;
        cout << n << " " << r << "\n";
        while (r--)
        {
            if (f)
            {
                x = rand() % n + 1;
                y = rand() % n + 1;
                if (x > y) swap(x, y);
                val = rand() % 100 + 1;
                cout << x << " " << y << " " << val << "\n";
                SEGT_update(1, 1, n, x, y, val);
                BF_update(x, y, val);
                f = 0;
            }
            else
            {
                x = rand() % n + 1;
                y = rand() % n + 1;
                if (x > y) swap(x, y);
                cout << x << " " << y << "\n";
                res1 = SEGT_solve(1, 1, n, x, y);
                res2 = BF_solve(x, y);
                if (res1 == res2)
                    cout << "Ok\n";
                else
                {
                    cout << res1 << " " << res2 << "\n";
                    return 0;
                }
                f = 1;
            }
        }

    }*/
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        while (r--)
        {
            cin >> f;
            if (f)
            {
                cin >> x >> y;
                cout << SEGT_solve(1, 1, n, x, y) << "\n";
            }
            else
            {
                cin >> x >> y >> val;
                SEGT_update(1, 1, n, x, y, val);
            }
        }
        for (int i = 0; i <= 270000; i++)
        {
            SEGT[i].first = 0;
            SEGT[i].second = 0;
        }
    }
    return 0;
}
