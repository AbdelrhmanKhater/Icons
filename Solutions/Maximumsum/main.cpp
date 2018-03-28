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

pair<int, int> SEGT[400005];
//int nums[100005];
int n, s, e;
char o;
int m;
pair<int, int> ans;

void SEGT_update(int idx, int s, int e, int pos, int val)
{
    if (pos < s || pos > e) return;
    if (s == e) { SEGT[idx].first = val; return;}
    int mid = (s + e) / 2;
    SEGT_update(idx * 2, s, mid, pos, val);
    SEGT_update(idx * 2 + 1, mid + 1, e, pos, val);
    int nums[4] = {SEGT[2 * idx].first, SEGT[2 * idx].second,SEGT[2 * idx + 1].first, SEGT[2 * idx + 1].second};
    sort(nums, nums + 4);
    SEGT[idx].first = nums[2];
    SEGT[idx].second = nums[3];
}
pair<int, int> SEGT_solve(int idx, int s, int e, int x, int y)
{
    if (y < s || x > e) return make_pair(0, 0);
    if (s >= x && e <= y) return SEGT[idx];
    int mid = (s + e) / 2;
    pair<int, int> lft = SEGT_solve(2 * idx, s, mid, x, y);
    pair<int, int> rht = SEGT_solve(2 * idx + 1, mid + 1, e, x, y);
    int nums[4] = {lft.first, lft.second, rht.first, rht.second};
    sort(nums, nums + 4);
    return make_pair(nums[2], nums[3]);
}
/*int BF_solve(int s, int e)
{
    int mx1 = nums[s], mx2 = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (nums[i] > mx1)
        {
            mx2 = mx1;
            mx1 = nums[i];
        }
        else if (nums[i] > mx2)
                mx2 = nums[i];
    }
    return mx1 + mx2;
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    /*int res1, res2;
    while (true)
    {
        memset(nums, 0, sizeof nums);
        for (int i = 0; i < 400005; i++)
        {
            SEGT[i].first = 0;
            SEGT[i].second = 0;
        }
        n = rand() % 1000 + 1;
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            s = rand() % 5;
            cout << s << "\n";
            nums[i + 1] = s;
            SEGT_update(1, 1, n, i + 1, nums[i + 1]);
        }
        short t = 9;
        bool flag = true;
        while (t--)
        {
            if (flag)
            {
                o = 'U';
                flag = false;
            }
            else
            {
                o = 'Q';
                flag = true;
            }
            cout << o << "\n";
            if (o == 'U')
            {
                s = rand() % n + 1;
                e = rand() % 5;
                cout << s << " " << e << "\n";
                SEGT_update(1, 1, n, s, e);
                nums[s] = e;
            }
            else
            {
                s = rand() % n + 1;
                e = rand() % n + 1;
                cout << s << " " << e << "\n";
                if (s > e) swap(s, e);
                ans = SEGT_solve(1, 1, n, s, e);
                res1 = ans.first + ans.second;
                res2 = BF_solve(s, e);
                if (res1 == res2)
                    cout << "Ok\n";
                else
                {
                    cout << res1 << " " << res2 << "\n";
                    return 0;
                }
            }
        }
    }*/
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        SEGT_update(1, 1, n, i + 1, s);
    }
    cin >> m;
    while (m--)
    {
        cin >> o;
        if (o == 'U')
        {
            cin >> s >> e;
            SEGT_update(1, 1, n, s, e);
        }
        else
        {
            cin >> s >> e;
            ans = SEGT_solve(1, 1, n, s, e);
            cout << ans.first + ans.second << "\n";
        }
    }


    return 0;
}
