#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string.h>

using namespace std;
int n, q;
//int ans[100005];
int val;
//int SEGT[400005];
int sq, eq;
int BIT[100005];

void BIT_update(int idx, int val)
{
    for (int i = idx; i <= n; i += (i & -i))
        BIT[i] += val;
}
int BIT_solve(int idx)
{
    int ret = 0;
    for (int i = idx; i; i -= (i & -i))
        ret += BIT[i];
    return ret;
}
/*void cumulative_solve()
{
    for (int i = 1; i < n; i++)
        ans[i] += ans[i - 1];
}*/
/*void SEGT_update(int idx, int s, int e, int pos, int val)
{
    if (pos < s || pos > e)
        return;
    if (s == e)
    {
        SEGT[idx] = val;
        return ;
    }
    int mid = (s + e) / 2;
    update(idx * 2, s, mid, pos, val);
    update(idx * 2 + 1, mid + 1, e, pos, val);
    SEGT[idx] = SEGT[idx * 2] + SEGT[idx * 2 + 1];
}
int SEGT_solve(int idx, int s, int e, int x, int y)
{
    if (y < s || x > e) return 0;
    if (s >= x && e <= y) return SEGT[idx];
    int mid = (s + e) / 2;
    return solve(idx * 2, s, mid, x, y) + solve(idx * 2 + 1, mid + 1, e , x, y);
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    /*int res1, res2;
    while(true)
    {
        memset(BIT, 0, sizeof BIT);
        n = rand() % 100000 + 1;
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            ans[i] = rand() % 100000 + 1;
            cout << ans[i] << " ";
            //update(1, 0, n - 1, i, ans[i]);
            BIT_update(i + 1, ans[i]);
        }
        cumulative_solve();
        q = rand() % 10000 + 1;
        cout << "\n" << q << "\n";
        for (int i = 0; i < q; i++)
        {
            sq = rand() % n;
            eq = rand() % n;
            if (sq > eq) swap(sq, eq);
            cout << sq << " " << eq << "\n";
            //res1 = solve(1, 0, n - 1, sq, eq);
            res2 = ((sq == 0)? ans[eq] : ans[eq] - ans[sq - 1]);
            res1 = BIT_solve(eq + 1) - BIT_solve(sq);
            if (res1 == res2)
                cout << "Ok\n";
            else
            {
                cout << res1 << " " << res2 << "\n";
                return 0;
            }
        }
    }*/

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        //cin >> ans[i];
        //SEGT_update(1, 0, n - 1, i, val);
        BIT_update(i + 1, val);
    }
    //n = 100000;
    //for (int i = 0; i < n; BIT_update(i + 1, 1), i++);
    //cumulative_solve();
    cin >> q;
    //q = 10000;
    for (int i = 0; i < q; i++)
    {
        cin >> sq >> eq;
        //sq = 0, eq = n;
        /*if (sq)
        cout << ans[eq] - ans[sq - 1] << "\n";
        else cout << ans[eq] << "\n";*/
        //cout << SEGT_solve(1, 0, n - 1, sq, eq) << "\n";
        cout << BIT_solve(eq + 1) - BIT_solve(sq) << "\n";
    }
    return 0;
}
